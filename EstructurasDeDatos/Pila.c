#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 100

int pila[MAXTAM];
int tope=-1;

void Apilar();
void Eliminar();
void Completos();
void ContElementos();


int main(){
	int opc;
	do{
		do{
			printf("Escribir el numero para realizar la operacion deseada.\n");
			printf("Menu de opciones para una pila: \n\n");
			printf("1.-Meter un dato en la pila. \n");
			printf("2.-Sacar el ultimo dato de la pila. \n");
			printf("3.-Sacar todos los datos de la pila. \n");
			printf("4.- Contar cuantos elementos hay en la pila. \n");
			scanf("%d", &opc);
	}while(opc<1 || opc>4);
	switch(opc){
		case 1:
			Apilar();
			break;
		case 2:
			Eliminar();
			break;
		case 3:
			Completos();
			break;
		case 4:
			ContElementos();
			break;
	}	
	}while(opc<5);
	if(opc>4){
		printf("El valor introducido no es valido. \n");
	}
}



void Apilar(){
	system("cls");
	int num;
	if(tope==(MAXTAM)){
		printf("La pila esta llena. \n");
	}
	else{
		printf("Introduzca el elemento: \n");
		scanf("%d",&num);
		pila[tope+1]=num;
		tope=tope+1;
	}
	printf("\n");
}

void Eliminar(){
	system("cls");
	if(tope==-1){
		printf("La pila esta vacia. \n");
	}
	else{
		printf("El elemento %d ha sido retirado de la pila.\n",pila[tope]);
		tope--;
	}
}

void ContElementos(){
	system("cls");
	int i,aux,cont=0;
	if(tope==-1){
		printf("La pila no tiene elementos. \n");
	}
		else{
		for(i=tope;i>=0;i--){
			cont++;
		}
		printf("Hay %d elementos en la pila. \n",cont);
	}
}

void Completos(){
	system("cls");
	int i;
	if(tope==-1){
		printf("La pila esta vacia. \n");
	}
	else{
		printf("Los elementos dentro de la pila en orden son: ");
		for(i=tope;i>=0;i--){
			printf("%d,",pila[i]);
			tope--;
		}
		printf("\n");
	}
}
