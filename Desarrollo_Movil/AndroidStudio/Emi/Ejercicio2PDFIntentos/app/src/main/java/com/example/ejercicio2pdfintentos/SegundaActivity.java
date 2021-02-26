package com.example.ejercicio2pdfintentos;

import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SegundaActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    Bundle bd2;
    Bundle bd3;
    int a;
    float bb;
    int c;
    int condicion;
    double x1;
    double x2;

    public void onCreate (Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        bd2 = getIntent().getExtras();
        bd3 = getIntent().getExtras();
        jet1.append("A " + bd1.getString("A") + "\n");
        jet1.append("B " + bd2.getString("B") + "\n");
        jet1.append("C " + bd3.getString("C") + "\n");
        jet1.append("La raices del polinomio son: \n");

        a = Integer.parseInt(bd1.getString("A"));
        bb = Integer.parseInt(bd2.getString("B"));
        c = Integer.parseInt(bd3.getString("C"));

        float aux = bb * bb;
        condicion = 4 * a * c;

        if (a == 0)
        {
            x1 = (-c / bb);
            System.out.println("B = "+bb + "\nC ="+c);
            System.out.println(c+" / "+bb+" = "+x1+"\n");
            jet1.append("Raiz = " + x1 + "\n");
        }
        else {
            if(Math.pow(bb,2) < condicion)
            {
                jet1.append("Las raices serán complejas\n");
                jet1.append("\nRaiz 1 = (" + -bb + " + " + Math.sqrt(4*a*c) + "i" + ")/" +2*a);
                jet1.append("\nRaiz 1 = (" + -bb + " - " + Math.sqrt(4*a*c) + "i" + ")/" +2*a);
            }
            else
            {
                x1 = (-bb + (Math.sqrt(Math.pow(bb,2) - (4 * a * c) ) ) ) / (2 * a);
                x2 = (-bb - (Math.sqrt(Math.pow(bb,2) - (4 * a * c) ) ) ) / (2 * a);
                if(x1 == x2)
                {
                    jet1.append("Raiz 1 = " + x1 + "\n");
                    jet1.append("Raiz 2 = " + -x2 + "\n");
                }
                else
                {
                    jet1.append("Raiz 1 = " + x1 + "\n");
                    jet1.append("Raiz 2 = " + x2 + "\n");
                }

            }
        }
    }
}
