#ifndef PROYECTO_POBLACION_H
#define PROYECTO_POBLACION_H


class Poblacion {
private:
    std::vector<Sujeto> sujetos;
    Funciones funciones;
public:
    void generar_poblacion(std::vector<int> f_valores,std::vector<int> f_fitnes,int tipo_alelo,int tam_alelo);
    void generar_poblacion(std::vector<int> f_valores,std::vector<int> f_fitnes,std::vector<float> f_probabilidad,int tam_alelo);
    void set_poblacion(std::vector<Sujeto> f_sujetos);
    void ver_poblacion();
    std::vector<Sujeto> get_poblacion();
    Sujeto get_max();
    Sujeto get_min();

};

void Poblacion::set_poblacion(std::vector<Sujeto> f_sujetos) {
    sujetos.clear();
    sujetos = f_sujetos;
}

std::vector<Sujeto> Poblacion::get_poblacion() {
    return sujetos;
}

void Poblacion::generar_poblacion(std::vector<int> f_valores, std::vector<int> f_fitnes, int tipo_alelo,int tam_alelo) {
    Sujeto aux_sujeto;
    for(int i=0 ; i<=f_valores.size()-1 ; i++){
        aux_sujeto.set_id(i);
        aux_sujeto.set_valor(f_valores[i]);
        aux_sujeto.set_fitnes(f_fitnes[i]);
        if(tipo_alelo == 0) aux_sujeto.set_alelo(funciones.convertir_binario(f_valores[i],tam_alelo));
        else aux_sujeto.set_alelo(funciones.convertir_gray(f_valores[i],tam_alelo));
        sujetos.push_back(aux_sujeto);
    }
}

void Poblacion::generar_poblacion(std::vector<int> f_valores,std::vector<int> f_fitnes, std::vector<float> f_probabilidad,int tam_alelo) {
    Sujeto aux_sujeto;
    std::vector<int> alelo_aux;
    for(int i=0 ; i<=f_valores.size()-1 ; i++){
        aux_sujeto.set_id(i);
        aux_sujeto.set_valor(f_valores[i]);
        aux_sujeto.set_fitnes(f_fitnes[i]);
        for(int j = 0 ; j <= (f_probabilidad.size()-1)/tam_alelo ; j++){
            if(f_probabilidad[i+j] <= .5) alelo_aux.push_back(1);
            else alelo_aux.push_back(0);
        }
        aux_sujeto.set_alelo(alelo_aux);
        alelo_aux.clear();
        sujetos.push_back(aux_sujeto);
    }
}

void Poblacion::ver_poblacion() {

    for(int i=0 ; i<=sujetos.size()-1 ; i++){
        std::cout << "Sujeto :" << sujetos[i].get_id() << "   ";
        std::cout << "Valor :" << sujetos[i].get_valor()<< "   ";
        std::cout << "Fitnes :" << sujetos[i].get_fitnes()<< "   ";
        std::cout << "Alelo :" << funciones.imprimir_arreglo(sujetos[i].get_alelo());
    }
}

Sujeto Poblacion::get_max() {
    int max = sujetos[0].get_fitnes();
    int id =0;

    for(int i=1; i <= sujetos.size()-1 ; i++){
        if(sujetos[i].get_fitnes() > max){
            max = sujetos[i].get_fitnes();
            id = i;
        }
    }

    return sujetos[id];
}

Sujeto Poblacion::get_min() {
    int min = sujetos[0].get_fitnes();
    int id =0;

    for(int i=1; i <= sujetos.size()-1 ; i++){
        if(sujetos[i].get_fitnes() < min){
            min = sujetos[i].get_fitnes();
            id = i;
        }
    }

    return sujetos[id];
}

#endif //PROYECTO_POBLACION_H
