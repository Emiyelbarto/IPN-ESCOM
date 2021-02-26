package com.example.intento_poligono2;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

public class MyGLSurfaceView extends GLSurfaceView {

    MyGLRenderer renderer;

    private final float TOUCH_SCALE_FACTOR = 180.0f / 320.0f;
    private float previousX;
    private float previousY;

    public MyGLSurfaceView(Context context) {
        super(context);
        //setEGLContextClientVersion(2);
        renderer = new MyGLRenderer(context);
        this.setRenderer(renderer);
    }

    public boolean onTouchEvent(final MotionEvent evt)
    {
        float currentX = evt.getX();
        float currentY = evt.getY();
        float deltaX, deltaY;
        deltaX = currentX - previousX;
        deltaY = currentY - previousY;
        switch (evt.getAction()) {
            case MotionEvent.ACTION_MOVE:
                // Modify rotational angles according to movement

                if(currentX < getWidth() / 2)
                {
                    deltaX = deltaX * -1;

                }

                if (currentY > getHeight()/2)
                {
                    deltaY = deltaY * -1;
                }
                renderer.angleX += deltaY * TOUCH_SCALE_FACTOR;
                renderer.angleY += deltaX * TOUCH_SCALE_FACTOR;
                break;

            default:
                break;
        }
        // Save current x, y
        previousX = currentX;
        previousY = currentY;
        return true;  // Event handled
    }
}
