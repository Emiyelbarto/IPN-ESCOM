package com.example.pruebacronometro;

import android.annotation.SuppressLint;
import android.app.Service;
import android.content.Intent;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;

@SuppressLint("Registered")
public class Cronometro extends Service{
    ExampleTimer t;
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
        t = new ExampleTimer(1000,1000000);
    }

    private void pararCronometro() {
        t.cancel();
    }

    private void resumirCronometro() {
        t.resume();
    }

    private void pausarCronometro() {
        t.pause();
    }

}