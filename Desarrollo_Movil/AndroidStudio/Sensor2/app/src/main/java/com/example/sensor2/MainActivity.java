package com.example.sensor2;

import android.app.Activity;
import android.content.Context;
import android.hardware.*;
import android.os.*;
import android.widget.TextView;

public class MainActivity extends Activity implements SensorEventListener{
    SensorManager   sm;
    Sensor          s;
    int             n;
    double          x, y, z, a, m, g;
    TextView        jtvX, jtvY, jtvZ, jtvA, jtvM, jtvG;

    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        sm = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        s = sm.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        sm.registerListener(this, s, SensorManager.SENSOR_DELAY_FASTEST);
        x=0; y=0; z=0; a=0; m=0; n=0;
        g = SensorManager.STANDARD_GRAVITY;
        jtvX = (TextView) findViewById(R.id.xtvX);
        jtvY = (TextView) findViewById(R.id.xtvY);
        jtvZ = (TextView) findViewById(R.id.xtvZ);
        jtvA = (TextView) findViewById(R.id.xtvA);
        jtvM = (TextView) findViewById(R.id.xtvM);
        jtvG = (TextView) findViewById(R.id.xtvG);

        new MiAsincronia().execute();
    }

    public void onSensorChanged(SensorEvent se){
        x = se.values[0];
        y = se.values[1];
        z = se.values[2];
        a = Math.sqrt(x*x + y*y + z*z);
        if(a>m)
            m = a;
    }

    public void onAccuracyChanged(Sensor s, int i){}

    class MiAsincronia extends AsyncTask<Void, Void, Void>{
        protected Void doInBackground(Void... x){
            while(true){
                try {
                    Thread.sleep(100); // 100 milisegundos
                }
                catch(InterruptedException e){
                    e.printStackTrace();
                }

                n++;
                publishProgress();
            }
        }

        protected void onProgressUpdate(Void... progress){
            jtvX.setText(" " + x + "\n");
            jtvY.setText(" " + y + "\n");
            jtvZ.setText(" " + z + "\n");
            jtvA.setText(" " + a + "\n");
            jtvM.setText(" " + m + "\n");
            jtvG.setText(" " + g + "\t\tActualización: " + n + "(ms)");
        }
    }
}

