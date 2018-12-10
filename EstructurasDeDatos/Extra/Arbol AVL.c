#include <stdio.h>
#include <stdlib.h>
#define DERECHA 1
#define IZQUIERDA 0
#define TRUE 1
#define FALSE 0

typedef struct nodo{
   int numero;
   int FE;
   struct nodo *derecho;
   struct nodo *izquierdo;
   struct nodo *padre;
 }*Nodo;
 
void Insertar(Nodo *, int );
void Eliminar_nodo(Nodo *, int );
int Buscar(Nodo , int );
int EsHoja(Nodo );
int Num_Nodos(Nodo , int* );
int Altura_Arbol(Nodo , int* );
int Nivel_Nodo(Nodo , int );
void InOrden(Nodo, void (*func)(int*));
void PreOrden(Nodo, void (*func)(int*));
void PostOrden(Nodo, void (*func)(int*));
void Equilibrar(Nodo *, Nodo, int, int);
void RSI(Nodo *, Nodo);
void RSD(Nodo *, Nodo );
void RDI(Nodo *, Nodo );                                                                                  
void RDD(Nodo *, Nodo );                                                                                                                                                                                                                         
void Eliminar_Arbol(Nodo *);
void auxContador(Nodo , int*);
void auxAltura(Nodo , int, int*);                                                                                                                                                                                                                                                                                        
void Mostrar(int *);

int main(){
   Nodo Arbol = NULL;   
   int i, num, ndatos, opcion;   
   do{   	
     printf("1. Insertar nodo.");
     printf("\n2.-Imprimir Arbol.");
     printf("\n3. Eliminar nodo.");
     printf("\n4. Eliminar Arbol.");
     printf("\n5. Salir.\n");     
     scanf("%d",&opcion);                                                                                                                                                                                                                    
     switch (opcion){
            case 1:	printf("Introduzca cuantos nodos insertar. \n");
					scanf("%d",&ndatos);
					printf("Introduzca los %d nodos. \n",ndatos);                   
                    for(i=1; i<=ndatos; i++){
                        scanf("%d",&num);                         
                    	Insertar(&Arbol, num); 
                    }
                    break;
			case 2: 
			        printf("InOrden : ");
                    InOrden(Arbol, Mostrar);
                    printf("\nPreOrden : ");
                    PreOrden(Arbol, Mostrar);
                    printf("\nPostOrden : ");
                    PostOrden(Arbol, Mostrar);                  
                    system("pause");
                    system("cls");
                    break;
                    
           case 3:  system("cls");           
                    printf("\n Introduzca dato a eliminar ");                    
                    scanf("%d", &num);                    
                    system("cls");
					Eliminar_nodo(&Arbol, num);                    
                    printf("Se ha eliminado el nodo %d.\n",num);                    
                    printf("InOrden : ");
                    InOrden(Arbol, Mostrar);
                    printf("\nPreOrden : ");
                    PreOrden(Arbol, Mostrar);
                    printf("\nPostOrden : ");
                    PostOrden(Arbol, Mostrar); 
                    system("PAUSE");
                    system("cls");
                    break;
           case 4:            
                    Eliminar_Arbol(&Arbol);                    
                    printf("ARBOL ELIMINADO.");                
                    system("PAUSE");                    
                    system("cls");                    
                    break;                   
           }  
     } while (opcion!=5);
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  }  

void Insertar(Nodo *nodo, int dato){
   Nodo padre = NULL;
   Nodo actual = *nodo;
  while(actual!=NULL && dato != actual->numero){
      padre = actual;
      if(dato < actual->numero)
	  	actual = actual->izquierdo;
      else if(dato > actual->numero)
    	actual = actual->derecho;                
    }
  if(actual!=NULL) 
   return;
   
  if(padre==NULL)
  {
      *nodo = (Nodo)malloc(sizeof(struct nodo));
      
      (*nodo)->numero = dato;
      
      (*nodo)->izquierdo = (*nodo)->derecho = NULL;
      
      (*nodo)->padre = NULL;
      
      (*nodo)->FE = 0;
  } 
                                                                                                                                                                                                            
  else if(dato < padre->numero)
  {
      actual = (Nodo)malloc(sizeof(struct nodo));
      
      padre->izquierdo = actual;
      
      actual->numero = dato;
      
      actual->izquierdo = actual->derecho = NULL;
      
      actual->padre = padre;
      
      actual->FE = 0;
      
      Equilibrar(nodo, padre, IZQUIERDA, TRUE);
  }
  else if(dato > padre->numero) 
  {
      actual = (Nodo)malloc(sizeof(struct nodo));
      
      padre->derecho = actual;
      
      actual->numero = dato;
      
      actual->izquierdo = actual->derecho = NULL;
      
      actual->padre = padre;
      
      actual->FE = 0;
      
      Equilibrar(nodo, padre, DERECHA, TRUE);
  }                                                                                                                                                     
}

void Equilibrar(Nodo *r, Nodo nodo, int rama, int dato){
   int salir = FALSE;
   
   while(nodo && !salir) 
   {
      if(dato != 0)
      
        if(rama == IZQUIERDA) 
        
          nodo->FE--; 
          
        else   
         
          nodo->FE++;
          
      else
      
        if(rama == IZQUIERDA) 
        
          nodo->FE++; 
          
        else   
        
          nodo->FE--;
          
      if(nodo->FE == 0)
      
        salir = TRUE; 
        
      else if(nodo->FE == -2) 
        { 
        if(nodo->izquierdo->FE == 1)
        
          RDD(r, nodo); 
          
        else 
        
          RSD(r, nodo);  
                                                                                            
      salir = TRUE;  
      
     }else if(nodo->FE == 2){ 
            
        if(nodo->derecho->FE == -1)
        
          RDI(r, nodo); 
          
        else 
        
          RSI(r, nodo); 
          
      salir = TRUE;
      }
      if(nodo->padre)
      
        if(nodo->padre->derecho == nodo)
        
          rama = DERECHA;
          
        else
        
          rama = IZQUIERDA;
          
     nodo = nodo->padre; 
   }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}

int EsHoja(Nodo nodo){
   return !nodo->derecho && !nodo->izquierdo;
}

void RDD(Nodo *r, Nodo nodo){
   Nodo Padre = nodo->padre;
   Nodo A = nodo;
   Nodo B = A->izquierdo;
   Nodo C = B->derecho;
   Nodo CI = C->izquierdo;
   Nodo CD = C->derecho;
   if(Padre)
     if(Padre->derecho == A)
       Padre->derecho = C;
     else 
       Padre->izquierdo = C;
   else
       *r = C;
   B->derecho = CI;
   A->izquierdo = CD;
   C->izquierdo = B;
   C->derecho = A;
   C->padre = Padre;
   A->padre = B->padre = C;    
   if(CI)   
     CI->padre = B;   
   if(CD)
     CD->padre = A;
                                                                                                     
  switch(C->FE) 
  {
      case -1: B->FE = 0; 
      
               A->FE = 1; 
               
               break;
               
      case 0:  B->FE = 0; 
      
               A->FE = 0;
               
               break;
               
      case 1:  B->FE = -1; 
      
               A->FE = 0; 
               
               break;
  }
   C->FE = 0;                                                                                                                                                                                                                   
}
                                                                                          
void RDI(Nodo *r, Nodo nodo){
   Nodo Padre = nodo->padre;
   Nodo A = nodo;
   Nodo B = A->derecho;
   Nodo C = B->izquierdo;
   Nodo CI = C->izquierdo;
   Nodo CD = C->derecho;
   if(Padre)
     if(Padre->derecho == A)
       Padre->derecho = C;
     else 
       Padre->izquierdo = C;
   else 
     *r = C;
    
   A->derecho = CI;
   B->izquierdo = CD;
   C->izquierdo = A;
   C->derecho = B;
   C->padre = Padre;
   A->padre = B->padre = C;
   if(CI)  
     CI->padre = A;
   if(CD)
     CD->padre = B;
     
   switch(C->FE) 
    {
      case -1: A->FE = 0;
      
               B->FE = 1; 
               
               break;
               
      case 0:  A->FE = 0;
      
               B->FE = 0; 
               
               break;
               
      case 1:  A->FE = -1;
      
               B->FE = 0; 
               
               break;
   }
   C->FE = 0;                                                                                                                                                                                                      
}

void RSD(Nodo *r, Nodo nodo){
   Nodo Padre = nodo->padre;
   Nodo A = nodo;
   Nodo B = A->izquierdo;
   Nodo C = B->derecho;
   if(Padre)
     if(Padre->derecho == A)
       Padre->derecho = B;
     else 
       Padre->izquierdo = B;
   else 
    *r = B;
       
   A->izquierdo = C;
   
   B->derecho = A;
   
   A->padre = B;
   
   if(C)
   
     C->padre = A;
     
   B->padre = Padre;
   
   A->FE = 0;
   
   B->FE = 0;                                                                                                                                                                    
}
                                                                                        
void RSI(Nodo *r, Nodo nodo){
   Nodo Padre = nodo->padre;
   Nodo A = nodo;
   Nodo B = A->derecho;
   Nodo C = B->izquierdo;
   if(Padre != NULL)
     if(Padre->derecho == A)
       Padre->derecho = B;
     else 
       Padre->izquierdo = B;
   else 
    *r = B;
       
   A->derecho = C;
   
   B->izquierdo = A;
   
   A->padre = B;
   
   if(C != NULL)
   
    C->padre = A;
    
   B->padre = Padre;
   
   A->FE = 0;
   
   B->FE = 0;                                                                                      
}

void Eliminar_nodo(Nodo *n, int dato){
   Nodo padre = NULL;   
   Nodo actual;   
   Nodo nodo;   
   int aux;   
   actual = *n;
   while(actual!=NULL) 
   {
      if(dato == actual->numero) 
      { 
         if(EsHoja(actual)!=0) 
         { 
            if(padre)
            
               if(padre->derecho == actual)
               
                  padre->derecho = NULL;
                
               else if(padre->izquierdo == actual) 
               
                  padre->izquierdo = NULL;
                  
            free(actual); 
            
            actual = NULL;
            
            if((padre->derecho == actual && padre->FE == 1) || (padre->izquierdo == actual && padre->FE == -1))                                               
               {
               padre->FE =	 0;
               
               actual = padre;
               
               padre = actual->padre;
               }
            if(padre)
            
               if(padre->derecho == actual)
               
                  Equilibrar(n, padre, DERECHA, FALSE);
                
               else 
                                       
                  Equilibrar(n, padre, IZQUIERDA, FALSE);
                  
            return;
            
          }else {
                 
            padre = actual;
            
            if(actual->derecho) 
            {
               nodo = actual->derecho;
               
               while(nodo->izquierdo) 
               {
                  padre = nodo;
                  
                  nodo = nodo->izquierdo;
               }
            }                                                                                                                                                              
                                                                                                      
           else{
                 
               nodo = actual->izquierdo;
               
               while(nodo->derecho) 
                {
                  padre = nodo;
                  
                  nodo = nodo->derecho;
                 }
              }
            
            aux = actual->numero;
            
            actual->numero = nodo->numero;
            
            nodo->numero = aux;
            
            actual = nodo;
           }
         
         }else { 
           
           padre = actual;
         
           if(dato > actual->numero)
         
             actual = actual->derecho;
          
           else if(dato < actual->numero) 
         
             actual = actual->izquierdo;
      }
   }                                                                                                
}                                                                                                                                                                                                                                                                                                                                                                                             

void InOrden(Nodo nodo, void (*func)(int*)){
   if(nodo->izquierdo)
   
      InOrden(nodo->izquierdo, func);
      
   func(&(nodo->numero));
   
   if(nodo->derecho) 
   
      InOrden(nodo->derecho, func);
}

void PreOrden(Nodo nodo, void (*func)(int*)){
   func(&nodo->numero);
   
   if(nodo->izquierdo)
   
      PreOrden(nodo->izquierdo, func);
      
   if(nodo->derecho)
   
      PreOrden(nodo->derecho, func);
}

void PostOrden(Nodo nodo, void (*func)(int*)){
   if(nodo->izquierdo) 
   
     PostOrden(nodo->izquierdo, func);
     
   if(nodo->derecho) 
   
     PostOrden(nodo->derecho, func);
     
   func(&nodo->numero);
}

void Mostrar(int *n){
   printf("%d, ", *n);
}

void Eliminar_Arbol(Nodo *nodo){
   if(*nodo != NULL){
      Eliminar_Arbol(&(*nodo)->izquierdo); 
      Eliminar_Arbol(&(*nodo)->derecho); 
      free(*nodo);   
      *nodo = NULL;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}
