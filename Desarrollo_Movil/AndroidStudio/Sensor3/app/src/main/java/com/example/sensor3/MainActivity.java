package com.example.sensor3;

import android.os.*;
import android.app.*;
import android.content.*;
import android.hardware.*;
import android.widget.*;

public class MainActivity extends Activity implements SensorEventListener{
    int             n = 0;
    boolean         c = true;
    double          x=0, y=0, z=0, a=0, bM=0;
    double          mfeM = SensorManager.MAGNETIC_FIELD_EARTH_MAX;
    double          mfem = SensorManager.MAGNETIC_FIELD_EARTH_MIN;
    SensorManager   sm;     Sensor          s;
    TextView jtvx, jtvy, jtvz, jtva, jtvM, jtvG;

    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jtvx = (TextView) findViewById(R.id.xtvX);
        jtvy = (TextView) findViewById(R.id.xtvY);
        jtvz = (TextView) findViewById(R.id.xtvZ);
        jtva = (TextView) findViewById(R.id.xtvB);
        jtvM = (TextView) findViewById(R.id.xtvM);
        jtvG = (TextView) findViewById(R.id.xtvT);
        sm   = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        s    = sm.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
        sm.registerListener(this, s, SensorManager.SENSOR_DELAY_NORMAL);
        new Asincronia().execute();
    }

    public void onResume(){
        super.onResume();
        c = true;
        new Asincronia().execute();
    }

    public void onPause(){
        super.onPause();
        c = false;
    }

    public void onAccuracyChanged(Sensor s, int i){}

    public void onSensorChanged(SensorEvent e){
        x = e.values[0];
        y = e.values[1];
        z = e.values[2];
        a = Math.sqrt(x*x + y*y + z*z);
        if(a > bM)
            bM = a;
    }

    class Asincronia extends AsyncTask<Void, Void, Void>{
        protected Void doInBackground(Void... v){
            while (c){
                try{
                    Thread.sleep(200);
                }catch(InterruptedException e){ e.printStackTrace(); }
                n++;
                publishProgress();
            }
            return null;
        }

        protected void onProgressUpdate(Void... v){
            jtvx.setText(x + "");
            jtvy.setText(y + "");
            jtvz.setText(z + "");
            jtva.setText(a + "");
            jtvM.setText(bM + "");
            jtvG.setText(mfem + " - " + mfeM  + "");
            jtvG.append(n  + "");
        }

        protected void onPostExecute(Void result){
            super.onPostExecute(result);
            Context c = getApplicationContext();
            Toast.makeText(c, "Fin de Campo Magnetico.", Toast.LENGTH_LONG).show();
        }
    }
}

