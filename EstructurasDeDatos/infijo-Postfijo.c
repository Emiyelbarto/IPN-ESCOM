#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	char operador;
	int precedencia;
	struct nodo *siguiente;
}Nodo;

typedef struct{
	Nodo *tope;
	int sizePila;
}Pila;

Nodo *pop(Pila *);
void push(Pila *,Nodo );
int isEmpty(Pila *);
void init(Pila *);
int sizePila(Pila *);
void imprimirPila(Pila *);
void limpiarBuffer();
int evaluarSigno(Pila *,Nodo );
int buscarParentesis(Pila *);
void llenarCadena(char );
int vaciarPila(Pila *);
void convertirExpresion(char *);
char *postfija;

int main(){
	printf("Este programa pasa una expresiOn matematica en notacIOn infija a postfija\n\nIntroduce tu expresion: ");
	char *infija;
	infija=malloc(100);
	postfija=malloc(100);
	scanf("%[^\n]",infija);
	limpiarBuffer();
	convertirExpresion(infija);
	return 0;
}

void limpiarBuffer(){
	int ch;
	while( (ch=getchar())!='\n' ){
            //printf( "--%d\n", ch );
	}
}

void init(Pila *pila){
	pila->tope=NULL;
	pila->sizePila=0;
}

int isEmpty(Pila *pila){
	int respuesta=0;
	if(pila->tope!=NULL)
		respuesta=0;//Tiene valores
	else
		respuesta=1;//esta vacia
	return respuesta;
}

Nodo* pop(Pila *pila){
	Nodo *aux;
	if(isEmpty(pila)==0){
		aux=pila->tope;
		pila->tope=pila->tope->siguiente;
	}else{
		printf("\n---La pila esta vacia---");
		aux=NULL;
	}
	imprimirPila(pila);
	return aux;
}

void push(Pila *pila, Nodo entrada){
	Nodo *aux;
	aux=(Nodo *)malloc(sizeof(Nodo));
	*aux=entrada;
	aux->siguiente=pila->tope;
	pila->tope=aux;
	pila->sizePila++;
	imprimirPila(pila);
}

void imprimirPila(Pila *pila){
	Nodo *aux;
	aux=(Nodo *)malloc(sizeof(Nodo));
	aux=pila->tope;
	printf("\n\nLa pila tienen un tamaño de:%d",pila->sizePila);
	printf("\n");
	printf("\n---");
	while(aux!=NULL){
		printf("\n %c",aux->operador);
		printf("\n---");
		aux=aux->siguiente;
	}
}

int evaluarSigno(Pila *pila, Nodo entrada){
	int flag=0,codigoError=0;
	Nodo *aux;
	do{
		if(entrada.precedencia==0){
			push(pila,entrada);
			flag=1;
		}else if(isEmpty(pila)==1){
			push(pila,entrada);
			flag=1;
		}else if(pila->tope->precedencia < entrada.precedencia){
			push(pila,entrada);
			flag=1;
		}else if(pila->tope->precedencia >= entrada.precedencia){
			aux=pop(pila);
			llenarCadena(aux->operador);
			free(aux);
			flag=0;
		}else{
			printf("\n\nOcurrio un error");
			codigoError=1;
		}
	}while(flag==0);
	return codigoError;
}

int buscarParentesis(Pila *pila){
	int codigoError=1;
	Nodo *aux;
	while(isEmpty(pila)==0){
		aux=pop(pila);
		if(aux->precedencia!=0){
			llenarCadena(aux->operador);
			free(aux);
		}else if(aux->precedencia==0){
			codigoError=0;
			break;
		}
	}
	if(codigoError==1){
		printf("\n***Error! El numero de parentesis es incorrecto ");
	}
	return codigoError;
}

void llenarCadena(char simbolo){
	int x=0;
	while(postfija[x]!='\0'){
		x++;
	}
	postfija[x]=simbolo;
	postfija[x+1]='\0';
}

int vaciarPila(Pila *pila){
	int codigoError=0;
	Nodo *aux;
	while(isEmpty(pila)==0){
		aux=pop(pila);
		if(aux->precedencia!=0){
			llenarCadena(aux->operador);
			free(aux);
		}else{
			codigoError=1;
			printf("\n***Error! El numero de parentesis es incorrecto");
			break;
		}
	}
	return codigoError;
}

void convertirExpresion(char *infija){
	int flag=0;
	int codigoError=0;
	Nodo nodo;//Se usa para abreviar el numero de elementos a enviar
	Pila pila;
	init(&pila);
	int x=0; //'x' es el contador para la cadena infija
	while(infija[x]!='\0' && codigoError==0){
		if(infija[x]>=65 && infija[x]<=90){
			llenarCadena(infija[x]);
		}else{
			switch(infija[x]){
				case ')':
				codigoError=buscarParentesis(&pila);
				break;
				case '(':
				//printf("\nsigno de precedencia 0");
				nodo.operador=infija[x];
				nodo.precedencia=0;
				nodo.siguiente=NULL;
				codigoError=evaluarSigno(&pila,nodo);
				break;
				case '+': case '-':
				//printf("\nsigno de precedencia 1");
				nodo.operador=infija[x];
				nodo.precedencia=1;
				nodo.siguiente=NULL;
				codigoError=evaluarSigno(&pila,nodo);
				break;
				case '*': case '/':
				//printf("\nsigno de precedencia 2");
				nodo.operador=infija[x];
				nodo.precedencia=2;
				nodo.siguiente=NULL;
				codigoError=evaluarSigno(&pila,nodo);
				break;
				case '^':
				//printf("\nsigno de precedencia 3");
				nodo.operador=infija[x];
				nodo.precedencia=3;
				nodo.siguiente=NULL;
				codigoError=evaluarSigno(&pila,nodo);
				break;
				default:
				codigoError=1;
				printf("El símbolo no es valido");
				break;
			}
		}
		x++;
	}
	if(isEmpty(&pila)==0){
		codigoError=vaciarPila(&pila);
	}
	if(codigoError==1){
		printf("\nLa expresión %s es incorrecta\n",infija);
	}else{
		printf("\nExpresión postfija: %s\n",postfija);
	}
}

