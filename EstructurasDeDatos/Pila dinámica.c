#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	char *dato;
	struct nodo * siguiente;
}Nodo;

typedef Nodo *pNodo;
typedef Nodo *Pila;

void push(char *formula);
char pop(Pila * buffer);
int comp(Pila * buffer,char *formula);
int size(char *formula);

int main(){
	Pila *buffer= NULL;
	buffer=(Nodo *)malloc(sizeof(Nodo));
	int i;
	char *formula;
	formula=(char *)malloc(sizeof(char));
	printf("Escribir la ecuacion a revisar. \n");
	scanf("%[^\n]",formula);
	fflush(stdin);
	comp(buffer,&formula);
	if((comp(*buffer,formula)==1)){
		printf("Los parentecis estan bien ordenados. \n\n");
		return 0;
	}
	else if((comp(buffer,&formula))==0){
		printf("Los parentecis estan mal ordenados. \n\n");
	}
}

int comp(Pila * buffer, char *formula){
	int i;
	printf("Hola");
	for(i=0;i<size(&formula);i++){
		if(formula[i]=='('){
			printf("Entra al for");
			push(formula[i]);
			printf("hola");	
		}
		else{
			if(formula[i]=')'){
				if(pop(&buffer)!='('){
					return 0;
				}
			}
		}
	}
}

void push(char *formula){
	Pila buffer= NULL;
	buffer=(Nodo *)malloc(sizeof(Nodo));
	pNodo aux;
	aux=(pNodo)malloc(sizeof(Nodo));
	aux->dato=formula;
	aux->siguiente=buffer;
}

char pop(Pila *buffer){
	if(buffer!=NULL){
		char var;
		pNodo nodo;
		nodo=*buffer;
		*buffer=nodo->siguiente;
		var=nodo->dato;
		free(nodo);
		return var;
	}
	else{
		return 0;
	}
}

int size(char *formula){
	int iterador=0;
	while(formula[iterador]!='\0'){
		iterador++;
	}
	return iterador;
}
