package com.example.ejercicioarchivos2;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class ArchivosActivity extends AppCompatActivity {
    TextView tv;
    String			s;
    InputStream is;
    InputStreamReader isr;
    BufferedReader br;
    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.archivos_activity);
        tv	= (TextView) findViewById(R.id.xtv);
        tv.append("\nAbriendo: res/raw/misdatos.txt");
        is	= getResources().openRawResource(R.raw.misdatos);
        isr	= new InputStreamReader(is);
        br	= new BufferedReader(isr, 8192);
        try{
            while( null != (s=br.readLine()) )
                tv.append("\n" + s);
            is.close();
            isr.close();
            br.close();
        } catch(Exception e){
            tv.append("\n " + e);
        }
        tv.append("\nEnd of file.");
    }
}
