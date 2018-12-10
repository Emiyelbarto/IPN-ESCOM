#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int *dato;
	struct nodo *derecho;
	struct nodo *izquierdo;
}Nodo;

Nodo *Inicializar_Arbol(Nodo *Arbol);
Nodo *Crear_Arbol();
void Insertar_Elemento(Nodo *Arbol,int n);
void Preorden(Nodo *raiz);
Nodo Eliminar_Arbol(Nodo *raiz);
void Inorden(Nodo *raiz);
void Postorden(Nodo *raiz);
void prueba();

int main(){
	int opcion,dato;
	Nodo *Arbol;
	Arbol = Crear_Arbol();
	
	while(opcion!=3){
		printf("--------MENU DE ARBOL BINARIO--------\n");
		printf("1.- Insertar elemento. \n");
		printf("2.- Imprimir el arbol.\n");
		printf("3.- Salir\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("Introducir un dato. \n");
				fflush(stdin);
				scanf("%d",&dato);
				Insertar_Elemento(Arbol,dato);
				break;
			case 2:
				printf("El arbol es: \n");
				printf("El arbol en preorden es: \n");
				Preorden(Arbol);
				printf("\nEl arbol en inorden es: \n");
				Inorden(Arbol);
				printf("\nEl arbol en postorden es: \n");
				Postorden(Arbol);
				printf("\n");
				system("pause");
				break;
		}
		system("cls");
	}
	return 0;
}

Nodo *Crear_Arbol(){
	Nodo *raiz;
	raiz = (Nodo *) malloc(sizeof(Nodo));
	
	raiz->dato = (int * )malloc(sizeof(int));
	raiz->dato[0] = 0;
	raiz->dato[1] = -1;
	raiz->derecho = NULL;
	raiz->izquierdo = NULL;
	
	return raiz;
}

void Insertar_Elemento(Nodo *raiz,int n){
	if((raiz != NULL) && (raiz->izquierdo == NULL) && (raiz->derecho == NULL)){
		raiz->dato[0] = n;
		raiz->dato[1] = 0;
		raiz->izquierdo = Crear_Arbol();
		raiz->derecho = Crear_Arbol();
	}
	if(n<raiz->dato[0]){
		Insertar_Elemento(raiz->izquierdo,n);
	}
	else if(n>raiz->dato[0]){
		Insertar_Elemento(raiz->derecho,n);
	}
}

void Preorden(Nodo *raiz){
	if(raiz!=NULL){
		if(raiz->dato[1]!=-1){
			printf("%d  ",raiz->dato[0]);
			Preorden(raiz->izquierdo);
			Preorden(raiz->derecho);
		}
	}
}

void Inorden(Nodo *raiz){
	if(raiz!=NULL){
		if(raiz->dato[1]!=-1){
			Inorden(raiz->izquierdo);
			printf("%d  ",raiz->dato[0]);
			Inorden(raiz->derecho);
		}
	}
}

void Postorden(Nodo *raiz){
	if(raiz != NULL){
		if(raiz->dato[1]!=-1){
			Postorden(raiz->izquierdo);
			Postorden(raiz->derecho);
			printf("%d  ",raiz->dato[0]);
		}
	}
}
Nodo Eliminar_Arbol(Nodo *raiz){
	
	raiz->dato = (int * )malloc(2 * sizeof(int));
	raiz->dato[0] = 0;
	raiz->dato[1] = -1;
	raiz->derecho = NULL;
	raiz->izquierdo = NULL;
}

void prueba(){
	printf("prueba. \n");
}

