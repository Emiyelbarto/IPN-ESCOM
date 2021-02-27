#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

#define load_size 7500 //capacidad de carga en gramos
#define water_limit 59 //capacidad de agua en litros
#define max_speed 1200 //velocidad máxima en revoluciones por minuto
#define det_level 1500 //nivel de detergente en gramos
#define sv_level 1000 //nivel de suavizante en mililitros

void menu(); //Funcion Menu Principal
void seleccion_tipo_completo(); //Funcion cuando la seleccion fue lavado completo
int sensor_ropa();
int sensor_detergente();
int sensor_suavizante();
int seleccion_tipo_ropa(int tim,int peso); //Funcion para la seleccion de ropa(recibe peso y una variable identificadora de carga)
void seleccion_enjuagado(); // Funcion cuando solmente se enjuaga
void seleccion_centrifugado(); //Funcion cuando solamente centrifuga

int main(){
system("cls");
  printf("\nLavadora MarQ MQFLXI75");
  printf("\nInicializando Sistema...");
 Sleep(4000);
  printf("\nLista!");
 Sleep(4000);
 printf("\nChecando niveles...");
 Sleep(2000);
 system("cls");
   menu();
  return 0;
}

void menu(){
int seleccion;
  printf("\nSeleccione una opcion");
  printf("\n1.- Lavado completo");
  printf("\n2.- Enjuagado");
  printf("\n3.- Centrifugado");
  printf("\n");
  scanf("\n%i",&seleccion);

   switch(seleccion){
    
    case 1: //Lavado completo
    system("cls");
    printf("\nIniciando Lavado Completo");
    Sleep(1000);
    printf("\nPuerta abierta, deposite la ropa");
    Sleep(4000);
    system("cls");
    seleccion_tipo_completo();
    break;

    case 2: //Enjuagado
    system("cls");
    printf("\nIniciando Enjuagado");
    Sleep(1000);
    printf("\nPuerta abierta, deposite la ropa");
    Sleep(4000);
    system("cls");
    seleccion_enjuagado();
    break;

    case 3: //Centrifugado
    system("cls");
    printf("\nIniciando Centrifugado");
    Sleep(1000);
    printf("\nPuerta abierta, deposite la ropa");
    Sleep(4000);
    system("cls");
    seleccion_centrifugado();
    break;


   }

}

void seleccion_tipo_completo(){
  int lvl; //esta variable es solo para simular el sensor de los niveles con un random
  int peso, det, suav, typ, tim;
  srand (time(NULL)); //Se inicia un random
  lvl=rand()%1; //Si es 0 entonces los niveles no son los necesarios, si es 1 entonces son correctos
  printf("\nComprobando si los niveles de detergente y suavizante son óptimos");
    if(lvl == 0){
    	system("cls");
    	 printf("\nNiveles por debajo de lo necesario! Llene porfavor los contenedores hasta la linea marcada"); // el sensor detecta si los niveles de detergente son muy bajos
    	 det=sensor_detergente(); //Simula el llenado de detergente
    	 suav=sensor_suavizante(); //Simula el llenado de suavizante
    	 Sleep(3000);
    }
 peso=sensor_ropa(); //Simula el insertar la ropa, devuelve el peso de la misma
 printf("\nSe han detectado %i kilos en la lavadora",peso);
 if(peso >= 1 && peso <= 2 ){
 	printf("\nCarga mínima detectada");
 	tim=1; //identificador de carga
    typ=seleccion_tipo_ropa(tim,peso);
 }

 if(peso > 2 && peso <= 4 ){
 	printf("\nCarga media detectada");
 	tim=2; //identificador de carga
 	typ=seleccion_tipo_ropa(tim,peso);
 }

 if(peso > 5 && peso <= 8 ){
 	printf("\nCarga máxima detectada");
 	tim=3; //identificador de carga
 	seleccion_tipo_ropa(tim,peso);
 }


}

int seleccion_tipo_ropa(int tim, int peso){
  int seleccion;
  printf("\nSeleccione tipo de ropa");
  printf("\n1.- 'Quick 15' ");
  printf("\n2.- Seda Delicada Plus ");
  printf("\n3.- Lana Lavado a Mano Plus ");
  printf("\n4.- Algodón");
  printf("\n5.- Ropa de Noche");
  printf("\n6.- Drum Clean");
  printf("\n7.- Spin");
  printf("\n");
  scanf("\n%i",&seleccion);

if(seleccion == 1){
	if(peso >= 1 && peso <= 2){
  printf("\nComenzando lavado, tiempo: 15 min");
  printf("\nVelocidad 600rpm");
    printf("\nLavado..");
    Sleep(3000);
    printf("\nEnjuagado...");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
  }else if(peso > 2 && peso <= 4){
  	printf("\nComenzando lavado, tiempo: 15 min");
  	printf("\nVelocidad 800rpm");
    printf("\nLavado...");
    Sleep(3000);
    printf("\nEnjuagado...");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
  }else if(peso > 4 && peso <= 8){
  	printf("\nComenzando lavado, tiempo: 15 min");
  	printf("\nVelocidad 1200rpm");
    printf("\nLavado..");
    Sleep(3000);
    printf("\nEnjuagado..");
    Sleep(3000);
    printf("\nSecado..");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
  }
}

if(seleccion >= 2 && seleccion <= 7){
    if(tim == 1){
    printf("\nComenzando lavado, tiempo: 20 min");
    printf("\nVelocidad: 600rpm");
    printf("\nLavado...");
    Sleep(3000);
    printf("\nEnjuagado...");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
    }
 }


    if(tim == 2){
    printf("\nComenzando lavado, tiempo: 30 min");
    printf("\nVelocidad: 800rpm");
    printf("\nLavado...");
    Sleep(3000);
    printf("\nEnjuagado...");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
    }


    if(tim == 3){
    printf("\nComenzando lavado, tiempo: 45 min");
    printf("\nVelocidad: 1200rpm");
    printf("\nLavado...");
    Sleep(3000);
    printf("\nEnjuagado...");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
    }
   return 0;
 }


void seleccion_enjuagado(){
  int lvl; //esta variable es solo para simular el sensor de los niveles con un random
  int peso;
  srand (time(NULL)); //Se inicia un random
  lvl=rand()%1; //Si es 0 entonces los niveles no son los necesarios, si es 1 entonces son 
  printf("\nEL PROCESO DE ENJUAGADO NO REQUIERE DE ALGUN DETERGENTE NI SUAVIZANTE");
 peso=sensor_ropa();
 printf("\nSe han detectado %i kilos en la lavadora",peso);
 if(peso >= 1 && peso <= 2 ){
 	printf("\nCarga mínima detectada");
 	printf("\nVelocidad: 600rpm");
 	printf("\nComenzando enjuagado 10 min");
 	Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
 }

 if(peso > 2 && peso <= 4 ){
 	printf("\nCarga media detectada");
 	printf("\nVelocidad: 800rpm");
    printf("\nComenzando enjuagado 15 min");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
 }

 if(peso > 4 && peso <= 8 ){
 	printf("\nCarga maxima detectada");
 	printf("\nVelocidad: 1200rpm");
 	printf("\nComenzando enjuagado 20 min");
 	Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");

 }
 
}

void seleccion_centrifugado(){
  int lvl; //esta variable es solo para simular el sensor de los niveles con un random
  int peso;
  srand (time(NULL)); //Se inicia un random
  lvl=rand()%1; //Si es 0 entonces los niveles no son los necesarios, si es 1 entonces son 
  printf("\nEL PROCESO DE CENTRIFUGADO NO REQUIERE DE ALGUN DETERGENTE NI SUAVIZANTE");
 peso=sensor_ropa();
 printf("\nSe han detectado %i kilos en la lavadora",peso);
 if(peso >= 1 && peso <= 2 ){
 	printf("\nCarga mínima detectada");
 	printf("\nVelocidad: 600rpm");
 	printf("\nComenzando centrifugado 5 min");
 	Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
 }

 if(peso > 2 && peso <= 4 ){
 	printf("\nCarga media detectada");
 	printf("\nVelocidad: 800rpm");
    printf("\nComenzando centrifugado 10 min");
    Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");
 }

 if(peso > 4 && peso <= 8 ){
 	printf("\nCarga máxima detectada");
 	printf("\nVelocidad: 1200rpm");
 	printf("\nComenzando centrifugado 15 min");
 	Sleep(3000);
    printf("\nSecado...");
    Sleep(3000);
    puts("\a");
    printf("\nProceso completado!");

 }
}

//Apartir de aqui inician las funciones que simulan los sensores de la lavadora; Peso de ropa, Nivel de Agua,
//Nivel de detergente, Nivel de Suavizante
 int sensor_ropa(){
  srand (time(NULL)); //Se inicia un random
  int peso = rand()%(8-1+1)+1; // Simula peso de la ropa insertada
  return peso;
 }

 int sensor_detergente(){
  srand (time(NULL)); //Se inicia un random
  int det = rand()%(1500-100+1)+100; // Simula niveles de detergente
  return det;
 }

 int sensor_suavizante(){
  srand (time(NULL)); //Se inicia un random
  int suav = rand()%(1000-200+1)+200; // Simula niveles de suavizante
  return suav;
 }
