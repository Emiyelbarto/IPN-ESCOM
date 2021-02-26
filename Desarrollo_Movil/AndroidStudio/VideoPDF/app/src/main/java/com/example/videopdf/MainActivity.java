package com.example.videopdf;

import androidx.appcompat.app.AppCompatActivity;

import android.net.Uri;
import android.os.Bundle;
import android.widget.MediaController;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity {

    VideoView vvw;
    Uri uri;
    MediaController mcr;
    @Override
    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        vvw = (VideoView) findViewById(R.id.xvv1);
        final String videoPath = "android.resource://" + this.getPackageName() + "/" + R.raw.video2;
        uri = Uri.parse(videoPath);
        mcr = new MediaController(this);
        vvw.setMediaController(mcr);
        vvw.setVideoURI(uri);
        vvw.start();
    }
}
