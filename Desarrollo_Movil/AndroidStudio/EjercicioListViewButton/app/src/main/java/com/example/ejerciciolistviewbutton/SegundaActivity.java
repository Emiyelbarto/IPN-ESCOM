package com.example.ejerciciolistviewbutton;

import java.util.ArrayList;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.*;

public class SegundaActivity extends Activity {
    private ListView lv;
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.listado);
        ArrayList<ListaEntrada> al = new ArrayList<ListaEntrada>();
        al.add(new ListaEntrada(R.drawable.wunder,
                "WUNDER", "Martin Wunder Nordahl Hansen is the top laner for G2 Esports. He was previously known as Wunderwear."));
        al.add(new ListaEntrada(R.drawable.jankos,
                "JANKOS", "Marcin Jankos Jankowski is the jungler for G2 Esports."));
        al.add(new ListaEntrada(R.drawable.caps,
                "CAPS", "Rasmus \"Caps\" Borregaard Winther is the mid laner for G2 Esports."));
        al.add(new ListaEntrada(R.drawable.perkz,
                "PERKZ", "Luka \"Perkz\" Perković is the bot laner for G2 Esports. His name was previously stylized PerkZ."));
        al.add(new ListaEntrada(R.drawable.mikyx,
                "MIKYX", "Mihael \"Mikyx\" Mehle is the support for G2 Esports."));
        al.add(new ListaEntrada(R.drawable.promisq,
                "PROMISQ", "Hampus Mikael \"promisq\" Abrahamsson is a substitute support for G2 Esports. He was previously known as sprattel."));
        al.add(new ListaEntrada(R.drawable.ocelote,
                "OCELOTE", "Carlos \"ocelote\" Rodríguez Santiago is a retired mid laner who is known for playing on SK Gaming. He is the founder of Gamers2, now G2 Esports."));

        lv = (ListView) findViewById(R.id.xlv_listado);

        lv.setAdapter(new ListaAdapter(this, R.layout.activity_segunda, al){
            public void onEntrada(Object o, View v) {
                if (o != null) {
                    TextView texto_superior_entrada = (TextView) v.findViewById(R.id.textView_superior);
                    if (texto_superior_entrada != null)
                        texto_superior_entrada.setText(((ListaEntrada) o).get_textoEncima());
                    TextView texto_inferior_entrada = (TextView) v.findViewById(R.id.textView_inferior);
                    if (texto_inferior_entrada != null)
                        texto_inferior_entrada.setText(((ListaEntrada) o).get_textoDebajo());
                    ImageView imagen_entrada = (ImageView) v.findViewById(R.id.imageView_imagen);
                    if (imagen_entrada != null)
                        imagen_entrada.setImageResource(((ListaEntrada) o).get_idImagen());
                }
            }
        });

        lv.setOnItemClickListener(new OnItemClickListener() {
            public void onItemClick(AdapterView<?> av, View view, int i, long l) {
                ListaEntrada le = (ListaEntrada) av.getItemAtPosition(i);
                CharSequence cs = "Seleccionado: " + le.get_textoDebajo();
                Toast t = Toast.makeText(SegundaActivity.this, cs, Toast.LENGTH_SHORT);
                t.show();
            }
        });
    }
}