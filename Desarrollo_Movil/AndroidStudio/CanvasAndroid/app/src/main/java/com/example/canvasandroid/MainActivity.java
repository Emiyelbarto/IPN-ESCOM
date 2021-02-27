package com.example.canvasandroid;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private int flag = 0;
    private MyCanvas myCanvas;
    private Button guardarPatron;
    private Button verPelicula;
    private RelativeLayout relativeLayout;
    private Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        myCanvas = new MyCanvas(this);
        //setContentView(myCanvas);
        setContentView(R.layout.activity_main);

        guardarPatron = (Button) findViewById(R.id.buttonGuardar);
        intent = new Intent(this, VideoActivity.class);

        guardarPatron.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (flag == 0) {
                    Toast.makeText(getApplicationContext(), "Patrón Guardado!",
                            Toast.LENGTH_LONG).show();
                    guardarPatron.setText("Eliminar Patrón");
                    flag = 1;
                }
                else{
                    Toast.makeText(getApplicationContext(), "Patrón Eliminado!",
                            Toast.LENGTH_LONG).show();
                    guardarPatron.setText("Guardar Patrón");
                    flag = 0;
                    startActivity(intent);
                }
            }
        });
        /*
         */
    }
}
