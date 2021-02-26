package com.example.numeromaravilloso;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.*;
import android.content.Intent;
import android.widget.*;

public class MainActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    Button jbn1, jbn2, jbn3, jbn4;
    Intent itn1, itn2, itn3, itn4;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jet1 = (EditText) findViewById(R.id.TxtNombre);
        jbn1 = (Button) findViewById(R.id.BtnMaravilloso);
        jbn2 = (Button) findViewById(R.id.BtnFibonacci);
        jbn3 = (Button) findViewById(R.id.BtnPrimo);
        jbn4 = (Button) findViewById(R.id.BtnPalindromo);
        //Numero Maravilloso
        jbn1.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn1 = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd1.putString("N",jet1.getText().toString());
                itn1.putExtras(bd1);
                startActivity(itn1);
            }
        });
        //Numero Fibonacci
        jbn2.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn2 = new Intent(MainActivity.this, TerceraActivity.class);
                bd1 = new Bundle();
                bd1.putString("N",jet1.getText().toString());
                itn2.putExtras(bd1);
                startActivity(itn2);
            }
        });
        //Numero Primo
        jbn3.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn3 = new Intent(MainActivity.this, CuartaActivity.class);
                bd1 = new Bundle();
                bd1.putString("N",jet1.getText().toString());
                itn3.putExtras(bd1);
                startActivity(itn3);
            }
        });
        //Palindromo
        jbn4.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn4 = new Intent(MainActivity.this, QuintaActivity.class);
                bd1 = new Bundle();
                bd1.putString("N",jet1.getText().toString());
                itn4.putExtras(bd1);
                startActivity(itn4);
            }
        });
    }
}
