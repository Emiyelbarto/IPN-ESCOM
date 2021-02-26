package com.example.numeromaravilloso;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;

public class CuartaActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    int a;
    boolean fl;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        jet1.append("Verificacion Numero Primo\n");
        jet1.append("Numero introducido: " + bd1.getString("N") +"\n");
        a = Integer.parseInt(bd1.getString("N"));
        fl = VerificacionPrimo(a);
        if (fl)
        {
            jet1.append("El numero si es primo");
        }
        else
        {
            jet1.append("El numero no es primo");
        }
    }

    public boolean VerificacionPrimo(int n)
    {
        if(n <= 3)
            return true;
        else if(n % 2 == 0 || n % 3 == 0)
            return false;
        int i = 5;
        while(i * i <= n)
        {
            if(n % i == 0 || n % (i+2) == 0)
                return false;
            i = i + 6;
        }
        return true;
    }

}
