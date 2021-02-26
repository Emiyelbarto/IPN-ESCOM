package com.example.ejemplobuttons1;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;      // -1
import android.widget.*;
public class MainActivity extends Activity implements OnClickListener{ // -2
    Button jbn1, jbn2, jbn3, jbn4;
    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jbn1 = (Button) findViewById(R.id.xbn1);                    // MÉTODO 1
        jbn1.setOnClickListener(bn1Listener);     // -3
        jbn2 = (Button)findViewById(R.id.xbn2);                     // MÉTODO 2
        jbn2.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                showToastMessage("Botón digitado: xbn2\nUtiliza: new OnClickListener{}");
            }
        }
        );
        jbn3 = (Button) findViewById(R.id.xbn3);                    // MÉTODO 3
        jbn3.setOnClickListener(this);
    }

    private OnClickListener bn1Listener = new OnClickListener() {  // desde el MÉTODO 1
        public void onClick(View v) {
            showToastMessage("Botón digitado: xbn1\nUtiliza: clase btn1Listener");
        }
    };

    public void onClick(View v) {       // -4 y -5
        showToastMessage("Botón digitado: xbn3\nUtiliza: implements OnClickListener.");
    }

    public void xbn4DesdeXML(View v) {                              // MÉTODO 4
        showToastMessage("Boton digitado: xbn4\nInvoca al método desde el XML.");
    }
    private void showToastMessage(String msg){
        Toast toast = Toast.makeText(this, msg, Toast.LENGTH_SHORT);         toast.show();
    }
}