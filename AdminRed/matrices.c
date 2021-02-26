#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct operando{
	int fila_init;
	int num_filas;
	int r1, c1;
	int** Matriz1;
	int r2,c2;
	int** Matriz2;
}OP;

void printMat(int** mat, int m, int n){
	int i, j;
	printf("Matriz %dx%d:\n", m, n);
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("  %d  ", mat[i][j]);
		}
		printf("\n");
	}
}

void* func(void *arg){
    OP *op = (OP*)arg;
	int** res;
	res = (int**)malloc(op->num_filas*sizeof(int*));
	for(int cs; cs < op->num_filas; cs++){
		res[cs] = (int*)malloc(op->c2*sizeof(int));
	}

    printf("Me llego los datos\n-Fila_init: %d\n-Num_filas: %d\n\n",op->fila_init,op->num_filas);

	for(int ij = op->fila_init; ij < (op->num_filas + op->fila_init); ij++){
		for (int i = 0; i < op->c2; i++) {
			int suma = 0;
			for (int j = 0; j < op->c1; j++) {
				suma += op->Matriz1[ij][j] * op->Matriz2[j][i];
			}
		res[ij - op->fila_init][i] = suma;
		}
	}

    pthread_exit(res);
}

int toFile(int r, int c, int mat[r][c], FILE *f){
	if(f == NULL){
		return -1;
	}else{
		int i, j;
		fprintf(f, "Matriz Resultante [%dx%d]:\n", r, c);
		for(i = 0; i < r; i++){
			for(j = 0; j < c; j++){
				fprintf(f, "%d   ", mat[i][j]);
			}
			fprintf(f,"\n");
		}
		return 0;
	}
}

int main(int argc, char *argv[]){
	int h_aux, f_aux;
	int c = 0;
	int num_h = atoi(argv[1]);
	pthread_t hilo[num_h];
	int m1_fila = atoi(argv[2]);
	int m1_columna = atoi(argv[3]);
	int m2_fila = atoi(argv[4]);
	int m2_columna = atoi(argv[5]);
	time_t t;
	
	
	if(argc <  6){
		printf("Numero incorrecto de argumentos\n");
		return 0;
	}else if(m1_columna != m2_fila){
		printf("Argumentos invalidos para la multuplicacion de matrices\n");
		return 0;
	}else if (num_h > m1_fila){
		printf("Numero de hilos incorrectos (sobrantes)\n");
		return 0;
	}

	//printf("Numero de argumentos: %d\n", argc);
	f_aux = m1_fila;
	h_aux = num_h;
	int arr[num_h];
	
	int **m1 = (int**)malloc(m1_fila*sizeof(int*));
	for(int row = 0; row < m1_fila; row++){
		m1[row] = (int*)malloc(m1_columna*sizeof(int));
	}
	int **m2 = malloc(m2_fila*sizeof(int));
	for(int row2 = 0; row2 < m2_fila; row2++){
		m2[row2] = (int*)malloc(m2_columna*sizeof(int));
	}
	srand(time(NULL));
	for(int i = 0; i < m1_fila; i++){
		for(int j = 0; j < m1_columna; j++){
			m1[i][j] = (rand() % 9) +1;
		}
	}
	srand(getpid());
	for(int k = 0; k < m2_fila; k++){
		for(int l = 0; l < m2_columna; l++){
			m2[k][l] = (rand() % 9) +1;
		}
	}
	printMat(m1,m1_fila,m1_columna);
	printMat(m2,m2_fila,m2_columna);

	printf("----------------------------------------------\n");
	while (h_aux > 0){
		float aux;
		aux =  (float)f_aux / h_aux;
		printf("%d / %d = %f\n",f_aux, h_aux, aux);
		arr[c] = ceil(aux);
		f_aux -= ceil(aux);
		h_aux--;
		c++;
	}

	printf("----------------------------------------------\n");
	OP arg_hilos[num_h];
	for(int r=0; r<num_h; r++){
		if(r==0){
			arg_hilos[r].fila_init = 0;
		}else{
			arg_hilos[r].fila_init = arr[r-1] + arg_hilos[r-1].fila_init;
		}
		
		arg_hilos[r].num_filas = arr[r];
		arg_hilos[r].r1 = m1_fila; 
		arg_hilos[r].c1 = m1_columna;
		arg_hilos[r].Matriz1 = m1;
		arg_hilos[r].r2 = m2_fila; 
		arg_hilos[r].c2 = m2_columna;
		arg_hilos[r].Matriz2 = m2;

		pthread_create(&hilo[r], NULL, func, &arg_hilos[r]);
	}
	int producto[m1_fila][m2_columna];
	for(int t=0; t<num_h; t++){
		int** salida; 
		pthread_join(hilo[t],&salida);

		for(int ij = arg_hilos[t].fila_init; ij < (arg_hilos[t].num_filas + arg_hilos[t].fila_init); ij++){
			for (int i = 0; i < arg_hilos[t].c2; i++) {
				for (int j = 0; j < arg_hilos[t].num_filas; j++) {
					producto[ij][i] = salida[ij - arg_hilos[t].fila_init][i];
				}
			}
		}	
	}

	/*printf("RES:\n");
	for(int loop = 0; loop < m1_fila; loop++){
		for(int loop2 = 0; loop2 < m2_columna; loop2++){
			printf("%d   ", producto[loop][loop2]);
		}
		printf("\n");
	}*/
	FILE *arch = fopen("Res.txt", "w"); 
	if(toFile(m1_fila, m2_columna, producto, arch))	
	return 0;
}
