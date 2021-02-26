package com.example.ejemplo1fragmentos;

import android.os.Bundle;
import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.res.Configuration;
import android.view.WindowManager;
import android.widget.HorizontalScrollView;

public class MainActivity extends Activity{
    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        Configuration c = getResources().getConfiguration();
        FragmentManager fm = getFragmentManager();
        FragmentTransaction ft = fm.beginTransaction();
        if(c.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            HorizontalFragmento hf = new HorizontalFragmento();
            ft.replace(android.R.id.content, hf);
        }
        else{
            VerticalFragmento vf = new VerticalFragmento();
            ft.replace(android.R.id.content, vf);
        }
        ft.commit();
    }
}