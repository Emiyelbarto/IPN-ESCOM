package com.example.mapasejercicio1;

import android.content.Context;
import android.graphics.Camera;
import android.graphics.Color;
import android.graphics.Path;
import android.media.midi.MidiManager;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.MainThread;
import androidx.fragment.app.FragmentActivity;

import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.Circle;
import com.google.android.gms.maps.model.CircleOptions;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.vision.barcode.Barcode;
import com.google.android.gms.maps.MapView;

import static android.widget.Toast.LENGTH_SHORT;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;
    private MapView mv;
    private Button btnSatelite;
    private Button btnMover;
    private Button btnAnimar;
    private Button btnCentrar;
    Marker CurrentMarker = null;
    private static int flag = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        final SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        btnSatelite = (Button) findViewById(R.id.satellite);
        btnMover = (Button) findViewById(R.id.mover);
        btnAnimar = (Button) findViewById(R.id.animar);
        btnCentrar = (Button) findViewById(R.id.centrar);
        mapFragment.getMapAsync(this);


        btnSatelite.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (flag == 0) {
                    mMap.setMapType(mMap.MAP_TYPE_SATELLITE);
                    flag = 1;
                } else {
                    mMap.setMapType(mMap.MAP_TYPE_NORMAL);
                    flag = 0;
                }
            }
        });

        btnCentrar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LatLng Casa = new LatLng(37.40, -5.99); // new LatLng(37.40*1E6, -5.99*1E6);
                mMap.clear();
                Circle circle = mMap.addCircle(new CircleOptions()
                        .center(new LatLng(37.40, -5.99))
                        .radius(1000)
                        .strokeColor(Color.RED)
                        .fillColor(Color.RED));
                //mMap.addMarker(new MarkerOptions().position(new LatLng(37.4, -5.99)).title("Sevilla"));
                mMap.addMarker(new MarkerOptions().position(Casa).title("Sevilla"));
                mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(Casa, 12f));
            }
        });

        btnAnimar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LatLng SixFlags = new LatLng(19.295616, -99.210565); // 19.295616, -99.210565
                CameraUpdate location = CameraUpdateFactory.newLatLngZoom(SixFlags, 15);
                mMap.animateCamera(location);
                mMap.clear();
                Circle circle = mMap.addCircle(new CircleOptions()
                        .center(new LatLng(37.40, -5.99))
                        .radius(1000)
                        .strokeColor(Color.RED)
                        .fillColor(Color.RED));
                mMap.addMarker(new MarkerOptions().position(new LatLng(37.4, -5.99)).title("Sevilla"));
                mMap.addMarker(new MarkerOptions().position(SixFlags).title("Six Flags Mexico"));
            }
        });


        btnMover.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                CameraUpdate scroll = CameraUpdateFactory.scrollBy(400, 400);
                mMap.animateCamera(scroll);
            }
        });

    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        Marker MarcadorSevilla;
        MarkerOptions OpcionesSevilla = new MarkerOptions().position(new LatLng(37.4, -5.99)).title("Sevilla");
        Circle circle = mMap.addCircle(new CircleOptions()
                .center(new LatLng(37.40, -5.99))
                .radius(1000)
                .strokeColor(Color.RED)
                .fillColor(Color.RED));
        MarcadorSevilla = mMap.addMarker(OpcionesSevilla);
        mMap.setOnMarkerClickListener(new GoogleMap.OnMarkerClickListener() {
            @Override
            public boolean onMarkerClick(Marker marker) {
                Context context = getApplicationContext();
                String msg = "Lat: "+ 37.4000 + "-" + "Lon: " + -5.999 + "\n";
                Toast toast = Toast.makeText(context,msg, LENGTH_SHORT);
                toast.show();
                return true;
            }
        });
    }

}
