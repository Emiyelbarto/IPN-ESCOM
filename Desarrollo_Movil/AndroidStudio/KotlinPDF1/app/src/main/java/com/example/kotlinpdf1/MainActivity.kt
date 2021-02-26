package com.example.kotlinpdf1

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val input = findViewById<EditText>(R.id.editText)
        val btnComprobar = findViewById<Button>(R.id.btnComprobar)

        btnComprobar.setOnClickListener {
            if(input.text.toString() != "")
            {
                Toast.makeText(this,"Valor no es nulo", Toast.LENGTH_LONG).show()
            }
            else if(input.text.toString() == "")
            {
                Toast.makeText(this,"Valor es nulo", Toast.LENGTH_LONG).show()
            }
        }
    }
}
