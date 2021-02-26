package com.example.ejemplo2fragmentos;

import android.app.*;
import android.os.*;
import android.view.*;
import android.view.View.OnClickListener;
import android.widget.*;

public class MiFragmento extends Fragment {
    public final static int OK      = 0;
    public final static int CANCEL  = 1;
    private FragmentoListener fl;

    @Override
    public void onAttach(Activity a) {
        super.onAttach(a);
        if (a instanceof FragmentoListener) {
            fl = (FragmentoListener) a;
        }
    }

    public interface FragmentoListener {
        public void digitado(int resultado, String texto);
    }

    @Override
    public View onCreateView(LayoutInflater li, ViewGroup vg, Bundle b) {
        View v = li.inflate(R.layout.activity_mifragmento, vg, false);

        ((Button) v.findViewById(R.id.xbnA)).setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                botonDigitado(v);
                Toast.makeText(getActivity(), "Desde MiFragmento", Toast.LENGTH_LONG).show();
            }
        });

        ((Button) v.findViewById(R.id.xbnC)).setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                botonDigitado(v);
            }
        });

        return v;
    }

    public void botonDigitado(View v) {
        if (null == fl)
            return;
        if (((Button) v).getText().equals("Aceptar"))
            fl.digitado(OK, ((EditText) getActivity().findViewById(R.id.xet)).getText().toString());
        else
            fl.digitado(CANCEL, "");
    }
}
