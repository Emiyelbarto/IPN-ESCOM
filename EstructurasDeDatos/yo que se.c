#include <stdio.h>
#include <stdlib.h>
#define DERECHA 1
#define IZQUIERDA 0
#define TRUE 1
#define FALSE 0

typedef struct nodo 
 {
   int numero;
   int FE;
   struct nodo *derecho;
   struct nodo *izquierdo;
   struct nodo *padre;
 }*ptr;
 
void Insertar(ptr *nodo, int dato);
void Eliminar_nodo(ptr *n, int dato);
int Buscar(ptr n, int dato);
int EsHoja(ptr n);
int Num_Nodos(ptr n, int* c);
int Altura_Arbol(ptr n, int* altura);
int Nivel_Nodo(ptr n, int dato);
void InOrden(ptr, void (*func)(int*));
void PreOrden(ptr, void (*func)(int*));
void PostOrden(ptr, void (*func)(int*));
void Equilibrar(ptr *raiz, ptr nodo, int, int);
void RSI(ptr *r, ptr nodo);
void RSD(ptr *r, ptr nodo);
void RDI(ptr *r, ptr nodo);                                                                                  
void RDD(ptr *r, ptr nodo);                                                                                                                                                                                                                         
void Eliminar_Arbol(ptr *nodo);
void auxContador(ptr n, int*);
void auxAltura(ptr a, int, int*);                                                                                                                                                                                                                                                                                        
void Mostrar(int *n);

int main(){
   ptr Arbol = NULL;   
   int i, num, ndatos, opcion;
   
   do
    {
     printf("\n\n\n\n\n\n\n\n\n\n");
     printf("\n*********************");
     printf("\n1. Insertar nodo    *");
     printf("\n2. Nivel nodo       *");
     printf("\n3. Buscar nodo      *");
     printf("\n4. Eliminar nodo    *");
     printf("\n5. Eliminar árbol   *");
     printf("\n6. Salir            *");
     printf("\n*********************");
     
     printf("\n\n\n");
     
     printf(" Elija opción    ");
     
     scanf("%d",&opcion);  
     
   
   
                                                                                                                                                                                                                                                            
     switch (opcion)
        {
            case 1:   system("cls");
            
                      printf("\n Indique cuántos datos desea insertar      ");
                      
                      scanf("%d",&ndatos);
                      
                      system("cls");
                      
                      printf("\n Introduzca %d datos\n\n", ndatos);
                      
                      for(i=1; i<=ndatos; i++)
                        {
                          scanf("%d",&num);
                          
                          Insertar(&Arbol, num); 
                        } 
                      system("cls");
                      printf("\n Número nodos ----> %d ", Num_Nodos(Arbol, &num));
                      
                      printf("\n\n Altura `árbol ----> %d ", Altura_Arbol(Arbol, &num));
                      
                      printf("\n\n InOrden      ----> ");
                      InOrden(Arbol, Mostrar);
                      printf("\n\n PreOrden     ----> ");
                      PreOrden(Arbol, Mostrar);
                      printf("\n\n PostOrden    ----> ");
                      PostOrden(Arbol, Mostrar);
                      printf("\n\n\n\n\n\n\n\n");
                      
                      system("pause");
                      
                      system("cls");
                      break;                                                                                                         
                      
                      
                      
                      
                      
                                                                                                                                                                                                                                                                                                
            case 2:   system("cls");
            
                      printf("\n\n Introduzca nodo      ");
                      
                      scanf("%d", &num);
                      
                      system("cls");
                      
                      printf("\n\n Nivel de %d  ---->  %d\n",num, Nivel_Nodo(Arbol, num));
                      
                      printf("\n\n\n\n\n\n\n\n");
                      
                      system("PAUSE");
                      
                      system("cls");
                      
                      break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                                                                                                                                  
                     
           case 3:   system("cls"); 
           
                    printf("\n Introduzca dato a buscar      ");
                    
                    scanf("%d", &num);
                    
                    system("cls");
                    
                    Buscar(Arbol, num);
                    
                    printf("\n\n\n\n\n\n\n\n");
                    
                    system("PAUSE");
                    
                    system("cls");
                                                                                                                                                
                    break;  
                    
                    
           case 4:  system("cls");
           
                    printf("\n Introduzca dato a eliminar      ");
                    
                    scanf("%d", &num);
                    
                    system("cls");
                    
                    Eliminar_nodo(&Arbol, num);
                    
                    printf("\n\n Eliminado    ----> %d  ",num);
                    
                    printf("\n\n InOrden      ----> ");
                    
                    InOrden(Arbol, Mostrar);
                    
                    printf("\n\n Número nodos ----> %d", Num_Nodos(Arbol, &num));
                    
                    printf("\n\n Altura árbol ----> %d", Altura_Arbol(Arbol, &num));
                    
                    printf("\n\n\n\n\n\n\n\n");
                    
                    system("PAUSE");
                    
                    system("cls");
                    
                    break;
                                                                                                                                       
                    
                    
                    
                    
                    
           case 5:  system("cls");
            
                    Eliminar_Arbol(&Arbol);
                    
                    printf("\n ARBOL ELIMINADO");
                    
                    printf("\n\n\n\n\n\n\n\n");
                    
                    system("PAUSE");
                    
                    system("cls");
                    
                    break;
                    
          case 6:   break;
          
          default:  system("cls");
          
                    break;
           }  
     } while (opcion!=6);
     
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  } 

void Insertar(ptr *nodo, int dato)
{
   ptr padre = NULL;
   
   ptr actual = *nodo;
   
  while(actual!=NULL && dato != actual->numero) 
  {
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
      *nodo = (ptr)malloc(sizeof(struct nodo));
      
      (*nodo)->numero = dato;
      
      (*nodo)->izquierdo = (*nodo)->derecho = NULL;
      
      (*nodo)->padre = NULL;
      
      (*nodo)->FE = 0;
  } 
                                                                                                                                                                                                            
  else if(dato < padre->numero)
  {
      actual = (ptr)malloc(sizeof(struct nodo));
      
      padre->izquierdo = actual;
      
      actual->numero = dato;
      
      actual->izquierdo = actual->derecho = NULL;
      
      actual->padre = padre;
      
      actual->FE = 0;
      
      Equilibrar(nodo, padre, IZQUIERDA, TRUE);
  }
  else if(dato > padre->numero) 
  {
      actual = (ptr)malloc(sizeof(struct nodo));
      
      padre->derecho = actual;
      
      actual->numero = dato;
      
      actual->izquierdo = actual->derecho = NULL;
      
      actual->padre = padre;
      
      actual->FE = 0;
      
      Equilibrar(nodo, padre, DERECHA, TRUE);
  }                                                                                                                                                     
}

void Equilibrar(ptr *r, ptr nodo, int rama, int dato){
   int salir = FALSE;
   
   while(nodo && !salir) 
   {
      if(dato)
      
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

int EsHoja(ptr nodo){
   return !nodo->derecho && !nodo->izquierdo;
}

void RDD(ptr *r, ptr nodo){
   ptr Padre = nodo->padre;
   ptr A = nodo;
   ptr B = A->izquierdo;
   ptr C = B->derecho;
   ptr CI = C->izquierdo;
   ptr CD = C->derecho;
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

void RDI(ptr *r, ptr nodo){
   ptr Padre = nodo->padre;
   ptr A = nodo;
   ptr B = A->derecho;
   ptr C = B->izquierdo;
   ptr CI = C->izquierdo;
   ptr CD = C->derecho;
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

void RSD(ptr *r, ptr nodo){
   ptr Padre = nodo->padre;
   ptr A = nodo;
   ptr B = A->izquierdo;
   ptr C = B->derecho;
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
                                                                                             
void RSI(ptr *r, ptr nodo){
   ptr Padre = nodo->padre;
   ptr A = nodo;
   ptr B = A->derecho;
   ptr C = B->izquierdo;
   if(Padre)
     if(Padre->derecho == A) 
       Padre->derecho = B;
     else 
       Padre->izquierdo = B;
   else 
     *r = B;
       
   A->derecho = C;
   
   B->izquierdo = A;
   
   A->padre = B;
   
   if(C)
   
    C->padre = A;
    
   B->padre = Padre;
   
   A->FE = 0;
   
   B->FE = 0;
}

void Eliminar_nodo(ptr *n, int dato){
   ptr padre = NULL;   
   ptr actual;   
   ptr nodo;   
   int aux;   
   actual = *n;
   
   while(actual!=NULL) 
   {
      if(dato == actual->numero) 
      { 
         if(EsHoja(actual)) 
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
               padre->FE = 0;
               
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

void InOrden(ptr nodo, void (*func)(int*)){
   if(nodo->izquierdo)
   
      InOrden(nodo->izquierdo, func);
      
   func(&(nodo->numero));
   
   if(nodo->derecho) 
   
      InOrden(nodo->derecho, func);
}
void PreOrden(ptr nodo, void (*func)(int*)){
   func(&nodo->numero);
   
   if(nodo->izquierdo)
   
      PreOrden(nodo->izquierdo, func);
      
   if(nodo->derecho)
   
      PreOrden(nodo->derecho, func);
}
void PostOrden(ptr nodo, void (*func)(int*)){
   if(nodo->izquierdo) 
   
     PostOrden(nodo->izquierdo, func);
     
   if(nodo->derecho) 
   
     PostOrden(nodo->derecho, func);
     
   func(&nodo->numero);
}

int Buscar(ptr nodo, int dato)
{
   ptr actual = nodo;
   while(actual!= NULL) 
   {
      if(dato == actual->numero)
      { 
        printf("\n %d  EXISTE", dato);
        return TRUE;
      } 
      else if(dato < actual->numero)
         actual = actual->izquierdo; 
      else if(dato > actual->numero)
         actual = actual->derecho;
   }
    printf("\n %d  NO EXISTE", dato);
    return FALSE;                                                                                           
}

int Nivel_Nodo(ptr nodo, int dato){
   int altura = 0;
   ptr actual = nodo;
   while(actual != NULL)
     {
      if(dato == actual->numero)
        return altura; 
      else {
         altura++;
      if(dato < actual->numero) 
         actual = actual->izquierdo;
      else if(dato > actual->numero) 
         actual = actual->derecho;
      }
   }
   return -1;                                                                                                                                                                                                                                                    
}

void auxContador(ptr nodo, int *c){
   (*c)++; 
   if(nodo->izquierdo) 
   auxContador(nodo->izquierdo, c);
   if(nodo->derecho)  
    auxContador(nodo->derecho, c);
}

int Num_Nodos(ptr nodo, int *cont){
   *cont = 0;
   auxContador(nodo, cont); 
   return *cont;
}

void auxAltura(ptr nodo, int a, int *altura){
   if(nodo->izquierdo) 
   auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)
   auxAltura(nodo->derecho, a+1, altura);
   if(EsHoja(nodo) && a > *altura) 
   *altura = a;
}

int Altura_Arbol(ptr nodo, int *altura){
   *altura = 0;
   auxAltura(nodo, 0, altura); 
    return *altura;
}

void Mostrar(int *n){
   printf("%d, ", *n);
}

void Eliminar_Arbol(ptr *nodo){
   if(*nodo){
      Eliminar_Arbol(&(*nodo)->izquierdo); 
      Eliminar_Arbol(&(*nodo)->derecho); 
      free(*nodo);   
      *nodo = NULL;
	}
}
