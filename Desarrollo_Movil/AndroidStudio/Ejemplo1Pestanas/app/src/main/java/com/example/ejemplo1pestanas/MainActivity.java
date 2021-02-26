package com.example.ejemplo1pestanas;

import android.os.*;
import android.app.*;
import android.content.res.*;
import android.view.*;
import android.widget.*;
import android.widget.TabHost.*;

public class MainActivity extends Activity {

    Resources r;
    TabHost     th;
    TabSpec ts;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        r = getResources();
        th = (TabHost) findViewById(android.R.id.tabhost);
        th.setup();
        ts = th.newTabSpec("mitab1");
        ts.setContent(R.id.xtab1);
        ts.setIndicator("TAB1", r.getDrawable(android.R.drawable.ic_btn_speak_now));
        th.addTab(ts);
        ts = th.newTabSpec("mitab2");
        ts.setContent(R.id.xtab2);
        ts.setIndicator("TAB2", r.getDrawable(android.R.drawable.ic_dialog_map));
        th.addTab(ts);
        th.setCurrentTab(0);
        th.setOnTabChangedListener(new OnTabChangeListener() {
            public void onTabChanged(String tabId) {
                Toast.makeText(getApplicationContext(), "Pestaña seleccionada: " + tabId, Toast.LENGTH_SHORT).show();
            }
        });
    }
}
