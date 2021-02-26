package com.example.listviewej1;

import java.util.ArrayList;
import android.content.Context;
import android.view.*;
import android.widget.BaseAdapter;

public abstract class ListaAdapter extends BaseAdapter {

    private ArrayList<?> al;
    private int R_layout_IdView;
    private Context c;

    public ListaAdapter(Context c, int R_layout_IdView, ArrayList<?> al) {
        super();
        this.c = c;
        this.al = al;
        this.R_layout_IdView = R_layout_IdView;
    }

    public View getView(int i, View v, ViewGroup vg) {
        if (v == null) {
            LayoutInflater vi = (LayoutInflater) c.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            v = vi.inflate(R_layout_IdView, null);
        }
        onEntrada (al.get(i), v);
        return v;
    }

    public int getCount() {
        return al.size();
    }

    public Object getItem(int j) {
        return al.get(j);
    }

    public long getItemId(int k) {
        return k;
    }

    public abstract void onEntrada (Object o, View v);
}
