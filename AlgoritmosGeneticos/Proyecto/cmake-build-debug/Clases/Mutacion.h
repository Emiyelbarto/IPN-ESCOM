#ifndef PROYECTO_MUTACION_H
#define PROYECTO_MUTACION_H

#include <vector>

class Mutacion {
public:
    std::vector<int> insercion(std::vector<int> f_alelo,std::vector<int> f_posicion);
    std::vector<int> desplazamiento(std::vector<int> f_alelo,std::vector<int> f_posicion);
    std::vector<int> intercambio(std::vector<int> f_alelo,std::vector<int> f_posicion);
};

std::vector<int> Mutacion::insercion(std::vector<int> f_alelo, std::vector<int> f_posicion) {
    std::vector<int> aux_out;

    if(f_posicion[0] < f_posicion[1]){
        int aux_int = f_posicion[1];
        f_posicion[1] = f_posicion[0];
        f_posicion[0] = aux_int;
    }

    if(f_posicion[1] == f_posicion[0])return f_alelo;

    bool aux_bool = true;

    for(int i=0 ; i <= f_alelo.size()-1 ; i++){
        if(aux_bool){
            if ( i == f_posicion.at(1)){
                aux_out.push_back(f_alelo[f_posicion[0]]);
                aux_out.push_back(f_alelo[i]);
                aux_bool = false;
            }else{
                aux_out.push_back(f_alelo[i]);
            }
        }else{
            if ( i != f_posicion.at(0)) aux_out.push_back(f_alelo[i]);
        }
    }

    return aux_out;
}

std::vector<int> Mutacion::desplazamiento(std::vector<int> f_alelo, std::vector<int> f_posicion) {
    std::vector<int> aux_out;
    std::vector<int> pos{f_posicion[0],f_posicion[1]};

    aux_out = insercion(f_alelo,pos);
    pos.clear();
    pos.push_back(f_posicion[2]);
    pos.push_back(f_posicion[3]);
    aux_out = insercion(aux_out,pos);

    return aux_out;
}

std::vector<int> Mutacion::intercambio(std::vector<int> f_alelo, std::vector<int> f_posicion) {
    int aux_int = f_alelo[f_posicion[0]];

    f_alelo.at(f_posicion[0]) = f_alelo.at(f_posicion[1]);
    f_alelo.at(f_posicion[1]) = aux_int;

    return f_alelo;
}

#endif //PROYECTO_MUTACION_H
