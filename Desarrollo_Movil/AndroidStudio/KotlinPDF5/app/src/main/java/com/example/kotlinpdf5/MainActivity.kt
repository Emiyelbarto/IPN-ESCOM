package com.example.kotlinpdf5

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.widget.Button
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnMostrar = findViewById<Button>(R.id.btnMostrar)

        btnMostrar.setOnClickListener {

            val layoutInflater:LayoutInflater = LayoutInflater.from(applicationContext)

            // Inflate the layout using LayoutInflater
            val view: View = layoutInflater.inflate(
                R.layout.inflatable_main, // Custom view/ layout
                root_layout, // Root layout to attach the view
                false // Attach with root layout or not
            )

            // Find the text view from custom layout
            val label = view.findViewById<TextView>(R.id.textViewInflado)

            // Set the text of custom view's text view widget
            label.text = "Mensaje invocado desde inflater."

            // Finally, add the view/custom layout to the activity root layout
            root_layout.addView(view,0)
        }

    }
}
