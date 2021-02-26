package com.example.numeromaravilloso;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;

public class TerceraActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    int a;
    boolean fl;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        jet1.append("Verificacion Numero Fibonacci\n");
        jet1.append("Numero introducido: " + bd1.getString("N") +"\n");
        a = Integer.parseInt(bd1.getString("N"));
        fl = VerificacionFibonacci(a);
        if (fl)
        {
            jet1.append("El numero si es fibonacci");
        }
        else
        {
            jet1.append("El numero no es fibonacci");
        }
    }

    public boolean VerificacionFibonacci(int n)
    {
        if(n == 0 || n == 3 || n == 5 || n == 8)
            return true;
        double raiz, power;
        power = n * n;
        System.out.println("power:" + power);
        raiz = (5 * power) - 4;
        System.out.println("raiz antes de sacar raiz:" + raiz);
        raiz = Math.sqrt(raiz);
        System.out.println("raiz = " + raiz);
        if(raiz - Math.floor(raiz) == 0)
            return true;
        return false;
    }
}
