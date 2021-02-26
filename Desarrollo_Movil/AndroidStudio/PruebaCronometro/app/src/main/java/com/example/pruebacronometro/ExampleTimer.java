package com.example.pruebacronometro;

import android.os.Handler;

public class ExampleTimer extends Timer {

    private Handler h;

    public ExampleTimer() {
        super();
    }

    public ExampleTimer(long interval, long duration){
        super(interval, duration);
    }

    @Override
    protected void onTick() {
        h += 0.01;

    }

    @Override
    protected void onFinish() {
        System.out.println("onFinish called!");
    }
}
