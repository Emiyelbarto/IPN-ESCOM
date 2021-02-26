package com.example.cuadrado;

import android.app.Activity;
import android.os.Bundle;
import android.widget.GridView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class SegundaActivity extends Activity {

    TextView txv1;
    Bundle bd1;
    int tam;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        txv1 = (TextView) findViewById(R.id.txt1);
        bd1 = getIntent().getExtras();
        txv1.setText("tamaño del cuadrado: "+bd1.getString(("N")));
        tam = Integer.parseInt(bd1.getString("N"));

        GridView grid = (GridView) findViewById(R.id.grid);
        grid.setNumColumns(tam);

        List<Matrix> matrixList = new ArrayList<>();


        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
                matrixList.add(new com.example.cuadrado.Matrix(i,j));
        }
    }
}
