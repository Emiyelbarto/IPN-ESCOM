package com.example.ejericio1pdfintentos;

import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SegundaActivity extends Activity {

    EditText jet1;
    Bundle bd1;
    Bundle bd2;

    public void onCreate (Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        bd2 = getIntent().getExtras();
        System.out.println(bd1);
        System.out.println(bd2);

        jet1.append("Hola " + bd1.getString("NOMBRE") +" "+ bd2.getString("APELLIDO"));

    }

}
