package com.example.kotlinpdf6

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btn = findViewById<Button>(R.id.btnPrincipal)

        btn.setOnClickListener {
            Toast.makeText(this,"soy un singleton invocado!",Toast.LENGTH_LONG).show()
        }
    }

}