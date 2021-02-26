package com.example.ejemplo2fragmentos;

import com.example.ejemplo2fragmentos.MiFragmento;
import android.app.*;
import android.os.*;
import android.view.*;
import android.view.View.*;
import android.widget.*;

public class MainActivity extends Activity implements MiFragmento.FragmentoListener {
    TextView    xtv;
    Button      jbn;

    @Override
    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        xtv = (TextView) findViewById(R.id.xtv);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                FragmentManager fm = getFragmentManager();
                Fragment f = fm.findFragmentByTag("editor");
                if (null == f) {
                    FragmentTransaction ft = fm.beginTransaction();
                    ft.add(R.id.xfl, new MiFragmento(), "editor");
                    ft.commit();
                }
                xtv.setText("");
                Toast.makeText(MainActivity.this, "Utilizando Fragment", Toast.LENGTH_LONG).show();
            }
        });
    }

    @Override
    public void digitado(int r, String s) {
        TextView xtv = (TextView) findViewById(R.id.xtv);
        if (r == MiFragmento.OK) {
            xtv.setText(s);
        }
        FragmentManager     fm = getFragmentManager();
        Fragment            fe = fm.findFragmentByTag("editor");
        FragmentTransaction ft = fm.beginTransaction();
        ft.remove(fe);
        ft.commit();
    }
}