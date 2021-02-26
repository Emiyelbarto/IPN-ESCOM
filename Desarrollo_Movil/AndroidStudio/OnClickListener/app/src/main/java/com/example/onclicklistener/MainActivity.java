package com.example.onclicklistener;

import androidx.appcompat.app.AppCompatActivity;
import android.app.*;
import android.os.*;
import android.view.View;
import android.view.View.*; //OnClickListener //1
import android.widget.*;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    EditText jet1;
    Button jbn1;

    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jet1 = (EditText) findViewById(R.id.xet1);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn1.setOnClickListener((OnClickListener) this); //3
    }

    public void onClick(View v)
    {
        int n = Integer.parseInt(jet1.getText()+"");
    }
}
