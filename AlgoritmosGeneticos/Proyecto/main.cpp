#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cmake-build-debug/Clases/Funciones.h"
#include "cmake-build-debug/Clases/Sujeto.h"
#include "cmake-build-debug/Clases/Poblacion.h"
#include "cmake-build-debug/Clases/Seleccion.h"
#include "cmake-build-debug/Clases/Cruza.h"
#include "cmake-build-debug/Clases/Mutacion.h"

std::vector<int> aux_aleatorios_enteros;
std::vector<float> aux_aleatorios_flotante;
std::vector<int> aux_fitnes;
std::vector<Poblacion> generaciones;

int tam_poblacion;
int lim_inferior;
int lim_superior;
int tam_mutados;
int tam_gen;
int tam_alelo;
int aux_int;
int tam_padres;

int tipo_alelo;
int tipo_seleccion;
int tipo_cruza;
int tipo_mutacion;
int tipo_fitnes;
int tipo_generacion;

void get_aleatorios_enteros(int cantidad, bool repetido,int lim_inferior, int lim_superior){
    aux_aleatorios_enteros.clear();
    aux_fitnes.clear();
    int aux_int;

    for(int i = 0 ; i <= cantidad-1 ; i++){
        aux_int = lim_inferior + rand() % (lim_superior-lim_inferior);
        if( i == 0 ) {
            aux_aleatorios_enteros.push_back(aux_int);
        }
        else{
            if(repetido){
                if(!funciones.repetido(aux_int,aux_aleatorios_enteros)) aux_aleatorios_enteros.push_back(aux_int);
                else i--;
            } else aux_aleatorios_enteros.push_back(aux_int);
        }
    }
}

void get_aleatorios_flotante(int cantidad){
    aux_aleatorios_flotante.clear();
    float aux_float;

    for(int i = 0 ; i <= cantidad-1 ; i++) {
        aux_float = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/1));
        if (i == 0) aux_aleatorios_flotante.push_back(aux_float);
        else aux_aleatorios_flotante.push_back(aux_float);
    }

}

int get_fitnes(int f_valor){
    int aux_out =0;

    switch (tipo_fitnes){
        case 0:
            aux_out = f_valor;
            break;
        case 1:
            aux_out = f_valor*f_valor;
            break;
        case 2:
            aux_out = f_valor + 5;
            break;
        case 3:
            aux_out = f_valor*10;
            break;
    }

    return aux_out;
}

int get_valor(std::vector<int> f_arreglo){
    int aux_out =0;

    for(int i=0 ; i<=f_arreglo.size()-1 ; i++){
        aux_out = aux_out + f_arreglo[i]*pow(2,i);
    }

    return aux_out;
}

void mostrar_entradas(){
    std::cout << "\n Datos de entrada "<< std::endl;
    std::cout << "\tTamano de la poblacion: " << tam_poblacion << std::endl;
    std::cout << "\tLimite inferior del valor: " << lim_inferior << std::endl;
    std::cout << "\tLimite superior del valor: " << lim_superior << std::endl;
    std::cout << "\tCantidad de generaciones: " << tam_gen << std::endl;
    std::cout << "\tTamano de mutados: " << tam_mutados << std::endl;

    switch(tipo_alelo){
        case 0://binario
            std::cout << "\tTipo de gen: binario" << std::endl;
            break;
        case 1://gray
            std::cout << "\tTipo de gen: gray" << std::endl;
            break;
    }

    switch(tipo_seleccion){
        case 0: //ruleta
            std::cout << "\tSeleccion: ruleta" << std::endl;
            break;
        case 1: //jerarquico
            std::cout << "\tSeleccion: jerarquico" << std::endl;
            break;
        case 2: //torneo
            std::cout << "\tSeleccion: torneo" << std::endl;
            break;
    }

    switch(tipo_cruza){
        case 0: //un_punto
            std::cout << "\tCruza: un punto" << std::endl;
            break;
        case 1:// n_puntos
            std::cout << "\tCruza: n puntos" << std::endl;
            break;
        case 2: //uniforme
            std::cout << "\tCruza: uniforme" << std::endl;
            break;
    }

    switch(tipo_mutacion){
        case 0://insercion
            std::cout << "\tMutacion: insercion" << std::endl;
            break;
        case 1://desplazamiento
            std::cout << "\tMutacion: desplazamiento" << std::endl;
            break;
        case 2://intercambio
            std::cout << "\tMutacion: intercambio" << std::endl;
            break;
    }

    switch (tipo_fitnes){
        case 0://f(x)=x
            std::cout << "\tFuncion fitnes: f(x)=x" << std::endl;
            break;
        case 1://f(x)=x^2
            std::cout << "\tFuncion fitnes: f(x)=x^2" << std::endl;
            break;
        case 2://f(x)=x+5
            std::cout << "\tFuncion fitnes: f(x)=x+5" << std::endl;
            break;
        case 3://f(x)=x*10
            std::cout << "\tFuncion fitnes: f(x)=x*10" << std::endl;
            break;
    }

    switch (tipo_generacion){
        case 0://generacional
            std::cout << "\tTipo generaciones: generacional" << std::endl;
            break;
        case 1://extintiva
            std::cout << "\tTipo generaciones: extintiva" << std::endl;
            break;
    }
    std::cout << "\n";
}

void solicitar_datos(){
    std::cout << "Programa 4 de Algoritmos geneticos" << std::endl;
    std::cout << "objetivo: desarrollo de un algoritmo genetico, que conste de 3 metodos de seleccion, 3 metodos de cruza y 3 metodos de mutacion" << std::endl;
    std::cout << "Introduccion de datos iniciales" << std::endl;
    std::cout << " Limite inferior de los datos: ";
    std::cin >> lim_inferior;
    std::cout << "Limite superior de los datos: ";
    std::cin >> lim_superior;
    tam_alelo = funciones.get_tam_alelo(lim_superior);
    std::cout << "Cantidad de la poblacion: ";
    std::cin >> tam_poblacion;
    tam_padres = tam_poblacion;
    std::cout << "Cantidad de generaciones: ";
    std::cin >> tam_gen;
    std::cout << "Tipo de alelo:\n\t0)Binario\t1)Gray\t:";
    std::cin >> tipo_alelo;
    std::cout << "Tipo de seleccion:\n\t0)Ruleta\t1)Jerarquico\t2)Torneo\t:";
    std::cin >> tipo_seleccion;
    std::cout << "Tipo de cruza:\n\t0)Un punto\t1)N puntos\t2)Uniforme\t:";
    std::cin >> tipo_cruza;
    std::cout << "Cantidad de sujetos mutados: ";
    std::cin >> tam_mutados;
    std::cout << "Tipo de mutacion:\n\t0)Insercion\t1)Desplazamiento\t2)Intercambio\t:";
    std::cin >> tipo_mutacion;
    std::cout << "Tipo de mutacion:\n\t0)f(x)=x\t1)f(x)=x^2\t2)f(x)=x+5\t3)f(x)=x*10\t:";
    std::cin >> tipo_fitnes;
    std::cout << "Tipo de generacion:\n\t0)Generacional\t1)Extintiva\t:";
    std::cin >> tipo_generacion;
}

int main() {
    srand(time(NULL));

    std::vector<Sujeto> padres;
    std::vector<Sujeto> sujetos_aux;
    std::vector<Sujeto> hijos;
    std::vector<int> alelos_mutados;

    Seleccion seleccion;
    Cruza cruza;
    Mutacion mutacion;

    solicitar_datos();
    /*
    lim_inferior=0;
    lim_superior=64;
    tam_alelo = funciones.get_tam_alelo(lim_superior);
    tam_poblacion=4;
    tam_padres = tam_poblacion;
    tam_gen=3;
    tipo_alelo=0;
    tipo_seleccion=0;
    tipo_cruza=0;
    tam_mutados=2;
    tipo_mutacion=0;
    tipo_fitnes=2;
    tipo_generacion = 1;
*/
    mostrar_entradas();

    int cont = 0;

    Poblacion poblacion_0;

    switch(tipo_alelo){
        case 0://binario
            get_aleatorios_enteros(tam_poblacion,true,lim_inferior,lim_superior);
            for(int i=0 ; i <= aux_aleatorios_enteros.size()-1 ; i++){
                aux_fitnes.push_back(get_fitnes(aux_aleatorios_enteros[i]));
            }
            poblacion_0.generar_poblacion(aux_aleatorios_enteros,aux_fitnes,tipo_alelo,tam_alelo);
            break;
        case 1://gray
            get_aleatorios_enteros(tam_poblacion,true,lim_inferior,lim_superior);
            for(int i=0 ; i <= aux_aleatorios_enteros.size()-1 ; i++){
                aux_fitnes.push_back(get_fitnes(aux_aleatorios_enteros[i]));
            }
            poblacion_0.generar_poblacion(aux_aleatorios_enteros,aux_fitnes,tipo_alelo,tam_alelo);
            break;
    }

    std::cout << "Generacion 0" << std::endl;
    poblacion_0.ver_poblacion();

    generaciones.push_back(poblacion_0);

    for(int i=1 ; i <= tam_gen ; i ++){

        switch(tipo_seleccion){
            case 0: //ruleta
                get_aleatorios_flotante(tam_padres);
                padres = seleccion.ruleta(poblacion_0.get_poblacion(),tam_padres,aux_aleatorios_flotante);
                break;
            case 1: //jerarquico
                get_aleatorios_flotante(tam_padres);
                padres = seleccion.ruleta(poblacion_0.get_poblacion(),tam_padres,aux_aleatorios_flotante);
                break;
            case 2: //torneo
                get_aleatorios_enteros(tam_padres*2,false,0,tam_poblacion);
                padres = seleccion.torneo(poblacion_0.get_poblacion(),tam_padres,aux_aleatorios_enteros);
                break;
        }

        switch(tipo_cruza){
            case 0: //un_punto
                for(int j=0 ; j <= ( tam_padres/2 )-1 ; j=j+1){
                    sujetos_aux.push_back(padres[j]);
                    sujetos_aux.push_back(padres[j+1]);
                    get_aleatorios_enteros(1,false,0,tam_alelo);
                    sujetos_aux = cruza.un_punto(sujetos_aux,tam_alelo,aux_aleatorios_enteros);
                    hijos.push_back(sujetos_aux[0]);
                    hijos.push_back(sujetos_aux[1]);
                    sujetos_aux.clear();
                }
                break;
            case 1:
                for(int j=0 ; j <= ( tam_padres/2 )-1 ; j=j+1){
                    sujetos_aux.push_back(padres[j]);
                    sujetos_aux.push_back(padres[j+1]);
                    get_aleatorios_enteros(3,false,0,tam_alelo);
                    sujetos_aux = cruza.n_puntos(sujetos_aux,tam_alelo,aux_aleatorios_enteros);
                    hijos.push_back(sujetos_aux[0]);
                    hijos.push_back(sujetos_aux[1]);
                    sujetos_aux.clear();
                }
                break;
            case 2:
                for(int j=0 ; j <= ( tam_padres/2 )-1 ; j=j+1){
                    sujetos_aux.push_back(padres[j]);
                    sujetos_aux.push_back(padres[j+1]);
                    get_aleatorios_enteros(3,false,0,tam_alelo);
                    sujetos_aux = cruza.uniforme(sujetos_aux,tam_alelo,aux_aleatorios_enteros);
                    hijos.push_back(sujetos_aux[0]);
                    hijos.push_back(sujetos_aux[1]);
                    sujetos_aux.clear();
                }
                break;
        }

        get_aleatorios_enteros(tam_mutados,false,0,hijos.size());
        std::vector<int> mutados;
        for(int j=0 ; j <= 4 ; j++){
            aux_int =  rand() % tam_alelo;
            mutados.push_back(aux_int);
        }

        switch(tipo_mutacion){
            case 0://insercion
                for(int j=0 ; j <= hijos.size()-1 ; j++){
                    if(j==aux_aleatorios_enteros[0] || j==aux_aleatorios_enteros[1]){
                        hijos[j].set_alelo(mutacion.insercion(hijos[j].get_alelo(),mutados));
                    }
                }
                break;
            case 1://desplazamiento
                for(int j=0 ; j <= hijos.size()-1 ; j++){
                    if(j==aux_aleatorios_enteros[0] || j==aux_aleatorios_enteros[1]){
                        hijos[j].set_alelo(mutacion.desplazamiento(hijos[j].get_alelo(),mutados));
                    }
                }
                break;
            case 2://intercambio
                for(int j=0 ; j <= hijos.size()-1 ; j++){
                    if(j==aux_aleatorios_enteros[0] || j==aux_aleatorios_enteros[1]){
                        hijos[j].set_alelo(mutacion.intercambio(hijos[j].get_alelo(),mutados));
                    }
                }
                break;
        }

        int aux_h,aux_p;
        switch (tipo_generacion){
            case 1://extintiva
                for(int j=0 ; j<=hijos.size()-1 ; j++){
                    aux_h = get_fitnes(get_valor(hijos[j].get_alelo()));
                    aux_p = padres[j].get_fitnes();
                    if ( aux_p > aux_h ) hijos[j].set_alelo(padres[j].get_alelo());
                }
                break;
        }

        cont = tam_poblacion * i;
        for(int j=0 ; j<=hijos.size()-1 ; j++){
            hijos[j].set_id(cont+j);
            hijos[j].set_valor(get_valor(hijos[j].get_alelo()));
            hijos[j].set_fitnes(get_fitnes(hijos[j].get_valor()));
        }

        Poblacion hijos_m;
        std::cout << "Generacion " << i << std::endl;
        hijos_m.set_poblacion(hijos);
        hijos_m.ver_poblacion();

        padres.clear();
        hijos.clear();
        generaciones.push_back(hijos_m);
    }

    /*
    std::cout << "\nConcentrado por generaciones " << std::endl;

    sujetos_aux.clear();

    for(int i=0 ; i<= generaciones.size()-1 ; i++){
        sujetos_aux.push_back(generaciones[i].get_max());
        sujetos_aux.push_back(generaciones[i].get_min());
        }

    Poblacion concentrado;
    concentrado.set_poblacion(sujetos_aux);
    concentrado.ver_poblacion();

    std::cout << "\nGrafica: " << std::endl;
    funciones.graficar(sujetos_aux);
*/

    return 0;
}