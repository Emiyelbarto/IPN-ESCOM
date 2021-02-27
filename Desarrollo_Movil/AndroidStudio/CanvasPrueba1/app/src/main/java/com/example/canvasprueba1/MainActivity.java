package com.example.canvasprueba1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.os.Bundle;
import android.view.MotionEvent;

import com.example.canvasprueba1.views.CustomView;

public class MainActivity extends AppCompatActivity {

    CustomView cv;

    @Override
    protected void onCreate(Bundle b){
        super.onCreate(b);
        cv = new CustomView(this,null);
        setContentView(cv);
    }
}