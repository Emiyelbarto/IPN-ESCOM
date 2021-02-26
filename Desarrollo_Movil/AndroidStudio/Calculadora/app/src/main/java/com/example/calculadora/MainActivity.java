package com.example.calculadora;


import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {

    EditText etxt1;
    Button factorial;
    Button dig0, dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9;
    Button borrar;
    long res;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        dig0 = (Button) findViewById(R.id.ButtonCero);
        dig1 = (Button) findViewById(R.id.buttonUno);
        dig2 = (Button) findViewById(R.id.buttonDos);
        dig3 = (Button) findViewById(R.id.buttonTres);
        dig4 = (Button) findViewById(R.id.buttonCuatro);
        dig5 = (Button) findViewById(R.id.buttonCinco);
        dig6 = (Button) findViewById(R.id.buttonSeis);
        dig7 = (Button) findViewById(R.id.buttonSeven);
        dig8 = (Button) findViewById(R.id.buttonEight);
        dig9 = (Button) findViewById(R.id.buttonNine);
        factorial = (Button) findViewById(R.id.ButtonFactorial);
        borrar = (Button) findViewById(R.id.buttonErase);
        etxt1 = (EditText) findViewById(R.id.txt1);


        dig0.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "0");
            }
        });

        dig1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "1");
            }
        });


        dig2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "2");
            }
        });

        dig3.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "3");
            }
        });

        dig4.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "4");
            }
        });

        dig5.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "5");
            }
        });

        dig6.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "6");
            }
        });

        dig7.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "7");
            }
        });

        dig8.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "8");
            }
        });


        dig9.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText(etxt1.getText() + "9");
            }
        });

        borrar.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                etxt1.setText("");
            }
        });

        factorial.setOnClickListener(new View.OnClickListener() {
            public void onClick(View arg0) {
                int a = Integer.parseInt(etxt1.getText().toString());
                res = factorial(a);
                etxt1.setText(a + "! = "+res);
            }
        });




    }

    public long factorial(int n)
    {
        res = 1;
        for (int i = 2; i <= n; i++)
        {
            res = res * i;
        }
        System.out.println(res);
        return res;
    }
}
