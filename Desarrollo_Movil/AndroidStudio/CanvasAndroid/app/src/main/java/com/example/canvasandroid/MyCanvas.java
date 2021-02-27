package com.example.canvasandroid;


import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.Nullable;

public class MyCanvas extends View {

    private Paint paint;
    private Path path;

    public MyCanvas(Context context) {
        super(context);
        /*TEXTPAINT*/
        init(null);
    }

    /*
    Constructores de stackoverflow
    public MyCanvas(Context c) {
        super(c);
        init();
    }

     */
    public MyCanvas(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        init(attrs);
    }

    public MyCanvas(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(attrs);
    }

    public MyCanvas(Context context, @Nullable AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        init(attrs);
    }

    private void init(@Nullable AttributeSet set){

    }
    /*
    Acaban constructores
     */

    @Override
    protected void onDraw(Canvas canvas){
        super.onDraw(canvas);
        paint = new Paint();
        path = new Path();
        paint.setAntiAlias(true);
        paint.setColor(Color.BLACK);
        paint.setStrokeJoin(Paint.Join.ROUND);
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5f);
        canvas.drawPath(path,paint);
        //Primera Linea
        canvas.drawCircle(125,250, 25,paint);
        canvas.drawCircle(350,250, 25,paint);
        canvas.drawCircle(575,250, 25,paint);
        //Circulo inferior
        canvas.drawCircle(125,250, 15,paint);
        canvas.drawCircle(350,250, 15,paint);
        canvas.drawCircle(575,250, 15,paint);
        //Segunda linea
        canvas.drawCircle(125,500, 25,paint);
        canvas.drawCircle(350,500, 25,paint);
        canvas.drawCircle(575,500, 25,paint);
        //CIrculo inferior
        canvas.drawCircle(125,500, 15,paint);
        canvas.drawCircle(350,500, 15,paint);
        canvas.drawCircle(575,500, 15,paint);
        //Tercera Linea
        canvas.drawCircle(125,750, 25,paint);
        canvas.drawCircle(350,750, 25,paint);
        canvas.drawCircle(575,750, 25,paint);
        //Circulo inferior
        canvas.drawCircle(125,750, 15,paint);
        canvas.drawCircle(350,750, 15,paint);
        canvas.drawCircle(575,750, 15,paint);
        //TEXTO
        paint.setColor(Color.BLACK);
        paint.setTextSize(70);
        canvas.drawText("Dibujar Patrón", 120, 90, paint);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        float xPos = event.getX();
        float yPos = event.getY();

        switch (event.getAction()){
            case MotionEvent.ACTION_DOWN:
                path.moveTo(xPos,yPos);
                return true;

            case MotionEvent.ACTION_MOVE:
                path.lineTo(xPos,yPos);
                break;

            case MotionEvent.ACTION_UP:
                break;

            default:
                return false;
        }

        invalidate();
        return true;
    }
}
