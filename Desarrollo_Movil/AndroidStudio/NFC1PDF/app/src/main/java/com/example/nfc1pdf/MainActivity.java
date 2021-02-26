package com.example.nfc1pdf;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.nfc.FormatException;
import android.nfc.NdefMessage;
import android.nfc.NdefRecord;
import android.nfc.NfcAdapter;
import android.nfc.NfcManager;
import android.nfc.Tag;
import android.nfc.tech.Ndef;
import android.nfc.tech.NdefFormatable;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.sql.Array;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private static final int DIALOG_WRITE_URL = 1;
    private static final int PENDING_INTENT_TECH_DISCOVERED = 1;
    private static final int DIALOG_NEW_TAG = 3;
    private static final String ARG_MESSAGE = "message";
    private NfcAdapter mNfcAdapter;
    private EditText mMyUrl;
    private Button mMyWriteButton;
    private boolean mWriteUrl = false;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mMyUrl = (EditText) findViewById(R.id.myUrl);
        mMyWriteButton = (Button) findViewById(R.id.myWriteUrlButton);

        mMyWriteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mWriteUrl = true;
                MainActivity.this.showDialog(DIALOG_WRITE_URL);
            }
        });
        resolveIntent(this.getIntent(), false);
    }

    @Override
    public void onNewIntent(Intent data){
        resolveIntent(data,false);
    }

    @Override
    protected Dialog onCreateDialog(int id, Bundle args){
        switch(id){
            case DIALOG_WRITE_URL:
                return new AlertDialog.Builder(this)
                        .setTitle("Write URL to tag...")
                        .setMessage("Touch tag to start writing")
                        .setCancelable(true)
                        .setNeutralButton(android.R.string.cancel,
                                new DialogInterface.OnClickListener(){
                            public void onClick(DialogInterface dia, int arg){
                                dia.cancel();
                            }
                        })
                        .setOnCancelListener(new DialogInterface.OnCancelListener() {
                            @Override
                            public void onCancel(DialogInterface dialog) {
                                mWriteUrl = false;
                            }
                        })
                        .create();

            case DIALOG_NEW_TAG:
                return new AlertDialog.Builder(this)
                        .setTitle("Tag Detected")
                        .setCancelable(true)
                        .setNeutralButton(android.R.string.ok,
                                new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        dialog.dismiss();
                                    }
                                }).create();
        }
        return null;
    }

    @Override
    public void onResume(){
        super.onResume();

        NfcManager nfcManager = (NfcManager) this.getSystemService(Context.NFC_SERVICE);
        mNfcAdapter = nfcManager.getDefaultAdapter();

        PendingIntent pi = createPendingResult(PENDING_INTENT_TECH_DISCOVERED, new Intent(), 0);

        mNfcAdapter.enableForegroundDispatch(
                this,
                pi,
                new IntentFilter[]{new IntentFilter(NfcAdapter.ACTION_TECH_DISCOVERED)},
                new String[][]{
                        new String[]{"android.nfc.tech.NdefFormatable"},
                        new String[]{"android.nfc.tech.Ndef"}
                });
    }

    @Override
    public void onPause() {
        super.onPause();

        mNfcAdapter.disableForegroundDispatch(this);

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        switch (requestCode){
            case PENDING_INTENT_TECH_DISCOVERED:
                resolveIntent(data,true);
                break;
        }
    }

    private void resolveIntent(Intent data, boolean foregroundDispatch){
        String action = data.getAction();


        if ((data.getFlags() & Intent.FLAG_ACTIVITY_LAUNCHED_FROM_HISTORY) != 0) return;

        if (NfcAdapter.ACTION_TECH_DISCOVERED.equals(action)){
            Tag tag = data.getParcelableExtra(NfcAdapter.EXTRA_TAG);

            if (foregroundDispatch && mWriteUrl){
                mWriteUrl = false;
                String urlStr = mMyUrl.getText().toString();
                byte[] urlBytes = urlStr.getBytes(Charset.forName("UTF-8"));
                byte[] urlPayload = new byte[urlBytes.length + 1];
                urlPayload[0] = 0;
                System.arraycopy(urlBytes,0,urlPayload,1,urlBytes.length);

                NdefRecord urlRecord = new NdefRecord(
                        NdefRecord.TNF_WELL_KNOWN,
                        NdefRecord.RTD_URI,
                        new byte[0],
                        urlPayload);

                NdefMessage msg = new NdefMessage(new NdefRecord[]{urlRecord});

                Ndef ndefTag = Ndef.get(tag);
                if (ndefTag != null){
                    try{
                        ndefTag.connect();
                        ndefTag.writeNdefMessage(msg);
                    } catch (FormatException e) {
                        e.printStackTrace();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    finally {
                        try{ndefTag.close();}catch (Exception e){}
                    }
                }
                else
                {
                    NdefFormatable ndefFormatableTag = NdefFormatable.get(tag);
                    if (ndefFormatableTag != null){
                        try {
                            ndefFormatableTag.connect();
                            ndefFormatableTag.format(msg);
                        } catch (FormatException e) {} catch (IOException e) {}
                        finally{
                            try{ndefFormatableTag.close();}catch (Exception e){}
                        }
                    }
                }
                    dismissDialog(DIALOG_WRITE_URL);
            }
            else{
                StringBuilder tagInfo = new StringBuilder();
                byte[] uid = tag.getId();
                tagInfo.append("UID: ")
                        //.append(StringUtils.convertByteArrayToHexString(uid))
                        .append(new BigInteger(1, uid).toString(16))
                        .append("\n\n");

                Parcelable[] ndefRaw =
                        data.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES);
                NdefMessage[] ndefMsgs = null;
                if (ndefRaw != null){
                    ndefMsgs = new NdefMessage[ndefRaw.length];
                    for (int i = 0; i < ndefMsgs.length; i++)
                        ndefMsgs[i] = (NdefMessage) ndefRaw[i];
                }

                if (ndefMsgs != null) {
                    for (int i = 0; i < ndefMsgs.length; i++) {
                        NdefRecord[] records = ndefMsgs[i].getRecords();

                        if (records != null) {
                            for (int j = 0; j < records.length; j++) {
                                if ((records[j].getTnf() == NdefRecord.TNF_WELL_KNOWN)
                                        && Arrays.equals(records[j].getType(), NdefRecord.RTD_URI)) {
                                    byte[] payload = records[j].getPayload();

                                    String uri = new String(Arrays.copyOfRange(payload, 1, payload.length),
                                            Charset.forName("UTF-8"));
                                    tagInfo.append("URI: ").append(uri).append("\n");
                                }
                            }
                        }
                    }
                }
                Bundle args = new Bundle();
                args.putString(ARG_MESSAGE,tagInfo.toString());
                showDialog(DIALOG_NEW_TAG,args);
            }
        }
    }

     @Override
    protected void onPrepareDialog(int id, Dialog dialog, Bundle args){
        switch (id) {
            case DIALOG_NEW_TAG:
                String message = args.getString(ARG_MESSAGE);
                if (message != null)
                    ((AlertDialog) dialog).setMessage(message);
                break;
        }
     }

}
