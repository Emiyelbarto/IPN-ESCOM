#ifndef PROYECTO_FUNCIONES_H
#define PROYECTO_FUNCIONES_H
#include <vector>
#include <iostream>
#include <math.h>
#include "Sujeto.h"


class Funciones {
private:
    std::vector<int> aux_bin;
    std::vector<int> aux_gray;
public:
    int get_tam_alelo(int f_maximo);
    bool repetido(int f_num, std::vector<int> f_arreglo);
    std::string imprimir_arreglo(std::vector<int> f_arreglo);
    std::vector<int> convertir_binario(int f_valor,int tam_alelo);
    std::vector<int> convertir_gray(int f_valor,int tam_alelo);
    void graficar(std::vector<Sujeto> f_poblacion);
};

int Funciones::get_tam_alelo(int f_maximo) {
    int aux=0;
    for(int i=0 ; i < 64 ; i++){
        f_maximo = f_maximo / 2;
        aux++;
        if(f_maximo == 0) break;
    }
    return  aux;
}

bool Funciones::repetido(int f_num, std::vector<int> f_arreglo) {
    bool aux_b= false;
    for(int i = 0 ; i <= f_arreglo.size()-1 ; i++){
        if (f_num == f_arreglo[i]) {
            aux_b = true;
            break;
        }
    }
    return aux_b;
}

std::string Funciones::imprimir_arreglo(std::vector<int> f_arreglo) {
    std::string aux="";
    if(!f_arreglo.empty()){
        for(int i = 0 ; i <= f_arreglo.size()-1 ; i++){
            if( i == f_arreglo.size()-1 )aux += std::to_string(f_arreglo[i]);
            else aux += std::to_string(f_arreglo[i]) += "-";
        }
    }
    return aux += "\n";
}

std::vector<int> Funciones::convertir_binario(int f_valor,int tam_alelo) {
    aux_bin.clear();
    for(int i = 0 ; i <= tam_alelo-1 ; i++){
        aux_bin.push_back(f_valor % 2);
        f_valor = f_valor / 2;
    }
    return aux_bin;
}

std::vector<int> Funciones::convertir_gray(int f_valor,int tam_alelo) {
    aux_gray.clear();
    std::vector<int> f_binario = convertir_binario(f_valor,tam_alelo);

    for(int i = 0 ; i <= tam_alelo-1 ; i++){
        if(i == 0) aux_gray.push_back(f_binario[i]);
        else{
            if((f_binario[i-1] == 1 && f_binario[i] == 1 ) || (f_binario[i-1] == 0 && f_binario[i] == 0 )) aux_gray.push_back(0);
            else aux_gray.push_back(1);
        }
    }

    return aux_gray;
}

void Funciones::graficar(std::vector<Sujeto> f_poblacion) {
    int max=0;
    float pon;
    int aux_a,aux_b;
    std::string aux_s;
    for(int i = 0 ; i <= f_poblacion.size() ; i++){
        if(f_poblacion[i].get_fitnes() > max){
            max = f_poblacion[i].get_fitnes();
        }
    }

    for(int i = 0 ; i <= 100 ; i++) {
        if (i == 0) {
            std::cout << "\t    " << i;
        } else if (i % 10 == 0) {
            std::cout << i / 10;
        } else {
            std::cout << "-";
        }
    }
    std::cout << "\n";

    pon =(float) 100/max;
    max=0;

    for(int i=0 ; i<= f_poblacion.size()-1 ; i=i+2){
        aux_a = ceil(pon * (f_poblacion[i].get_fitnes())) ;
        aux_b = ceil(pon * (f_poblacion[i+1].get_fitnes())) ;
        for(int j = 0 ; j <= 100 ; j++){
            if(j == 0){
                std::cout << "Poblacion: " << max <<"|";
            } else{
                if(j ==  aux_a) std::cout << ">";
                if(j == aux_b) std::cout << "<";
                if(j >= aux_b && j < aux_a)std::cout << "-";
                else std::cout << " ";
            }
        }
        std::cout << "\n";
        max++;
    }

}

#endif //PROYECTO_FUNCIONES_H
