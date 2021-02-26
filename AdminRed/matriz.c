#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

//Funciones uwu

void * trabajoHilo(void *arh);
int verificacionArgumentos(int argc,char **argv);
void asignarMemoria(int *matriz[], int n_filas, int n_columnas);
void creacionMatriz(int *matriz[], int n_filas, int n_columnas);
void imprimirMatriz(int *matriz[], int n_filas, int n_columnas);
void liberarMatriz(int *matriz[], int n_filas, int n_columnas);

//variables compartidas
int **mA,**mB,**mR;
int inicio,fin;

typedef struct

int main(int argc, char *argv[]) {
  srand(time(NULL));
  
  if(!verificacionArgumentos(argc,argv)){
    printf("Ejecucion mal lograda.\n");
    return 0;
  }

  int filas_1=atoi(argv[1]), columnas_1=atoi(argv[2]);
  int filas_2=atoi(argv[3]), columnas_2=atoi(argv[4]);
  int n_hilos=atoi(argv[5]);
  int *m1[filas_1], *m2[filas_2], *mF[columnas_1];
  int rango = filas_1/n_hilos;
  int sobrante = filas_1%n_hilos;
  fin=rango;
  inicio=0;
  //mult contenido[n_hilos];
  pthread_t hilos[n_hilos];
  int err;

  asignarMemoria(m1,filas_1,columnas_1);
  asignarMemoria(m2,filas_2,columnas_2);
  
  creacionMatriz(m1,filas_1,columnas_1);
  creacionMatriz(m2,filas_2,columnas_2);

  printf("Matriz 1:\n");
  imprimirMatriz(m1,filas_1,columnas_1);

  printf("Matriz 2:\n");
  imprimirMatriz(m2,filas_2,columnas_2);

  mA=m1;
  mB=m2;

  //printf("Llegas aqui entra\n");
  asignarMemoria(mF,columnas_1,filas_2);
  //printf("Llegas aqui sales\n");*/
  mR=mF;
  for(int i=0;i<n_hilos;i++){
    if(i==n_hilos-1){
      err = pthread_create(&hilos[i], NULL, trabajoHilo,(void *)columnas_2);
    }else{
      err = pthread_create(&hilos[i], NULL, trabajoHilo,(void *)columnas_2);
    }
    if (err != 0){
      printf ("can't create thread: %s\n", strerror(err));
    }
    sleep(3);
    /*inicio += rango;
		fin += rango;*/
  }

  for(int i=0;i<n_hilos;i++){
    err = pthread_join(hilos[i], NULL);
    if (err != 0){
      printf ("can't create thread: %s\n", strerror(err));
    }
  }
  imprimirMatriz(mR,columnas_1,filas_2);

  liberarMatriz(m1,filas_1,columnas_1);
  liberarMatriz(m2,filas_2,columnas_2);
  liberarMatriz(mF,filas_2,columnas_2);
  

  liberarMatriz(mA,filas_1,columnas_1);
  liberarMatriz(mB,filas_2,columnas_2);
  liberarMatriz(mR,filas_2,columnas_2);
  
  return 0;
}

void * trabajoHilo(void *arg){
  int ncolumnas = (int)arg;
  int i, j, k, p, n, val, fila[ncolumnas];
	for( i = inicio ; i < fin ; i++ ){
		for( n = 0 , p = 0 ; n < ncolumnas ; n++ , p++ ){
			val = 0;
			for( j = 0 ; j < ncolumnas ; j++ )
				val += mA[i][j] * mB[j][n]; 
			mR[i][p] = val;
		}	
	}
  sleep(3);
  pthread_exit(NULL);
}

int verificacionArgumentos(int argc, char **argv){
  if(argc!=6){
    printf("Ejecucion con parametros inexactos no_filas_m1, no_columnas_m1, " 
    "no_filas_m2, no_columnas_m2, no_hilos\n");
    return 0;
  }
  if(atoi(argv[1])!=atoi(argv[4])){
    printf("Las matrices no cumplen con el tamanio adecuado no_filas_m1 = no_columnas_m2\n");
    return 0;
  }
  if(atoi(argv[1])<atoi(argv[5])){
    printf("De momento no podemos permitir que el numero de hilos supere el numero de filas\n");
    return 0;
  }
  return 1;
}

void asignarMemoria(int *matriz[], int n_filas, int n_columnas){
  int i;
  for(int i=0; i<n_filas; i++){
    matriz[i]=(int *)malloc (sizeof(int)*n_columnas);
  }
}

void creacionMatriz(int *matriz[], int n_filas, int n_columnas){
  for(int i=0;i<n_filas;i++){
    for(int j=0;j<n_columnas;j++){
      matriz[i][j]=(rand() % 5)+1;
    }
  }
}

void imprimirMatriz(int *matriz[], int n_filas, int n_columnas){
  for(int i=0;i<n_filas;i++){
    for(int j=0;j<n_columnas;j++){
      printf(" %i ",matriz[i][j]);
    }
    printf("\n");
  }
}

void liberarMatriz(int *matriz[], int n_filas, int n_columnas){
  for(int i=0;i<n_filas;i++){
    for(int j=0;j<n_columnas;j++){
      free(matriz[j]);
    }
    //free(matriz[i]);
  }
  //printf("Llega\n");
}