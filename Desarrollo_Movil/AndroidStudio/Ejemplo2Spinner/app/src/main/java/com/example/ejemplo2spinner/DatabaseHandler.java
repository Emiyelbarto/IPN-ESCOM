package com.example.ejemplo2spinner;

import java.util.*;
import android.content.*;
import android.database.Cursor;
import android.database.sqlite.*;

public class DatabaseHandler extends SQLiteOpenHelper {
    private static final int DATABASE_VERSION = 1;
    private static final String DATABASE_NAME = "EjemploDeSpinner";
    private static final String TABLE_LABELS = "nombres";
    private static final String KEY_ID = "id";
    private static final String KEY_NAME = "nombre";
    public DatabaseHandler(Context c) {
        super(c, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String CREATE_CATEGORIES_TABLE = "CREATE TABLE " + TABLE_LABELS + "(" + KEY_ID +       " INTEGER PRIMARY KEY," + KEY_NAME + " TEXT)";
        db.execSQL(CREATE_CATEGORIES_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_LABELS);
        onCreate(db);
    }

    public void insertLabel(String s){
        SQLiteDatabase  db = this.getWritableDatabase();
        ContentValues   cv = new ContentValues();
        cv.put(KEY_NAME, s);
        db.insert(TABLE_LABELS, null, cv);
        db.close();
    }

    public List<String> getAllLabels(){
        List<String> l = new ArrayList<String>();
        String q = "SELECT  * FROM " + TABLE_LABELS;
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor c = db.rawQuery(q, null);

        if (c.moveToFirst()) {
            do {
                l.add(c.getString(1));
            } while (c.moveToNext());
        }
        c.close();
        db.close();
        return l;
    }
}