package com.example.kotlinpdf2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnScan = findViewById<Button>(R.id.btnVerif)
        val input = findViewById<EditText>(R.id.input)
        var b: String? = "NULO"
        btnScan.setOnClickListener {
            if (input.text.toString() == ""){
                b = null
                Toast.makeText(this,"El valor es nulo pero muestra: " + b, Toast.LENGTH_LONG).show()
            }
            else{
                b = input.text.toString()
                Toast.makeText(this,"El valor no es nulo pero muestra: " + b, Toast.LENGTH_LONG).show()
            }
        }
    }
}
