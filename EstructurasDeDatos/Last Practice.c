#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *derecha, *izquierda;
}Nodo;

typedef struct cola{
	int recorrido;
	struct cola *siguiente;
}Cola;

typedef struct{
	Cola *Primero;
	Cola *Ultimo;
	int tam;
}Queue;

void menu();
Nodo *Inicializar();
Cola *Inicializar_Cola();
void Insertar(Nodo *, int );
void Buscar_Nodo(Nodo *, int , Queue *);
Nodo *Eliminar_Nodo(Nodo *, int , Queue *);
//Nodo *Rotar_Izquierda(Nodo *Arbol);
//Nodo *Rotar_Derecha(Nodo *Arbol);
void leertxt(Nodo *);
void push(int , Queue *);
int pop(Queue *);
void Preorden(Nodo *);
void Inorden(Nodo *);
void Postorden(Nodo *);
void Imprimir_Cola(Queue *);
int Profundidad(Nodo *);
int Balanceado(Nodo *);
void prueba();


int main(){
	int opc,dato,busqueda;
	Nodo *Arbol;
	Arbol = Inicializar();
	Queue *Camino;
	Camino = calloc(1,sizeof(Queue));
	
	while(opc!=6){
		menu();
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("Escribir el dato a insertar: \n");
				scanf("%d",&dato);
				Insertar(Arbol, dato);
				break;
			case 2: 
				printf("El arbol ha sido balanceado. \n");
				// Balanceo();
				break;
			case 3:
				printf("Introducir el nodo a buscar: \n");
				scanf("%d",&busqueda);
				Buscar_Nodo(Arbol, busqueda, Camino);
				system("PAUSE");
				break;
			case 4:
				printf("El arbol es: \n");
				printf("Preorden:\n");
				Preorden(Arbol);
				printf("\n");
				printf("Inorden:\n");
				Inorden(Arbol);
				printf("\n");
				printf("Postorden:\n");
				Postorden(Arbol);
				printf("\n");
				system("PAUSE");
				break;
			case 5:
				leertxt(Arbol);
				break;
		}
		system("cls");
	}
	return 0;	
}

void menu(){
	printf("----- MENU DE ARBOLES -----\n");
	printf("1.-Insertar nodo.\n2.-Eliminar nodo.\n3.-Buscar nodo.\n4.-Imprimir el arbol.\n5.-Leer txt.\n6.-Salir.\n");
}

Nodo *Inicializar(){
	Nodo *raiz;
	raiz = (Nodo *) malloc(sizeof(Nodo));
	
	raiz->dato = 0;
	raiz->derecha = NULL;
	raiz->izquierda = NULL;
	
	return raiz;
}

Cola *Inicializar_Cola(){
	Cola *inicio;
	inicio = (Cola *)malloc(sizeof(Cola));
	
	inicio->siguiente = NULL;
	inicio->recorrido = 0;
	
	return inicio;
}

void Insertar(Nodo *Arbol, int dato){
	
	Nodo *raiz;
	raiz = malloc(sizeof(Nodo));
	
	if((Arbol!=NULL) && (Arbol->derecha) == NULL && (Arbol->izquierda) == NULL){
		Arbol->dato = dato;
		Arbol->derecha = Inicializar();
		Arbol->izquierda = Inicializar();
		*raiz = *Arbol;
	}
	if(dato > Arbol->dato){
		Insertar(Arbol->derecha, dato);
	}
	else if(dato < Arbol->dato){
		Insertar(Arbol->izquierda, dato);
	}
}

void Buscar_Nodo(Nodo *Arbol, int busqueda, Queue *Camino){
	if(Arbol != NULL){
		if(busqueda == Arbol->dato){
			printf("El nodo %d tiene el siguiente recorrido: ",Arbol->dato);
			Imprimir_Cola(Camino);
			}
		else if(busqueda < Arbol->dato){
			push(Arbol->dato, Camino);
			Buscar_Nodo(Arbol->izquierda, busqueda, Camino);
		}
		else if(busqueda > Arbol->dato){
			push(Arbol->dato, Camino);
			Buscar_Nodo(Arbol->derecha, busqueda, Camino);
			}
	}
}

void Preorden(Nodo *Arbol){
	if(Arbol!=NULL){
		if(Arbol->dato != 0){
		printf("%d  ",Arbol->dato);
		Preorden(Arbol->izquierda);
		Preorden(Arbol->derecha);
		}
	}
}

void Inorden(Nodo *Arbol){
	if(Arbol!=NULL){		
		if(Arbol->dato != 0){
		Inorden(Arbol->izquierda);
		printf("%d  ",Arbol->dato);
		Inorden(Arbol->derecha);
		}
	}
}

void Postorden(Nodo *Arbol){
	if(Arbol != NULL){
		if(Arbol->dato != 0){
			Postorden(Arbol->izquierda);
			Postorden(Arbol->derecha);
			printf("%d  ",Arbol->dato);
		}
	}
}

void leertxt(Nodo *Arbol){
	int dato;
	
	FILE *archivo;
	char *nombrearchivo= "C:/Users/José Emiliano Pérez/Documents/arbolito.txt";
	
	archivo = fopen(nombrearchivo, "r");

	if(archivo == NULL){
		printf("\n No se pudo leer el txt. \n");
		return;
	}
	
	while(!feof(archivo)){
		fscanf(archivo,"%d,",&dato);
		Insertar(Arbol,dato);
	}
	fclose(archivo);
}

void push(int data, Queue *Camino){
	if(Camino->Primero == NULL){
		Camino->Primero = malloc(sizeof(Cola));
		Camino->Primero->recorrido = data;
		Camino->Primero->siguiente = NULL;
		Camino->Ultimo = Camino->Primero;
		Camino->tam = 1;
	}
	else{
		Camino->Ultimo->siguiente = malloc(sizeof(Cola));
		Camino->Ultimo->siguiente->recorrido = data;
		Camino->Ultimo = Camino->Ultimo->siguiente;
		Camino->Ultimo->siguiente = NULL;
		Camino->tam++;
	}
}

int pop(Queue *Camino){
	int Aux;
	if(Camino->Primero != NULL){
		Aux = Camino->Primero->recorrido;
		Camino->Primero = Camino->Primero->siguiente;
	}
	return Aux;
}

void Imprimir_Cola(Queue *Camino){
	int i;
	while(Camino->Primero != NULL){
		i = pop(Camino);
		if(i != 0){
			printf("%d	",i);
		}
	}
	printf("\n");
}

void prueba(){
	printf("prueba.\n");
}

int Balanceado(Nodo * Arbol){
    int nivel_izquierda ,nivel_derecha,precedencia = 0;
    
	nivel_izquierda = Profundidad(Arbol->izquierda);
    nivel_derecha = Profundidad(Arbol->derecha);
    
    precedencia = nivel_izquierda - nivel_derecha;
    
    if (precedencia == 0 || precedencia == 1 || precedencia == -1){
        if (Balanceado(Arbol->izquierda) && Balanceado(Arbol->derecha)){
            return 1;
        }
        else return 0;
    }
    else return 0;
}


int Profundidad(Nodo *Arbol){
	int nivel_izquierda, nivel_derecha;
	
	if(Arbol != NULL){
	    nivel_izquierda = Profundidad(Arbol->izquierda);
	    nivel_derecha = Profundidad(Arbol->derecha);
	    if (nivel_izquierda > nivel_derecha)
	        return nivel_izquierda + 1;
	    else
	        return nivel_derecha + 1;
	}
}

/*
Nodo *Rotar_Izquierda(Nodo *Arbol){
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	
	aux = Arbol->izquierda;
	
	Arbol->izquierda = aux->derecha;
	Arbol->izquierda->izquierda = aux;	
	
	return Arbol;
}

Nodo *Rotar_Derecha(Nodo *Arbol){
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	aux = Inicializar();
	
	aux = Arbol->derecha;
	
	Arbol->derecha = aux->izquierda;
	Arbol->derecha->derecha = aux;	
	
	return Arbol;
}

Nodo *Eliminar_Nodo(Nodo *Arbol, int busqueda, Queue *Camino){
	Nodo *Aux;
	Aux = malloc(sizeof(Nodo));
	
	if(Arbol!=NULL){
		if(busqueda < Arbol->dato){
			Eliminar_Nodo(Arbol->izquierda, busqueda, Camino);
		}
		else if(busqueda > Arbol->dato){
			Eliminar_Nodo(Arbol->derecha, busqueda, Camino);
		}
		else if(busqueda == Arbol->dato){
			while(Arbol->derecha != NULL){
				Arbol = Arbol->derecha;
			}
			Aux = Arbol;
			Arbol = NULL;
		}
	}
	return Aux;
}
*/
