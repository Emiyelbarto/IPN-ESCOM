package com.example.dbmssqllite1;

import android.os.Bundle;
import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity {
    EditText        jetI, jetN;
    Button          jbnA, jbnL, jbnU, jbnD;
    TextView        jtvL;
    SQLiteDatabase  sqld;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jetI = (EditText)   findViewById(R.id.xetI);
        jetN = (EditText)   findViewById(R.id.xetN);
        jbnA = (Button)     findViewById(R.id.xbnA);
        jbnL = (Button)     findViewById(R.id.xbnL);
        jbnU = (Button)     findViewById(R.id.xbnU);
        jbnD = (Button)     findViewById(R.id.xbnD);
        jtvL = (TextView)   findViewById(R.id.xtvL);

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBContactos", null, 1);
        sqld = dsqlh.getWritableDatabase();

        jbnA.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String          id = jetI.getText().toString();
                String          nombre = jetN.getText().toString();
                ContentValues   cv = new ContentValues();
                cv.put("id", id);
                cv.put("nombre", nombre);
                sqld.insert("Contactos", null, cv);
                jetI.setText("");
                jetN.setText("");
            }
        });

        jbnL.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id, nombre;
                Cursor c = sqld.rawQuery("SELECT id,nombre FROM Contactos", null);
                jtvL.setText("");
                if (c.moveToFirst()) {
                    do {
                        id = c.getString(0);
                        nombre = c.getString(1);
                        jtvL.append(" " + id + "\t" + nombre + "\n");
                    } while(c.moveToNext());
                }
            }
        });

        jbnD.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String          id = jetI.getText().toString();
                String DelQuery = "DELETE FROM Contactos WHERE id = "+id;
                sqld.execSQL(DelQuery);
                jetI.setText("");
                jetN.setText("");
            }
        });

        jbnU.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String          id = jetI.getText().toString();
                String          nombre = jetN.getText().toString();
                String DelQuery = "UPDATE Contactos SET nombre = '" + nombre + "' WHERE id = " + id;
                sqld.execSQL(DelQuery);
                jetI.setText("");
                jetN.setText("");
            }
        });
    }
}