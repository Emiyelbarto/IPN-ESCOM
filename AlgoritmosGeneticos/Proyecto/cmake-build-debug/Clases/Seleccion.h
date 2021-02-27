#ifndef PROYECTO_SELECCION_H
#define PROYECTO_SELECCION_H


#include <vector>
#include <iostream>
#include "Poblacion.h"
#include "Sujeto.h"

class Seleccion {
public:
    std::vector<Sujeto> ruleta(std::vector<Sujeto> aux_in,int f_cantidad,std::vector<float> f_probabilidad);
    std::vector<Sujeto> jerarquico(std::vector<Sujeto> aux_in,int f_cantidad,std::vector<float> f_probabilidad);
    std::vector<Sujeto> torneo(std::vector<Sujeto> aux_in,int f_cantidad,std::vector<int> f_orden);
};

std::vector<Sujeto> Seleccion::ruleta(std::vector<Sujeto> aux_in, int f_cantidad, std::vector<float> f_probabilidad) {
    std::vector<Sujeto> aux_out;
    std::vector<float> probabilidad_seleccion;
    int aux_max=0,aux_media;
    float aux_ponderacion,aux_suma;

    for(int i=0 ; i<=aux_in.size()-1 ; i++){
        aux_max = aux_max + aux_in[i].get_fitnes();
    }
    aux_media = aux_max/aux_in.size();
    aux_ponderacion =(float) 1 / aux_max;

    for(int i=0 ; i<=aux_in.size()-1 ; i++){
        probabilidad_seleccion.push_back(aux_ponderacion*aux_in[i].get_fitnes());
    }

    for(int i=0 ; i<=f_cantidad-1 ; i++){
        aux_ponderacion = f_probabilidad[i];
        aux_suma = 0;
        for(int j=0 ; j<=probabilidad_seleccion.size()-1 ; j++){
            if(aux_ponderacion <= probabilidad_seleccion[j]+aux_suma){
                aux_out.push_back(aux_in[j]);
                break;
            }else aux_suma = aux_suma + probabilidad_seleccion[j];
        }
    }

    return aux_out;
}

std::vector<Sujeto> Seleccion::jerarquico(std::vector<Sujeto> aux_in, int f_cantidad, std::vector<float> f_probabilidad) {
    std::vector<Sujeto> aux_out;
    Sujeto aux_sujeto;

    for(int i = 0 ; i <= aux_in.size()-1 ; i++){
        for(int j = 0 ; j <= aux_in.size()-1 ; j++){
            if(aux_in[j].get_valor() < aux_in[j+1].get_valor()){
                aux_sujeto = aux_in[j];
                aux_in[j] = aux_in[j+1];
                aux_in[j+1] = aux_sujeto;
            }
        }
    }

    aux_out = ruleta(aux_in,f_cantidad,f_probabilidad);

    return aux_out;
}

std::vector<Sujeto> Seleccion::torneo(std::vector<Sujeto> aux_in, int f_cantidad, std::vector<int> f_orden) {
    std::vector<Sujeto> aux_out;
    std::vector<Sujeto> aux_torneo;

    for(int i=0; i <= f_cantidad ; i++){
        if(  f_cantidad <= aux_out.size()) break;
        for(int j=0 ; j <= aux_in.size()-1 ; j++){
            aux_torneo.push_back(aux_in[f_orden[(i*aux_in.size())+j]]);
        }
        for(int j=0 ; j <= aux_torneo.size()-1 ; j = j+2){
            if(aux_torneo[j].get_valor() > aux_torneo[j+1].get_valor()) aux_out.push_back(aux_torneo[j]);
            else aux_out.push_back(aux_torneo[j+1]);
        }
        aux_torneo.clear();
    }

    return aux_out;
}

#endif //PROYECTO_SELECCION_H
