package com.example.ejemplo3fragment;

public class Grupo{
    private String de, asunto,texto;
    public Grupo(String de, String as, String te){
        this.de = de;
        this.asunto = as;
        this.texto = te;
    }

    public String getDe(){
        return de;
    }

    public String getAsunto(){
        return asunto;
    }

    public String getTexto(){
        return texto;
    }
}
