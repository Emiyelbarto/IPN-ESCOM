#ifndef PROYECTO_SUJETO_H
#define PROYECTO_SUJETO_H

#include <vector>

class Sujeto {
private:
    int id;
    int valor;
    int fintes;
    std::vector<int> alelo;
public:
    void set_id(int f_id);
    void set_valor(int f_valor);
    void set_fitnes(int f_fitnes);
    void set_alelo(std::vector<int> f_alelo);
    int get_id();
    int get_valor();
    int get_fitnes();
    std::vector<int> get_alelo();
};

void Sujeto::set_id(int f_id) {
    id = f_id;
}

void Sujeto::set_valor(int f_valor) {
    valor = f_valor;
}

void Sujeto::set_fitnes(int f_fitnes) {
    fintes = f_fitnes;
}

void Sujeto::set_alelo(std::vector<int> f_alelo) {
    alelo = f_alelo;
}

int Sujeto::get_id(){
    return id;
}

int Sujeto::get_valor(){
    return valor;
}

int Sujeto::get_fitnes() {
    return fintes;
}

std::vector<int> Sujeto::get_alelo(){
    return alelo;
}

#endif //PROYECTO_SUJETO_H
