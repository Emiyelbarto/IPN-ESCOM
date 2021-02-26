package com.example.proyecto1;

public class ListaEntrada {

    private int idim;
    private String a;
    private String d;

    public ListaEntrada (int idI, String sa, String sd) {
        this.idim = idI;
        this.a = sa;
        this.d = sd;
    }

    public String get_textoEncima() {
        return a;
    }

    public String get_textoDebajo() {
        return d;
    }

    public int get_idImagen() {
        return idim;
    }
}