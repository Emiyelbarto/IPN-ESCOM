package com.example.kotlinpdf6

import android.content.Context
import android.widget.Toast

object MessageSingleton {
    fun show(c : Context) {
        Toast.makeText(c,"Soy un singleton", Toast.LENGTH_LONG).show()
    }
}
