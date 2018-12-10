//Archivo pila_char.h
#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodo{
 char dato;
 struct nodo *siguiente;
} Nodo;
 
typedef Nodo *pNodo;
typedef Nodo *Pila;

void push();
char pop();
void comp();

int main(){
	int i;
	Pila buffer=NULL;
	buffer=(Nodo *)malloc(sizeof(Nodo));
	for()
}

void push(Pila *pila, char x){
 	Nodo nodo;
 	nodo = (pNodo)malloc(sizeof(Nodo));
 	if (nodo != NULL){
    	 nodo->dato = x;
    	 nodo->siguiente = *pila;
    	 *pila=nodo;
    }
}

char pop(Pila *pila)
{
 ptrNodo nodo;
 char x;
 nodo = *pila;
 x = (*pila)->dato;
 *pila = (*pila)->siguiente;
 free(nodo);
 return x;
}

int pila_vacia(Pila *pila)
{
 return (*pila == NULL ? 1:0);
}
