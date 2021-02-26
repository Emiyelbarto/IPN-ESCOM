package com.example.ejercicioarchivos2;

import androidx.appcompat.app.AppCompatActivity;
import android.os.*;
import android.widget.*;
import java.io.*;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    TextView        jtv;
    File            f, d, r;
    FileOutputStream fos;
    PrintWriter     pw;
    String          s;
    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.archivos_activity);
        jtv  = (TextView) findViewById(R.id.xtv);
        s   = Environment.getExternalStorageState();    // Tarjeta SD disponible.
        System.out.println(s);
        /*
        if (s == null) {
            System.out.println("S es nulo");
            finish();
            moveTaskToBack(true);
        }
        */
        jtv.append("\nEstado Actual: " + s);
        r   = Environment.getExternalStorageDirectory();// Directorio en tarjeta SD.
        d   = new File(r.getAbsolutePath() + "/datos"); // Crea carpeta datos en SD.
        d.mkdirs();
        jtv.append("\n\nNueva Carpeta: " + d + "\n\nContenido de la Carpeta " + r + ":");
        String [] lista = r.list();
        for(int i=0; i<lista.length; i++)
            jtv.append("\n" + lista[i]);
        f = new File(d, "misdatos.txt");                  // Abre datos1.txt en carpeta datos.
        try{
            fos = new FileOutputStream(f);
            pw  = new PrintWriter(fos);
            pw.println("Inicio del arhivo");            // Escribe cadena en datos1.txt.
            pw.flush();
            pw.close();
            jtv.append("\n\n Archivo: " + f + "\nGuardado.");
        }catch (FileNotFoundException fnfe){
            fnfe.printStackTrace();;
            jtv.append("\n\nEXCEPTION:\n" + fnfe);
        }
    }
}
