
#ifndef PROYECTO_CRUZA_H
#define PROYECTO_CRUZA_H


#include "Sujeto.h"
#include "Funciones.h"

Funciones funciones;
Poblacion poblacion;

class Cruza {

public:
    std::vector<Sujeto> un_punto(std::vector<Sujeto> aux_in,int f_tam,std::vector<int> f_mask);
    std::vector<Sujeto> n_puntos(std::vector<Sujeto> aux_in,int f_tam,std::vector<int> f_mask);
    std::vector<Sujeto> uniforme(std::vector<Sujeto> aux_in,int f_tam,std::vector<int> f_mask);
};

std::vector<Sujeto> mask(std::vector<int> p_1,std::vector<int> p_2,std::vector<int> f_mask){
    std::vector<Sujeto> aux_out;
    Sujeto s_h1;
    Sujeto s_h2;
    std::vector<int> a_h1;
    std::vector<int> a_h2;
    bool aux_b = true;
    for(int i=0 ; i <= f_mask.size()-1 ; i++){
        if(aux_b){
            if(f_mask[i]==0){
                a_h1.push_back(p_1[i]);
                a_h2.push_back(p_2[i]);
            }else{
                a_h1.push_back(p_2[i]);
                a_h2.push_back(p_1[i]);
                aux_b = false;
            }
        }else{
            if(f_mask[i]==1){
                a_h1.push_back(p_2[i]);
                a_h2.push_back(p_1[i]);
            }else{
                a_h1.push_back(p_1[i]);
                a_h2.push_back(p_2[i]);
                aux_b = true;
            }
        }
    }

    s_h1.set_alelo(a_h1);
    s_h1.set_id(0);
    s_h1.set_valor(0);
    s_h1.set_fitnes(0);

    s_h2.set_alelo(a_h2);
    s_h2.set_id(0);
    s_h2.set_valor(0);
    s_h2.set_fitnes(0);

    aux_out.push_back(s_h1);
    aux_out.push_back(s_h2);
    return aux_out;
}


std::vector<Sujeto> Cruza::un_punto(std::vector<Sujeto> aux_in, int f_tam, std::vector<int> f_mask) {
    std::vector<Sujeto> aux_out;
    std::vector<int> aux_mask;

    for(int i=0 ; i <= f_tam ; i++){
        if(i==f_mask[0]-1) aux_mask.push_back(1);
        else aux_mask.push_back(0);
    }

    aux_out = mask(aux_in[0].get_alelo(),aux_in[1].get_alelo(),aux_mask);

    return aux_out;
}

std::vector<Sujeto> Cruza::n_puntos(std::vector<Sujeto> aux_in, int f_tam, std::vector<int> f_mask) {
    std::vector<Sujeto> aux_out;
    std::vector<int> aux_mask;

    for(int i=0 ; i <= f_tam ; i++){
        if( i==f_mask[0]-1 || i==f_mask[1]-1 || i==f_mask[2]-1) aux_mask.push_back(1);
        else aux_mask.push_back(0);
    }

    aux_out = mask(aux_in[0].get_alelo(),aux_in[1].get_alelo(),aux_mask);

    return aux_out;
}

std::vector<Sujeto> Cruza::uniforme(std::vector<Sujeto> aux_in, int f_tam, std::vector<int> f_mask) {
    std::vector<Sujeto> aux_out;
    std::vector<int> aux_mask;
    Sujeto s_h1;
    Sujeto s_h2;
    std::vector<int> a_h1;
    std::vector<int> a_h2;

    for(int i=0 ; i <= f_tam-1 ; i++){
        if( i==f_mask[0]-1 || i==f_mask[1]-1 || i==f_mask[2]-1) aux_mask.push_back(1);
        else aux_mask.push_back(0);
    }

    for(int i=0 ; i <= aux_mask.size()-1 ; i++){
        if(f_mask[i]==1){
            a_h1.push_back(aux_in[0].get_alelo()[i]);
            a_h2.push_back(aux_in[1].get_alelo()[i]);
        }else{
            a_h1.push_back(aux_in[1].get_alelo()[i]);
            a_h2.push_back(aux_in[0].get_alelo()[i]);
        }
    }

    s_h1.set_alelo(a_h1);
    s_h1.set_id(0);
    s_h1.set_valor(0);
    s_h1.set_fitnes(0);

    s_h2.set_alelo(a_h2);
    s_h2.set_id(0);
    s_h2.set_valor(0);
    s_h2.set_fitnes(0);

    aux_out.push_back(s_h1);
    aux_out.push_back(s_h2);

    return aux_out;
}

#endif //PROYECTO_CRUZA_H
