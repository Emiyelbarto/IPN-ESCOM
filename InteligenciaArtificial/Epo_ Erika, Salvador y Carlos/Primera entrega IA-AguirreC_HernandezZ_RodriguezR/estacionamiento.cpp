#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sys/time.h>
#include <time.h>
#include<windows.h>
#include <unistd.h>
#include <sstream>

using namespace std;


class Espacios{
    private:
        int numero;
        bool ocupado;
    public:
        espacios(int ,bool );
        int obtenerNum();
        bool obtenerOcupado();
        void borrarEspacio();
};
Espacios::espacios(int num,bool lugar){
    numero=num; ocupado=lugar;
}

void Espacios::borrarEspacio(){
	numero=0; ocupado=false;
}

int Espacios::obtenerNum(){
    return numero;
}
bool Espacios::obtenerOcupado(){
    return ocupado;
}

void estacionarAuto(int num, Espacios espacio[12][12]);
void sacarAuto(int num, Espacios espacio[12][12]);
void mostrarLugares(Espacios espacio[12][12]);

int lvl,lugar;

int main(){

	int opcion;
	int i = 0;
	int j = 0,k=0;
	Espacios espacio[12][12];
	while(j<12){
		k=0;
		while(k<12){
			espacio[j][k].espacios(0,false);
			k++;			
		}
		j++;
	}
	int numero_Auto;
	cout << "Estacionameinto Automatizado 'Metro Cylinder' " << endl;
	//Elevador de 12 pisos con con 12 espacios cada uno
	while(opcion!=4){
		cout << "MENU:" << endl;
		cout << "1.- Estacionar auto" << endl;
		cout << "2.- Sacar auto" << endl;
		cout << "3.- Mostrar Lugares dentro del estacionamiento" << endl;
		cout << "4.- Salir" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:{
					estacionarAuto(numero_Auto,espacio);
					j=0;
					k=0;

					system("cls");
					cout << "\n\nSu ticket esta aqui abajo, recuerde su numero para recojer su auto" << endl;
					cout << "\n\n------------------------------------------" << endl;
					cout << "\t\tTICKET" << endl;
					cout << "\tSe estaciono en el \n\tPiso:" << lvl+1 <<endl;
					cout << "\tLugar:" << lugar+1 <<endl;
					cout << "\tNumero de ticket:" << espacio[lvl][lugar].obtenerNum() << endl;
					cout << "------------------------------------------\n\n" << endl;
					Sleep(2000);
					break;
				}

			case 2:{
						system("cls");
					int ticket;
					cout << "Introduce el numero en su ticket:" << endl;
					cin >> ticket;
					sacarAuto(ticket,espacio);
					break;
				}
			case 3:{
					system("cls");
					mostrarLugares(espacio);
					break;
				}
			case 4:{
					cout << "ADIOS" << endl;
					break;
			}
		}
	}
}

void estacionarAuto(int num, Espacios espacio[12][12]){
	srand (time(NULL));
	int flag = 0;
	int j = 0;
	int k = 0;
	system("cls");
    cout << "\n\n\tComprobando lugar para almacenar su auto.\n\tPor favor espere" << endl;
    Sleep(2000);
    cout << "\n\nADVERTENCIA\n\n\t------Mientras espere compruebe de poner el freno de mano y apagar correctamente su auto-------" << endl;
    Sleep(5000);
	system("cls");
	while(j<12){
		k=0;
		while(k<12){
			if(espacio[j][k].obtenerOcupado() == false){
				cout << "\n\n\tSe encontro un lugar, en breve sera llevado su auto para almacenarlo" << endl;
				Sleep(4000);
				num = rand() %(1000000000000000) + 100000000000000;
				espacio[j][k].espacios(num,true);
				lvl = j;
				lugar = k;
				k=12;
				j=12;
				flag=1;
			}
			k++;
		}
		j++;
	}
	if(flag == 0){
		cout << "No se encontro lugar para su auto dentro del estacionamiento.\nRegrese despues mientras los demas clientes regresan" << endl;
	}
}

void sacarAuto(int num, Espacios espacio[12][12]){
	int j = 0;
	int k = 0;
	int flag = 0;
	system("cls");
	cout << "\n\n\tSe esta buscando el numero en nuestro sistema.\n\tPor favor espere un momento." << endl;
	Sleep(4000);
	while(j<12){
		k=0;
		while(k<12){
			if(espacio[j][k].obtenerNum() == num){
				espacio[j][k].borrarEspacio();
				flag =1;
				system("cls");
				cout << "\n\n\tSu carro se encuentra en el piso:" << j+1 << " - lugar:"<<k+1<<endl;
				cout << "\n\tEn un momento se le entregara el auto" << endl;
				Sleep(4000);
				system("cls");
				cout << "\n\n\t-----Su auto ha sido entregado----\n\n\tConduzca con Cuidado\n\n\tVuelva Pronto\n\n" << endl;
				k=12;
				j=12;
			}
			k++;
		}
		j++;
	}
	if(flag == 0){
		cout << "\n\n\tNo se encontro el numero de ticket en nuestro sistema.\n\tVerifique que el numero este ingresado correctamente." << endl;
	}
}

void mostrarLugares(Espacios espacio[12][12]){
	int j=0,k=0;
	while(j<12){
		k=0;
		cout << "Piso " << j+1 << ":" <<endl;
		while(k<12){
			cout <<	espacio[j][k].obtenerNum() << " - " << espacio[j][k].obtenerOcupado() << endl;
			k++;
		}
		j++;
	}
}