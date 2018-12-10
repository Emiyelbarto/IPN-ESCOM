#include<stdio.h>
#include<stdlib.h>

#define DERECHA 1
#define IZQUIERDA 0
#define TRUE 1
#define FALSE 0

typedef struct nodo{
	int Valor;
	int Factor;
	struct nodo *derecha;
	struct nodo *izquierda;
	struct nodo *padre;
}*Nodo;

int menu();
void Insertar(Nodo *, int);
void Eliminar_Nodo(Nodo *, int);
int Buscar(Nodo , int);
int Hoja(Nodo);
int Num_Nodos(Nodo, int *);
int Altura_Arbol(Nodo , int *);
int Nivel_Nodo(Nodo , int );
void Equilibrar(Nodo *, Nodo , int , int);
void Leer_txt(Nodo *);
void Imprimir(Nodo );
void Preorden(Nodo , void (*funcion)(int *));
void Inorden(Nodo , void (*funcion)(int *));
void Postorden(Nodo , void (*funcion)(int *));
void Rotacion_Simple_Derecha(Nodo *, Nodo);
void Rotacion_Simple_Izquierda(Nodo *, Nodo);
void Rotacion_Doble_Derecha(Nodo *, Nodo);
void Rotacion_Doble_Izquierda(Nodo *, Nodo);
void Aux_Contadores(Nodo, int *);
void Mostrar(int *);

int main(){
	int opcion, dato;
	Nodo Arbol = NULL;
	
	opcion = menu();
	while(opcion != 4){
		opcion = menu();
		switch(opcion){
			case 1:
				printf("Introduzca el nodo a insertar: \n");
				scanf("%d",&dato);
				Insertar(&Arbol,dato);
				break;
			case 2:
				Imprimir(Arbol);
				system("PAUSE");
				break;
			case 3:
				printf("Insertar el nodo a eliminar. \n");
				scanf("%d",&dato);
				Eliminar_Nodo(&Arbol,dato);
				system("PAUSE");
				break;
		}
	system("cls");
	}
	return 1;
}

int menu(){
	int i;
	printf("1.-Insertar dato.\n2.-Imprimir Arbol.\n3.-Eliminar nodo\n4.-Salir.\n");
	scanf("%d",&i);
	return i;
}

void Insertar(Nodo *Arbol, int dato){
	Nodo Padre, actual;
	Padre = NULL;
	actual = *Arbol;
	
	while(actual != NULL && dato != actual->Valor){
		Padre = actual;
		if(dato < actual->Valor){
			actual = actual->izquierda;
		}
		else if(dato > actual->Valor){
			actual = actual->derecha;
		}
	}
	
	if( actual != NULL ){
		return ;
	}
	
	if(Padre == NULL){
		*Arbol = (Nodo)malloc(sizeof(struct nodo));
		(*Arbol)->Valor = dato;
		(*Arbol)->derecha = NULL;
		(*Arbol)->izquierda = NULL;
		(*Arbol)->padre = NULL;
		(*Arbol)->Factor = 0;
	}else if(dato < Padre->Valor){
		actual = (Nodo)malloc(sizeof(struct nodo));
		Padre->izquierda = actual;
		actual->Valor = dato;
		actual->izquierda = NULL;
		actual->derecha = NULL;
		actual->padre = Padre;
		actual->Factor = 0;
		Equilibrar(Arbol,Padre,IZQUIERDA,TRUE);
	}else if(dato > Padre->Valor){		
		actual = (Nodo)malloc(sizeof(struct nodo));
		Padre->derecha = actual;
		actual->Valor = dato;
		actual->izquierda = NULL;
		actual->derecha = NULL;
		actual->padre = Padre;
		actual->Factor = 0;
		Equilibrar(Arbol,Padre,DERECHA,TRUE);
	}
}

void Eliminar_Nodo(Nodo *x, int dato){
   Nodo padre = NULL, actual, nodo;
   int aux;
   actual = *x;
   
   while(actual!=NULL){
      if(dato == actual->Valor){ 
         if(Hoja(actual)!=0){
            if(padre != NULL){
               if(padre->derecha == actual)
				padre->derecha = NULL;
               else if(padre->izquierda == actual)
				padre->izquierda = NULL;
        	}
        	free(actual);
            actual = NULL;
            
            if((padre->derecha == actual && padre->Factor == 1) || (padre->izquierda == actual && padre->Factor == -1))                                               
               {
               padre->Factor =	 0;
               
               actual = padre;
               
               padre = actual->padre;
               }
            if(padre != NULL)
				if(padre->derecha == actual)
					Equilibrar(x, padre, DERECHA, FALSE);
				else
					Equilibrar(x, padre, IZQUIERDA, FALSE);
			return;
		}else{
			padre = actual;
			if(actual->derecha){
               nodo = actual->derecha;
			   while(nodo->izquierda){
                  padre = nodo;
				  nodo = nodo->izquierda;
               }
            }else{
				nodo = actual->izquierda;
				while(nodo->derecha){
                  padre = nodo;
				  nodo = nodo->derecha;
				}
			}
			aux = actual->Valor;
			actual->Valor = nodo->Valor;
			nodo->Valor = aux;
			actual = nodo;
		}
		}else {
			padre = actual;
			if(dato > actual->Valor)
				actual = actual->derecha;
			else if(dato < actual->Valor)
				actual = actual->izquierda;
      }
   }             
   printf("El nodo %d ha sido eliminado.\n");                                                                                   
}

/*void Leer_txt(Nodo *Arbol){	
	int dato;
	FILE *archivo;
	char *nombrearchivo= "C:/Users/José Emiliano Pérez/Documents/Practica.txt";
	
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
*/
void Imprimir(Nodo Arbol){
	if(Arbol != NULL){
		printf("Preorden : ");
		Preorden(Arbol,Mostrar);
		printf("\nInorden : ");
		Inorden(Arbol,Mostrar);
		printf("\nPostorden : ");
		Postorden(Arbol,Mostrar);
	}
	printf("\n");
}

void Preorden(Nodo Arbol, void (*funcion)(int *)){
	funcion(&Arbol->Valor);
	if(Arbol->izquierda != NULL){
		Preorden(Arbol->izquierda, funcion);
	}
	if(Arbol->derecha != NULL){
		Preorden(Arbol->derecha, funcion);
	}
}

void Inorden(Nodo Arbol, void (*funcion)(int *)){
	if(Arbol->izquierda != NULL){
		Inorden(Arbol->izquierda, funcion);
	}
	funcion(&(Arbol->Valor));
	if(Arbol->derecha != NULL){
		Inorden(Arbol->derecha,funcion);
	}
}

void Postorden(Nodo Arbol, void(*funcion)(int *)){
	if(Arbol->izquierda != NULL){
		Postorden(Arbol->izquierda , funcion);
	}
	if(Arbol->derecha != NULL){
		Postorden(Arbol->derecha , funcion);
	}
	funcion(&Arbol->Valor);
}

void Rotacion_Simple_Derecha(Nodo *Raiz, Nodo desequilibrado){
   Nodo Padre,A,B,C;
   Padre = desequilibrado->padre;
   A = desequilibrado;
   B = A->izquierda;
   C = B->derecha;
   if(Padre != NULL){
     if(Padre->derecha == A)
       Padre->derecha = B;
     else 
       Padre->izquierda = B;
   }
   else{
   *Raiz = B;
   A->izquierda = C;
   B->derecha = A;
   A->padre = B;
   if(C != NULL){
		C->padre = A;
   }
   B->padre = Padre;
   A->Factor = 0;
   B->Factor = 0;
   }
}

void Rotacion_Simple_Izquierda(Nodo *Raiz, Nodo desequilibrado){
	Nodo Padre, A, B, C;
	Padre = desequilibrado->padre;
	A = desequilibrado;
	B = A->derecha;
	C = B->izquierda;
	
	if(Padre != NULL){
		if(Padre->derecha == A){
			Padre->derecha = B;
		}
		else{
			Padre->izquierda = B;
		}
	}
	else{
		*Raiz = B;
		A->derecha = C;
		B->izquierda = A;
		A->padre = B;
	}
	if(C != NULL){
		C->padre = A;
		B->padre = Padre;
		A->Factor = 0;
		B->Factor = 0;
	}
}

void Rotacion_Doble_Izquierda(Nodo *Raiz, Nodo desequilibrado){
	Nodo Padre, A,B,C,C_Izquierda,C_Derecha;
	Padre = desequilibrado->padre;
	A = desequilibrado;
	B = A->derecha;
	C = A->izquierda;
	C_Izquierda = C->izquierda;
	C_Derecha = C->derecha;
	if(Padre != NULL){
		if(Padre->derecha == A){
			Padre->derecha = C;
		}
		else{
			Padre->izquierda = C;
		}
	}
	else{
		*Raiz = C;
		A->derecha = C_Izquierda;
		B->izquierda = C_Derecha;
		C->izquierda = A;
		C->derecha = B;
		C->padre = Padre;
		A->padre = B->padre = C;
		
		if(C_Izquierda != NULL){
			C_Izquierda->padre = A;
		}
		
		if(C_Derecha != NULL){
			C_Derecha->padre = B;
		}
		
		if(C->Factor == -1){
			A->Factor = 0;
			B->Factor = 1;
		}
		else if(C->Factor == 0){
			A->Factor = 0;
			B->Factor = 0;
		}
		else if(C->Factor == 1){
			A->Factor = -1;
			B->Factor = 0;
		}
	C->Factor = 0;
	}
}

void Rotacion_Doble_Derecha(Nodo *Raiz, Nodo desequilibrado){
	Nodo Padre, A,B,C,D,E;
	Padre = desequilibrado->padre;
	A = desequilibrado;
	B = A->izquierda;
	C = B->derecha;
	D = C->izquierda;
	E = C->derecha;
	
	if(Padre != NULL){
		if(Padre->derecha == A){
			Padre->derecha = C;
		}
		else{
			Padre->izquierda = C;
		}
	}
	else{
		*Raiz = C;
		B->derecha = D;
		A->izquierda = E;
		C->izquierda = B;
		C->derecha = A;
		C->padre = Padre;
		A->padre = B->padre = C;
		if(D != NULL){
			D->padre = B;
		}
		
		if(E != NULL){
			E->padre = A;
		}
		
		if(C->Factor == -1){
			B->Factor = 0;
			A->Factor = 1;
		}
		else if(C->Factor == 0){
			B->Factor = 0;
			A->Factor = 0;
		}
		else if(C->Factor == 1){
			B->Factor = -1;
			A->Factor = 0;
		}
	C->Factor = 0;
	}
}

void Equilibrar(Nodo *Raiz, Nodo desequilibrado, int rama, int dato){
	int salir = FALSE;
	while(desequilibrado && !salir){
		if(dato){
			if(rama == IZQUIERDA){
				desequilibrado->Factor --;
			}
			else{
				desequilibrado->Factor ++;
			}
		}
		else{
			if(rama == IZQUIERDA){
				desequilibrado->Factor ++;
			}
			else{
				desequilibrado->Factor --;
			}
		}
		
		if(desequilibrado->Factor == 0){
			salir = TRUE;
		}
		else if(desequilibrado->Factor == -2){
			if(desequilibrado->izquierda->Factor == 1){
				Rotacion_Doble_Derecha(Raiz,desequilibrado);
			}
			else{
				Rotacion_Simple_Derecha(Raiz,desequilibrado);	
			}
		salir = TRUE;
		}
		else if(desequilibrado->Factor == 2){
			if(desequilibrado->derecha->Factor == -1){
				Rotacion_Doble_Izquierda(Raiz,desequilibrado);
			}
			else{
				Rotacion_Simple_Izquierda(Raiz,desequilibrado);
			}
		salir = TRUE;
		}
		
		if(desequilibrado->padre != NULL){
			if(desequilibrado->padre->derecha == desequilibrado){
				rama = DERECHA;
			}
			else{
				rama = IZQUIERDA;
			}
			desequilibrado = desequilibrado->padre;
		}
	}
}

int Hoja(Nodo n){
	return !n->derecha && !n->izquierda;
}

void Numeros_Arbol(int *n){
	printf("%d, ", *n);
}
void Mostrar(int *n){
   printf("%d, ", *n);
}
