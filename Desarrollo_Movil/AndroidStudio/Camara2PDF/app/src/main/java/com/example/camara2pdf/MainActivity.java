package com.example.camara2pdf;

import java.io.*;
import android.app.Activity;
import android.content.Intent;
import android.graphics.*;
import android.media.MediaScannerConnection;
import android.media.MediaScannerConnection.MediaScannerConnectionClient;
import android.net.Uri;
import android.os.*;
import android.provider.MediaStore;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button      jbn;
    RadioButton jrb1, jrb2;
    Intent      i;
    int         TAKE_PICTURE = 1;
    int         SELECT_PICTURE = 2;
    String      s = "";

    @Override     public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        s = Environment.getExternalStorageDirectory() + "/test.jpg";
        jbn = (Button)findViewById(R.id.xbn1);
        jbn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                jrb1 = (RadioButton)findViewById(R.id.xrb1);
                jrb2 = (RadioButton)findViewById(R.id.xrb2);
                i =  new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
                int code = TAKE_PICTURE;
                if (jrb1.isChecked()) {
                    Uri output = Uri.fromFile(new File(s));
                    i.putExtra(MediaStore.EXTRA_OUTPUT, output);
                } else if (jrb2.isChecked()){
                    i = new Intent(Intent.ACTION_PICK, android.provider.MediaStore.Images.Media.INTERNAL_CONTENT_URI);
                    code = SELECT_PICTURE;
                }
                startActivityForResult(i, code);
            }
        });
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == TAKE_PICTURE) {
            if (data != null) {
                if (data.hasExtra("data")) {
                    ImageView iv = (ImageView)findViewById(R.id.xiv1);
                    iv.setImageBitmap((Bitmap) data.getParcelableExtra("data"));
                }
            } else {
                ImageView iv = (ImageView)findViewById(R.id.xiv1);
                iv.setImageBitmap(BitmapFactory.decodeFile(s));
                new MediaScannerConnectionClient() {
                    private MediaScannerConnection msc = null; {
                        msc = new MediaScannerConnection(getApplicationContext(), this); msc.connect();
                    }
                    public void onMediaScannerConnected() {
                        msc.scanFile(s, null);
                    }
                    public void onScanCompleted(String path, Uri uri) {
                        msc.disconnect();
                    }
                };
            }
        } else if (requestCode == SELECT_PICTURE){
            Uri image = data.getData();
            InputStream is;
            try {
                is = getContentResolver().openInputStream(image);
                BufferedInputStream bis = new BufferedInputStream(is);
                Bitmap bitmap = BitmapFactory.decodeStream(bis);
                ImageView iv = (ImageView)findViewById(R.id.xiv1);
                iv.setImageBitmap(bitmap);
            } catch (FileNotFoundException e) {}
        }
    }
}