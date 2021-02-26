package com.example.cuadrado;

import android.content.Context;
import android.opengl.Matrix;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

import java.util.List;

public class MatrixAdapter extends BaseAdapter {
    Context context;
    List<Matrix> matrixList;

    public MatrixAdapter(Context context, List<Matrix> matrixList) {
        this.context = context;
        this.matrixList = matrixList;
    }

    @Override
    public int getCount() {
        return matrixList.size();
    }

    @Override
    public Object getItem(int i) {
        return matrixList.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        View v;
        v = View.inflate(context,R.layout.griditem,null);
        return v;
    }
}
