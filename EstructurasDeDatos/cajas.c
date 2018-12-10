#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int dinero;
	struct nodo *siguiente;
}Nodo;

typedef struct{
	Nodo *primer;
	Nodo *ultimo;
	int size, caja;
}Queue;

void leertxt(Queue *Fila);
void imprimir_menu();
void meter_cliente(Queue *Fila);
void meter_clientetxt(Queue *Fila, Nodo *cliente);
int despachar_cliente(Queue *Fila);
int Sacar_cuenta(Queue *Fila);

int main(){
	Queue *Fila;
	Fila=malloc(5 * sizeof(Queue));
	Fila->primer = NULL;
	Fila->ultimo = NULL;
	Fila->size = 0;
	
	int salir=0;
	int opcion;
	
	leertxt(Fila);
	
	while(salir==0){
		opcion=-1;
		
		imprimir_menu();
		
		fflush(stdin);		
		scanf("%d",&opcion);
		
		if(opcion==4)salir==1;
		
		if(opcion==1){
			meter_cliente(Fila);
		}
		if(opcion==2){
			despachar(Fila);
						
		}
		if(opcion==3){
			sacar_cuenta(Fila);
		}
		if(opcion==4){
			salir = 1;
		}
	}
	return 0;
}

void imprimir_menu(){
	printf("\n *Menu de seleccion para Cajeros.* \n");
    printf("1.- Agregar nuevo cliente. \n");
	printf("2.- Despachar. \n");
    printf("3.- Sacar cuenta. \n");
    printf("4.- Salir. \n");    
}

void meter_clientetxt(Queue *Fila, Nodo *cliente){
	if(Fila->primer == NULL){
		Fila->primer = cliente;
		Fila->ultimo = cliente;
	}
	else{
		Fila->ultimo = cliente;
		cliente->siguiente = NULL;
	}
}

void meter_cliente(Queue *Fila){
	Nodo *nuevo_cliente, *auxiliar;
	nuevo_cliente= (Nodo *)malloc(sizeof(Nodo));
	auxiliar = (Nodo *)malloc(sizeof(Nodo));
	
	(nuevo_cliente->siguiente) = NULL;
	
	printf("Introducir la caja a la que ira el nuevo cliente. \n");
	scanf("%d",&(Fila->caja));
	if(Fila->caja>5){
		printf("El numero introducido de caja no es valido. \n");
	}
	else{
	printf("Introducir cuanto va a gastar. \n");
	scanf("%d",&(nuevo_cliente->dinero));
	Fila->ultimo = nuevo_cliente;
	
	}
	Fila->size++;
	printf("El tamano de la fila es: %d. \n",Fila->size);
}

void leertxt(Queue *Fila){
	
	Nodo *cliente;
	cliente = (Nodo *)malloc(sizeof(Nodo));
	
	FILE *archivo;
	char *nombrearchivo= "C:/Users/José Emiliano Pérez/Documents/dollars.txt";
	
	archivo = fopen(nombrearchivo, "r");

	if(archivo == NULL){
		printf("\n No se pudo leer el txt. \n");
		return;
	}
	
	printf("El txt contiene los siguientes elementos: \n");
	
	while(!feof(archivo)){
		fscanf(archivo,"%d , %d ",&(Fila->caja),&(cliente->dinero));
		meter_clientetxt(Fila, cliente);
		(Fila->size)++;
		printf(" %d, %d, tamano de la fila: %d. \n",Fila->caja,cliente->dinero,Fila->size);
	}
	fclose(archivo);
}

int despachar(Queue *Fila){
	int suma = 0,i;
	
	if(Fila->primer == NULL){
		printf("No hay ningun cliente en caja. \n");
		return -1;
	}
	if(Fila->size < 1){
		printf("La fila esta vacia. \n");
		return 1;
	}
	
	for(i=0;i<(Fila->caja);i++){
		printf("\n***prueba.***\n");
		suma = ((Fila[i].primer->dinero) + suma );
		printf("----------\nLa caja %d tiene %d pesos.\n----------",i+1,suma);
	}
	Fila->size --;
	printf("\nEl tamano de la fila ahora es: %d. \n",Fila->size);
	return suma;	
}

int sacar_cuenta(Queue *Fila){
	int suma_total=0,i;
	
	if(Fila->size=0){
		printf("----------\nLas cajas no tienen dinero.\n----------");
	}
	for(i=0;i<Fila->caja;i++){
		suma_total= (Fila->primer->dinero + suma_total);
	}
	printf("----------\nLa cuenta es: %d.\n----------",suma_total);
	
		
	
	
}
