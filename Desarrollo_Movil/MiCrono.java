package com.example.cronometro;

import java.util.*;
import android.app.Service;
import android.content.Intent;
import android.os.*;
import android.util.Log;

public class MiCrono extends Service {
    private Timer t = new Timer();
    private static final long INTERVALO_ACTUALIZACION = 10; //// En milisegundos
    public static MainActivity UPDATE_LISTENER;
    private double n = 0;
    private Handler h;
    private int timerSize = 0;
    private boolean timerStartFlag = false;
    private boolean hiddenVisibleFrg = false;
    private int videoTime = 0;

    public static void setUpdateListener(MainActivity sta) {
        UPDATE_LISTENER = sta;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        h = new Handler();
        iniciarCrono();
        h = new Handler() {
            @Override
            public void handleMessage(Message msg)
            {
                UPDATE_LISTENER.refreshCrono(n);
            }
        };
    }

    @Override
    public void onDestroy() {
        pararCrono();
        super.onDestroy();
    }

    @Override
    public IBinder onBind(Intent arg0) {
        return null;
    }

    private void iniciarCrono() {
        t.scheduleAtFixedRate(new TimerTask() {
            public void run() {
                n += 0.01;
                h.sendEmptyMessage(0);
            }
            }, 0, INTERVALO_ACTUALIZACION);
    }

    private void pararCrono() {
        if (t != null)
            t.cancel();
    }

    private void continuarCrono(){
        if (t != null)
        {
            //Continuar Cronometro
        }
    }

    private void pausarCrono(){

        Log.e("keshav","onPause timer1" + t);
    }

}