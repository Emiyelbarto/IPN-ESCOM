package com.example.listviewej1;

    import java.util.ArrayList;
    import android.app.Activity;
    import android.os.Bundle;
    import android.view.View;
    import android.widget.AdapterView.OnItemClickListener;
    import android.widget.*;

    public class MainActivity extends Activity {
        private ListView lv;
        protected void onCreate(Bundle b) {
            super.onCreate(b);
            setContentView(R.layout.listado);
            ArrayList<ListaEntrada> al = new ArrayList<ListaEntrada>();
            al.add(new ListaEntrada(R.drawable.buho,
                    "BUHO", "Búho es el nombre común de aves de la familia Strigidae, del orden de las estrigiformes o aves rapaces nocturnas. Habitualmente designa especies que, a diferencia de las lechuzas, tienen plumas alzadas que parecen orejas."));
            al.add(new ListaEntrada(R.drawable.colibri,
                    "COLIBRÍ", "Los troquilinos (Trochilinae) son una subfamilia de aves apodiformes de la familia Trochilidae, conocidas vulgarmente como colibríes, quindes, tucusitos, picaflores, chupamirtos, chuparrosas, huichichiquis (idioma nahuatl), mainumby (idioma guaraní) o guanumby."));
            al.add(new ListaEntrada(R.drawable.cuervo,
                    "CUERVO", "El cuervo común (Corvus corax) es una especie de ave paseriforme de la familia de los córvidos (Corvidae). Presente en todo el hemisferio septentrional, es la especie de córvido con la mayor superficie de distribución."));
            al.add(new ListaEntrada(R.drawable.flamenco,
                    "FLAMENCO", "Los fenicopteriformes (Phoenicopteriformes), los cuales reciben el nombre vulgar de flamencos, son un orden de aves neognatas, con un único género viviente: Phoenicopterus."));
            al.add(new ListaEntrada(R.drawable.kiwi,
                    "KIWI", "Los kiwis (Apterix, gr. 'sin alas') son un género de aves paleognatas compuesto por cinco especies endémicas de Nueva Zelanda.1 2 Son aves no voladoras pequeñas, aproximadamente del tamaño de una gallina."));
            al.add(new ListaEntrada(R.drawable.loro,
                            "LORO", "Las Psitácidas (Psittacidae) son una familia de aves psitaciformes llamadas comúnmente loros o papagayos, e incluye a los guacamayos, las cotorras, los periquitos, los agapornis y formas afines."));
            al.add(new ListaEntrada(R.drawable.pavo,
                    "PAVO", "Pavo es un género de aves galliformes de la familia Phasianidae, que incluye dos especies, el pavo real común (Pavo cristatus) y el pavo real cuelliverde (Pavo muticus).1"));
            al.add(new ListaEntrada(R.drawable.pinguino,
                    "PINGÜINO", "Los pingüinos (familia Spheniscidae, orden Sphenisciformes) son un grupo de aves marinas, no voladoras, que se distribuyen únicamente en el Hemisferio Sur, sobre todo en sus altas latitudes."));

            lv = (ListView) findViewById(R.id.xlv_listado);

            lv.setAdapter(new ListaAdapter(this, R.layout.activity_main, al){
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
                    Toast t = Toast.makeText(MainActivity.this, cs, Toast.LENGTH_SHORT);
                    t.show();
                }
            });
        }
    }