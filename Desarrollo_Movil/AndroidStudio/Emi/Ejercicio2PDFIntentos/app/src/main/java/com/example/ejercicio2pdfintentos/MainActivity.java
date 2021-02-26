package com.example.ejercicio2pdfintentos;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.*;
import android.content.Intent;
import android.widget.*;
public class MainActivity extends Activity {

    EditText txt1;
    EditText txt2;
    EditText txt3;
    Button jbn;
    Bundle bd1;
    Bundle bd2;
    Bundle bd3;
    Intent itn1;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        txt1 = (EditText) findViewById(R.id.txt1);
        txt2 = (EditText) findViewById(R.id.txt2);
        txt3 = (EditText) findViewById(R.id.txt3);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn1 = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd2 = new Bundle();
                bd3 = new Bundle();
                bd1.putString("A",txt1.getText().toString());
                bd2.putString("B",txt2.getText().toString());
                bd3.putString("C",txt3.getText().toString());
                itn1.putExtras(bd1);
                itn1.putExtras(bd2);
                itn1.putExtras(bd3);
                startActivity(itn1);
            }
        });
    }
}
