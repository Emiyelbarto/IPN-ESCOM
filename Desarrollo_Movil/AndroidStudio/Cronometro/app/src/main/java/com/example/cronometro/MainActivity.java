package com.example.cronometro;


import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity { // ServiceTimerActivity
        private TextView    jtv;
        private Button      jbn;

        @Override
        public void onCreate(Bundle b) {
            super.onCreate(b);
            setContentView(R.layout.activity_main);
            jtv = (TextView) findViewById(R.id.xtvT);
            jbn = (Button) findViewById(R.id.xbnI);
            jbn.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                    initCrono();
                }
            });

            Button stopButton = (Button) findViewById(R.id.xbnT);
            stopButton.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    stopCrono();
                }
            });

            Cronometro.setUpdateListener(this);
        }

        @Override
        protected void onDestroy() {
            stopCrono();
            super.onDestroy();
        }

        private void initCrono() {
            Intent in = new Intent(this, Cronometro.class);
            startService(in);
        }

        private void stopCrono() {
            Intent in = new Intent(this, Cronometro.class);
            stopService(in);
        }

        private void pruebaCrono()
        {
            Intent in = new Intent(this, Cronometro.class);

        }

        public void refreshCrono(double t) {
            jtv.setText(String.format("%.2f", t) + " segs");
        }
}