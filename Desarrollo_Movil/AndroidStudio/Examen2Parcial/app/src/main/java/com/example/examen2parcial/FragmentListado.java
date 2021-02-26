package com.example.examen2parcial;

import android.app.Activity;

import android.os.Bundle;
import android.view.*;
import android.widget.AdapterView.*;
import android.widget.*;
import androidx.fragment.app.Fragment;

public class FragmentListado extends Fragment {
    private Grupo[] datos = new Grupo[]{
            new Grupo("\nVector 1", "Valores 1", "\nValor vector 1 :"),
            new Grupo("\nVector 2", "Valores 2", "\nValor vector 2 :"),
            new Grupo("\nVector 3", "Valores 3", "\nValor vector 3 :")
    };

    private ListView lv;
    private GruposListener cl;

    @Override
    public View onCreateView(LayoutInflater li, ViewGroup vg, Bundle b) {
        return li.inflate(R.layout.fragment_listado, vg, false);
    }

    @Override
    public void onActivityCreated(Bundle b) {
        super.onActivityCreated(b);
        lv = (ListView)getView().findViewById(R.id.xlvListado);
        lv.setAdapter(new AdaptadorGrupos(this));
        lv.setOnItemClickListener(new OnItemClickListener() {

            @Override
            public void onItemClick(AdapterView<?> list, View v, int pos, long id) {
                if (cl!=null) {
                    cl.onGrupoSeleccionado((Grupo) lv.getAdapter().getItem(pos));
                }
            }
        });
    }

    class AdaptadorGrupos extends ArrayAdapter<Grupo> {
        Activity a;
        TextView tv1, tv2;
        AdaptadorGrupos(Fragment f) {
            super(f.getActivity(), R.layout.listitem_grupo, datos);
            this.a = f.getActivity();
        }

        public View getView(int i, View vi, ViewGroup vg) {
            LayoutInflater li = a.getLayoutInflater();
            View v = li.inflate(R.layout.listitem_grupo, null);
            tv1 = (TextView)v.findViewById(R.id.xtvDe);
            tv1.setText(datos[i].getDe());
            tv2 = (TextView)v.findViewById(R.id.xtvAsunto);
            tv2.setText(datos[i].getAsunto());
            return(v);
        }
    }

    public interface GruposListener {
        void onGrupoSeleccionado(Grupo c);
    }

    public void setGruposListener(GruposListener l) {
        this.cl=l;
    }
}