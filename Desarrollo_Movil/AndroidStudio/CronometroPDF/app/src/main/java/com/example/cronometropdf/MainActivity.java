package com.example.cronometropdf;

import android.app.*;
import android.os.*;
import android.view.*;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener{
    Chronometer c;
    Button      jbnI, jbnF, jbnR;
    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        c = (Chronometer)findViewById(R.id.xch);
        jbnI = (Button)findViewById(R.id.xbnI); jbnI.setOnClickListener(this);
        jbnF = (Button)findViewById(R.id.xbnF); jbnF.setOnClickListener(this);
        jbnR = (Button)findViewById(R.id.xbnR); jbnR.setOnClickListener(this);
    }
    @Override
    public void onClick(View v){
        switch(v.getId()){
            case R.id.xbnI:
                c.start();
                break;
            case R.id.xbnF:
                c.stop();
                break;
            case R.id.xbnR:
                c.setBase(SystemClock.elapsedRealtime());
                break;
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        //getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
