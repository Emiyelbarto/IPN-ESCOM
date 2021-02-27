package com.example.canvasandroid;

import android.app.Activity;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.MediaController;
import android.widget.VideoView;

public class VideoActivity extends Activity {

    private Button buttonReproducir;
    private int flag = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_video);

        buttonReproducir = (Button) findViewById(R.id.buttonReproducir);

        final VideoView videoView = findViewById(R.id.video_view);
        final String videoPath = "android.resource://" + getPackageName() + "/" + R.raw.vid;
        Uri uri = Uri.parse(videoPath);
        videoView.setVideoURI(uri);

        MediaController mediaController = new MediaController(this);
        videoView.setMediaController(mediaController);
        mediaController.setAnchorView(videoView);

        buttonReproducir.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (flag == 0){
                    videoView.start();
                    buttonReproducir.setText("Salir");
                    flag = 1;
                }
                else{
                    finish();
                    System.exit(0);
                }
            }
        });
    }
}
