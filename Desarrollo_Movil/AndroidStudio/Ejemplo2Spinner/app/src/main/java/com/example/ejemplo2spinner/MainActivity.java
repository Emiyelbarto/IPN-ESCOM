package com.example.ejemplo2spinner;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.*;

import java.util.List;

public class MainActivity extends AppCompatActivity implements OnItemSelectedListener {

    Spinner jsp1;
    Button jbn1;
    EditText jet1;

    @Override
    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jsp1 = (Spinner) findViewById(R.id.xsp1);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jet1 = (EditText) findViewById(R.id.xet1);
        jsp1.setOnItemSelectedListener(this);
        //jsp1.setOnItemSelectedListener(this);
        cargaSpinner();
        jbn1.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                String s = jet1.getText().toString();
                if (s.trim().length() > 0) {
                    DatabaseHandler db = new DatabaseHandler(getApplicationContext());
                    db.insertLabel(s);
                    jet1.setText("");
                    InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
                    imm.hideSoftInputFromWindow(jet1.getWindowToken(), 0);
                    cargaSpinner();
                } else {
                    Toast.makeText(getApplicationContext(), "Escribir elemento", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void cargaSpinner() {
        DatabaseHandler db = new DatabaseHandler(getApplicationContext());
        List<String> l = db.getAllLabels();
        ArrayAdapter<String> aa = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, l);
        aa.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        jsp1.setAdapter(aa);
    }

    //@Override
    public void onItemSelected(AdapterView<?> av, View v, int i, long l) {
        String s = av.getItemAtPosition(i).toString();
        Toast.makeText(av.getContext(), "Selección: " + s, Toast.LENGTH_LONG).show();
    }

    //@Override
    public void onNothingSelected(AdapterView<?> arg0) {
        // TODO Auto-generated method stub}
    }

    @Override
    public void onPointerCaptureChanged(boolean hasCapture) {

    }
}