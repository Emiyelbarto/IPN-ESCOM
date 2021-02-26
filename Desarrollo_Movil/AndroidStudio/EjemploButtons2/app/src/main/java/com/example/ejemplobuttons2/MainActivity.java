package com.example.ejemplobuttons2;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;                                           // 1
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener{              // 2
    ImageButton     jib1;
    ToggleButton    jtb1;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jib1 = (ImageButton) findViewById(R.id.xib1);
        jib1.setOnClickListener(this);// 3
        jtb1 = (ToggleButton)findViewById(R.id.xtb1);
        jtb1.setOnClickListener(this);
    }

    public void onClick(View v) {                                                   // 4
        if(v.getId()==R.id.xib1)                                                    // 5
            showToastMessage("Botón: ImageButton");
        else {
            if (jtb1.isChecked()) showToastMessage("Botón: ToggleButton en ON");
            else showToastMessage("Botón: ToggleButton en OFF");
        }
    }

    private void showToastMessage(String s){
        Toast t = Toast.makeText(this, s, Toast.LENGTH_SHORT);
        t.show();
    }
}