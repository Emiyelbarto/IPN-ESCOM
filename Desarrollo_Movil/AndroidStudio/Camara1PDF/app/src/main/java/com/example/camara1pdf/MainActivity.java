package com.example.camara1pdf;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.hardware.Camera;
import android.media.Image;
import android.media.audiofx.EnvironmentalReverb;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {
    private final String ruta = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DCIM) + "/tmpfotos/";
    private File f = new File(ruta);
    private Button jbn;
    private ImageView imgv;
    private static final int RC_PIC_CODE = 101;
    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jbn = (Button) findViewById(R.id.xbn);
        imgv = (ImageView) findViewById(R.id.result_foto);
        f.mkdirs();
        jbn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                capture();
                String s = ruta + getCode() + ".jpg";
                File f1 = new File(s);
                try{
                    f1.createNewFile();
                }catch(IOException ex){
                    Log.e("Error", "Error:" + ex);
                    Uri u = Uri.fromFile(f1);
                    Intent in = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
                    in.putExtra(MediaStore.EXTRA_OUTPUT, u);
                    startActivityForResult(in, 0);
                }
            }
        });
    }

    private String getCode(){
        SimpleDateFormat sdf = new SimpleDateFormat("yyyymmddhhmmss");
         String n = "pic_" + sdf.format(new Date());;
        return n;
    }

    private void capture(){
        Intent takepictureintent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        startActivityForResult(takepictureintent,RC_PIC_CODE);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        super.onActivityResult(requestCode,resultCode,data);

        if(requestCode == RC_PIC_CODE){
            if(resultCode == RESULT_OK){
                Bitmap bp = (Bitmap) data.getExtras().get("data");

                imgv.setScaleType(ImageView.ScaleType.FIT_CENTER);
                imgv.setImageBitmap(bp);
            }
            else if(resultCode == RESULT_CANCELED){
                Toast.makeText(this,"cancelled", Toast.LENGTH_SHORT).show();
            }
        }
    }
}