package com.example.kotlinpdf3

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnScan = findViewById<Button>(R.id.inputBtn)
        val input = findViewById<EditText>(R.id.input)

        btnScan.setOnClickListener {
            val a = input.text!!.length
            Toast.makeText(this,"La cadena mide: " + a, Toast.LENGTH_LONG).show()
        }
    }
}
