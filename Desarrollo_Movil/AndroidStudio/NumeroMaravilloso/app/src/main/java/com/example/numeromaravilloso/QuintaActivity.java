package com.example.numeromaravilloso;


import android.app.Activity;
import android.os.Bundle;
import android.widget.*;

public class QuintaActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    String s;
    boolean fl;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        jet1.append("Verificacion Palindromo\n");
        jet1.append("Cadena introducida: " + bd1.getString("N") +"\n");
        s = bd1.getString("N");
        fl = VerificacionPalindromo(s);
        if (fl)
        {
            jet1.append("La cadena si es palindromo");
        }
        else
        {
            jet1.append("La cadena no es palindromo");
        }
    }


    public boolean VerificacionPalindromo(String s)
    {
        boolean flag = false;
        int longitud = s.length();
        if(longitud % 2 == 0)
        {
            //longitud par
            for(int i = 0; i < (s.length()/2) - 1; i++)
            {
                char c = s.charAt(i);
                if(c != s.charAt(s.length() -i - 1))
                    return false;
                else
                    flag = true;
            }
        }
        else
        {
            //longitud impar
            for(int i = 0; i < (s.length() -1 /2) - 1; i++)
            {
                char c = s.charAt(i);
                if(c != s.charAt(s.length() -i -1))
                    return false;
                else
                    flag = true;
            }
        }
        return flag;
    }

}
