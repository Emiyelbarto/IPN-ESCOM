package com.example.numeromaravilloso;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;

public class SegundaActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    int a;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        jet1.append("Verificacion Numero Maravilloso\n");
        jet1.append("Numero introducido: " + bd1.getString("N") +"\n");
        a = Integer.parseInt(bd1.getString("N"));
        NumeroMaravilloso(a);
    }

    public int NumeroMaravilloso(int n)
    {
        while(n != 1)
        {
            if(n % 2 == 0)
            {
                jet1.append("Numero par = " + n + " / 2 = ");
                n = n / 2;
                jet1.append(n+"\n");
                n = NumeroMaravilloso(n);
            }
            else
            {
                jet1.append("Numero impar = (" + n + " * 3) + 1 = ");
                n = (n * 3) + 1;
                jet1.append(n+"\n");
                n = NumeroMaravilloso(n);
            }
        }
        return n;
    }

}
