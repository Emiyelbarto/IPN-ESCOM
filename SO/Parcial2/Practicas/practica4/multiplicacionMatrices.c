#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define lectura 0
#define escritura 1

int** crearMatriz(unsigned long numeroFilas, unsigned long numeroColumnas, int tipo){
	int **matriz;
	int i, j;

	matriz = (int**)malloc(numeroFilas*sizeof(int*));
	for(i = 0; i < numeroFilas; i++){
		matriz[i] = (int*)malloc(numeroColumnas*sizeof(int));
	}

	if(tipo == 0){
		srand(time(NULL));
		for(i = 0; i < numeroFilas; i++){
			for(j = 0; j < numeroColumnas; j++){
				matriz[i][j] = rand()%5;
			}
		}
	}else if(tipo == 1){
		for(i = 0; i < numeroFilas; i++){
			for(j = 0; j < numeroColumnas; j++){
				matriz[i][j] = 0;
			}
		}
	}
	//sleep(1);
	return matriz;
}

void mostrarMatriz(int** matriz, unsigned long numeroFilas, unsigned long numeroColumnas){
	int i, j;

	for(i = 0; i < numeroFilas; i++){
		printf("\n");
		for(j = 0; j < numeroColumnas; j++){
			printf("%d ", matriz[i][j]);
		}
	}
}

int calcularFilasProceso(int numeroProcesoEjecutandose, unsigned long numeroFilas, unsigned long numeroProcesos){
	if(numeroFilas%numeroProcesos == 0){
		return (numeroFilas/numeroProcesos)*numeroProcesoEjecutandose;
	}else{
		if(numeroProcesoEjecutandose == numeroProcesos){
			return ((numeroFilas/numeroProcesos)*numeroProcesoEjecutandose)+(numeroFilas%numeroProcesos);
		}else{
			return (numeroFilas/numeroProcesos)*numeroProcesoEjecutandose;
		}
	}
}

int **multiplicarMatrices(int** matrizResultante, int** matrizA, int** matrizB, unsigned long numeroFilasA, unsigned long numeroColumnasA, unsigned long numeroColumnasB, unsigned long numeroProcesos){
	int i, j, k, i2, j2;
	int status[numeroProcesos];
	pid_t proceso;

	int p[2];
	pipe(p);

	int matrizResultante2[numeroFilasA][numeroColumnasB];
	int **matrizResultanteFinal = crearMatriz(numeroFilasA, numeroColumnasB, 1);

	for(i2 = 0; i2 < numeroProcesos; i2++){
		switch(proceso = fork()){
			case 0:
				close(p[lectura]);
				for(i = calcularFilasProceso(i2, numeroFilasA, numeroProcesos); i < calcularFilasProceso(i2+1, numeroFilasA, numeroProcesos); i++){
					for(j = 0; j < numeroColumnasB; j++){
						for(k = 0; k < numeroColumnasA; k++){
							matrizResultante[i][j] += (matrizA[i][k]*matrizB[k][j]);
						}
						matrizResultante2[i][j] = matrizResultante[i][j];
						//printf("%d ", matrizResultante[i][j]);
					}
					write(p[escritura], &matrizResultante2[i], sizeof(matrizResultante2[i]));
					//printf(" esta fila fue hecha por el proceso %d\n", getpid());
				}
				close(p[escritura]);
				exit(0);
			break;
			
			default:
				if(i2 == (numeroProcesos-1)){
					close(p[escritura]);
					for(i = 0; i < numeroFilasA; i++){
						read(p[lectura], &matrizResultante2[i], sizeof(matrizResultante2[i]));
						for(j = 0; j < numeroColumnasB; j++){
							matrizResultanteFinal[i][j] = matrizResultante2[i][j];
							//printf("%d ", matrizResultante2[i][j]);
						}
						//printf("\n");
					}
					close(p[lectura]);
					for(j2 = 0; j2 < numeroProcesos; j2++){
						wait(&status[j2]);
					}
					return matrizResultanteFinal;
				}
			break;
		}
	}
}

int main(){

	unsigned long filasMatrizA, columnasMatrizA, columnasMatrizB, numeroProcesos;
	int **matrizA, **matrizB, **matrizResultante, **matrizResultanteFinal;

	printf("Numero de filas de la matriz A: ");
	setbuf(stdin, NULL);
	scanf("%lu", &filasMatrizA);
	printf("Numero de columnas de la matriz A: ");
	setbuf(stdin, NULL);
	scanf("%lu", &columnasMatrizA);
	printf("Numero de columnas de la matriz B: ");
	setbuf(stdin, NULL);
	scanf("%lu", &columnasMatrizB);
	printf("Numero de procesos: ");
	setbuf(stdin, NULL);
	scanf("%lu", &numeroProcesos);

	if(numeroProcesos > filasMatrizA){
		printf("Error: hay mas procesos que filas\n");
		return 0;
	}else{
		//CREACION DE LAS MATRICES
		matrizA = crearMatriz(filasMatrizA, columnasMatrizA, 0);
		matrizB = crearMatriz(columnasMatrizA, columnasMatrizB, 0);

		//MUESTRA DE MATRICES
		printf("\nMatriz A:");
		mostrarMatriz(matrizA, filasMatrizA, columnasMatrizA);
		printf("\n\nMatriz B:");
		mostrarMatriz(matrizB, columnasMatrizA, columnasMatrizB);

		//CREACION DE LA MATRIZ RESULTANTE
		matrizResultante = crearMatriz(filasMatrizA, columnasMatrizB, 1);

		//MULTIPLICACION DE MATRICES EN MATRIZ RESULTANTE
		printf("\n\nMatriz resultante:\n");
		matrizResultanteFinal = multiplicarMatrices(matrizResultante, matrizA, matrizB, filasMatrizA, columnasMatrizA, columnasMatrizB, numeroProcesos);
		mostrarMatriz(matrizResultanteFinal, filasMatrizA, columnasMatrizB);
		printf("\n");
	}

	return 0;
}