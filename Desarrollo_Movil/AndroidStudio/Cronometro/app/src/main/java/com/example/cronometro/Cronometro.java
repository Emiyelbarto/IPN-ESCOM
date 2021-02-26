package com.example.cronometro;

import java.util.*;
import android.annotation.SuppressLint;
import android.app.Service;
import android.content.Intent;
import android.os.*;

@SuppressLint("Registered")
public class Cronometro extends Service {
    private Timer t = new Timer();
    private static final long INTERVALO_ACTUALIZACION = 10; //// En milisegundos
    public static MainActivity UPDATE_LISTENER;
    private double n = 0;
    private Handler h;

    public static void setUpdateListener(MainActivity sta) {
        UPDATE_LISTENER = sta;
    }

    @SuppressLint("HandlerLeak")
    @Override
    public void onCreate() {
        super.onCreate();
        h = new Handler();
        iniciarCronometro();
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
        pararCronometro();
        super.onDestroy();
    }

    @Override
    public IBinder onBind(Intent arg0) {
        return null;
    }

    private void iniciarCronometro() {
        t.scheduleAtFixedRate(new TimerTask() {
            public void run() {
                n += 0.01;
                h.sendEmptyMessage(0);
            }
        }, 0, INTERVALO_ACTUALIZACION);
    }

    private void pararCronometro() {
        if (t != null)
            t.cancel();
    }

    private void resumirCronometro() {

    }

    private void pausarCronometro() {

    }

}