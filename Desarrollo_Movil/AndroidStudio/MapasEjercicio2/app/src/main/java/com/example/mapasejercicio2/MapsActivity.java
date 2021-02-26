package com.example.mapasejercicio2;

import android.Manifest;
import android.annotation.SuppressLint;
import android.content.Context;
import android.content.pm.PackageManager;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.annotation.RequiresApi;
import androidx.fragment.app.FragmentActivity;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;
    private EditText edtLatitud;
    private EditText edtLongitud;
    private EditText edtPrecision;
    private EditText edtProveedor;
    private Button btnActivar;
    private Button btnDesactivar;
    private Location currentBestLocation = null;
    private Location mLocationManager = null;
    static final int TWO_MINUTES = 1000 * 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        edtLatitud = (EditText) findViewById(R.id.Latitud);
        edtLongitud = (EditText) findViewById(R.id.Longitud);
        edtPrecision = (EditText) findViewById(R.id.Precision);
        edtProveedor = (EditText) findViewById(R.id.Proveedor);
        btnActivar = (Button) findViewById(R.id.BtnActivar);
        btnDesactivar = (Button) findViewById(R.id.BtnDesactivar);
        edtLatitud.setEnabled(false);
        edtLongitud.setEnabled(false);
        edtPrecision.setEnabled(false);
        edtProveedor.setEnabled(false);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
        btnDesactivar.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                edtLatitud.setText("Latitud:");
                edtLongitud.setText("Longitud:");
                edtPrecision.setText("Precision:");
                edtProveedor.setText("Provider Status: " + 0);
                mMap.setMyLocationEnabled(false);
                mMap.clear();
            }
        });

        btnActivar.setOnClickListener(new View.OnClickListener() {
            @SuppressLint("MissingPermission")
            @RequiresApi(api = Build.VERSION_CODES.M)
            public void onClick(View v) {
                mMap.setMyLocationEnabled(true);
                LocationManager locationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
                Criteria criteria = new Criteria();
                String provider = locationManager.getBestProvider(criteria,true);
                Location location = locationManager.getLastKnownLocation(provider);
                if(location == null)
                    onLocationChange(location);
                MyCurrentLoctionListener locationListener = new MyCurrentLoctionListener();
                locationManager.requestLocationUpdates(provider, 3000, 0, locationListener);
                edtLatitud.setText("Latitud: " + location.getLatitude());
                edtLongitud.setText("Longitud: " + location.getLongitude());
                edtPrecision.setText("Precision: " + 0.0);
                edtProveedor.setText("Provider Status: " + 1);
                LatLng marker = new LatLng(location.getLatitude(),location.getLongitude());
                mMap.addMarker(new MarkerOptions().position(marker).title("Marcador en mi ubicacion actual"));
                mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(marker,12f));
            }
        });
    }

    public void onLocationChange(Location location)
    {
        double latitude = location.getLatitude();
        double longitud = location.getLongitude();
        LatLng latLng = new LatLng(latitude, longitud);
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        // Add a marker in Sydney and move the camera
    }

}
