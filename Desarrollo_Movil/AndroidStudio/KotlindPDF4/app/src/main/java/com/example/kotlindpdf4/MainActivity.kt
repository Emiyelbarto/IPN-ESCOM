package com.example.kotlindpdf4

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val btn = findViewById<Button>(R.id.btnPrincipal)

        btn.setOnClickListener {
            Toast.makeText(this,"SOY UN LISTENER DE UNA LINEA! LAMBDA!", Toast.LENGTH_LONG).show()
        }
    }
}
