package com.example.cuadrado;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {

    Button createButton;
    EditText etx1;
    Intent itn1;
    Bundle bd1;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        createButton = (Button) findViewById(R.id.btncrear);
        etx1 = (EditText) findViewById(R.id.txt1);
        createButton.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0)
            {
                itn1 = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd1.putString("N",etx1.getText().toString());
                itn1.putExtras(bd1);
                startActivity(itn1);
            }
        });
    }
}
