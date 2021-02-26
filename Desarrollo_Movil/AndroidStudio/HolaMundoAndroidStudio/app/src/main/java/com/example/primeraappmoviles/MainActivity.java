package com.example.primeraappmoviles;

import android.annotation.SuppressLint;
import android.app.*;
import android.os.*;
import android.widget.*;
import android.view.*;
//Realizar num maravilloso, primo, fibo y palindromo
public class MainActivity extends Activity
{
    int x,y,z;
    TextView jtv1;
    int n;

    @SuppressLint("SetTextI18n")
    protected void onCreate(Bundle b)
    {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        x = 3;
        y = 5;
        z = x + y; // z = 8
        jtv1 = (TextView) findViewById(R.id.xtv1);
        jtv1.setText( x + "+" + y + "=" + z);
        //tv = (TextView) (findViewById(tr));
    }
}