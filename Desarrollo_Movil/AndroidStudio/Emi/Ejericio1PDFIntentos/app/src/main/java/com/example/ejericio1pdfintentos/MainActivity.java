package com.example.ejericio1pdfintentos;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.*;
import android.content.Intent;
import android.widget.*;
public class MainActivity extends Activity {

    EditText txt1;
    EditText txt2;
    Button jbn;
    Bundle bd1;
    Bundle bd2;
    Intent itn1;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        txt1 = (EditText) findViewById(R.id.txt1);
        txt2 = (EditText) findViewById(R.id.txt2);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn1 = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd2 = new Bundle();
                bd1.putString("NOMBRE",txt1.getText().toString());
                bd2.putString("APELLIDO",txt2.getText().toString());
                itn1.putExtras(bd1);
                itn1.putExtras(bd2);
                startActivity(itn1);
            }
        });
    }
}
