#include<stdio.h>
#include<stdlib.h>

struct nodo{
    char nombre;
    int celular;
    char correo;
    int edad;
    struct nodo *siguiente;
}Nontacto;

struct lista{
	struct nodo *primero;
	struct nodo *ultimo;
};

void menu();
struct nodo *crear_contacto(char nombre, int celular, char correo, int edad);
struct lista *agregar_contacto(struct lista *L, char nombre, int celular, char correo, int edad);

int main(){
	int opcion,salir=0, celular, edad;
	char correo[100], nombre[100];
	struct lista *Lista = NULL;
	/*
	correo = (char *)malloc(sizeof(char));
	nombre = (char *)malloc(sizeof(char));
	celular = (int *)malloc(sizeof(int));
	edad = (int *)malloc(sizeof(int));
	*/
	while(salir==0){
		opcion=-1;
		menu();
		scanf("%d",&opcion);
		
		if(opcion==6)salir=1;
		
		if(opcion==1){
			printf("Introducir el nombre, celular, correo y la edad separados por una coma. \n");
			fflush(stdin);
			scanf("%s,%d,%s,%d",&nombre,&celular,&correo,&edad);
			Lista = agregar_contacto(Lista, *nombre, celular, *correo, edad);
		}
		if(opcion==2){
			
		}
		if(opcion==3){
			
		}
		if(opcion==4){
			
		}
		if(opcion==5){
			
		}
	}
	return 0;
}

void menu(){	
	printf("*Menu de seleccion para Agenda.* \n");
    printf("1.- Agregar nuevo contacto. \n");
	printf("2.- Eliminar contacto. \n");
    printf("3.- Editar contacto. \n");
    printf("4.- Imprimir Agenda. \n"); 
	printf("5.- Leer txt. \n");
	printf("6.- Salir. \n");
}


struct lista *agregar_contacto(struct lista *L, char nombre, int celular, char correo, int edad){
	if(L!=NULL){
		struct nodo *nuevo_contacto = crear_contacto(nombre, celular, correo, edad);
			printf("prueba1");
		printf("Creando elemento con \n-Nombre: %s.\n-Celular:%d.\n-Correo:%s.\n-Edad: %d. \n",nombre,celular,correo,edad);
			printf("prueba2");
		L->ultimo->siguiente = nuevo_contacto;
		L->ultimo = nuevo_contacto;
		return L;
	}
	else{
		struct nodo *nuevo_contacto = crear_contacto(nombre, celular, correo, edad);
		struct lista *l = calloc(sizeof(struct lista),1);
		printf("Inicializando lista con \n-Nombre: %s.\n-Celular:%d.\n-Correo:%s.\n-Edad: %d. \n",nombre,celular,correo,edad);
		l->primero = nuevo_contacto;
		l->ultimo = nuevo_contacto;
		return l;
	}
}

struct nodo *crear_contacto(char nombre, int celular, char correo, int edad){
	
	struct nodo *nuevo_contacto = calloc(sizeof(struct lista),1);
	
	nuevo_contacto->nombre = nombre;
	nuevo_contacto->celular = celular;
	nuevo_contacto->correo = correo;
	nuevo_contacto->edad = edad;
	nuevo_contacto->siguiente = NULL;
	
	return nuevo_contacto;
}
