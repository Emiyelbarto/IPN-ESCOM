package com.example.ejerciciobutton1;
import android.media.MediaPlayer;
import android.app.Activity;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;
import android.os.Bundle;

public class MainActivity extends Activity {

    MediaPlayer mp;
    Button btn;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        mp = MediaPlayer.create(MainActivity.this, R.raw.sonido1);
        mp.start();
        btn = (Button) findViewById(R.id.btnSonido);

        btn.setOnClickListener(new OnClickListener() {
            public void onClick(View v)
            {
                mp.start();
            }
        });

    }

    public void onDestroy()
    {
        mp.stop();
        super.onDestroy();
    }
}
