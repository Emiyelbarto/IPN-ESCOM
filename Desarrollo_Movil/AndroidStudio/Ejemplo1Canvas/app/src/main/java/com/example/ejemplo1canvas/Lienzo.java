package com.example.ejemplo1canvas;
import android.annotation.SuppressLint;
import android.content.*;
import android.graphics.*;
import android.view.View;

public class Lienzo extends View {
    Paint   p;
    int     x, y;
    String s = "hola";

    public Lienzo(Context c){
        super(c);
    }

    @SuppressLint("DrawAllocation")
    protected void onDraw(Canvas c) {
        super.onDraw(c);  // Canvas pinta atributos
        p = new Paint();  // Paint asigna atributos
        x = getWidth();  // También: getMeasuredWidth() o getRight(), x=480
        y = getHeight();  // También: getMeasuredHeight() o getBottom(), y=762
        p.setColor(Color.WHITE); // Fondo blanco
        c.drawPaint(p);
        p.setColor(Color.BLACK); // Texto negro
        p.setTextSize(40);
        c.drawText("x0=" + x / 2 + ", y0=" + y / 2, x / 2 + 20, y / 2 - 20, p);
        p.setColor(Color.rgb(0, 0, 255));   // Ejes azules
        c.drawLine(x / 2, 0, x / 2, y, p);
        c.drawLine(0, y / 2, x, y / 2, p);
        p.setTextAlign(Paint.Align.LEFT);
        p.setTypeface(Typeface.SANS_SERIF);
        c.drawText("x0=" + x/2 + ", y0=" + y/2, x/2 + 20, y/2-20, p);
        p.setTextAlign(Paint.Align.LEFT);
        p.setTypeface(Typeface.SANS_SERIF);
        c.drawText("Eje Y", x / 2 + 10, 40, p);
        p.setColor(Color.argb(100, 200, 100, 100));
        c.drawCircle(x/2-140, y/2+140, 100, p);
        Paint mPaint;
        mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        c.drawOval(new RectF(x/2-280, y/2-280, x/2-100, y/2-170), mPaint);
        c.drawRect(x/2+280,y/2-280,x/2+140,y/2-140, mPaint);
        Path path = new Path();
        Point point1_draw = new Point(600, 800);
        Point point2_draw = new Point(520, 875);
        Point point3_draw = new Point(700, 875);
        path.moveTo(point1_draw.x, point1_draw.y);
        path.lineTo(point2_draw.x, point2_draw.y);
        path.lineTo(point3_draw.x, point3_draw.y);
        path.lineTo(point1_draw.x, point1_draw.y);
        path.close();
        c.drawARGB(0, 0, 0, 0);
        c.drawPath(path, p);
    }
}