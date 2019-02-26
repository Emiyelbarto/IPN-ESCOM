#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int n, m, i, j, k=0, aux;
	int *A, *B, *C;
	printf("Escribir el tamanio del primer arreglo\n");
	scanf("%d",&n);
	printf("Escribir el tamanio del segundo arreglo\n");
	scanf("%d",&m);
	j = n + m;
	A = malloc(sizeof(int)*j);
	B = malloc(sizeof(int)*m);
	printf("Arreglo A: ");
	for(i = 0; i < n; i++){
		A[i] = rand() % 500;
		printf("%d\t",A[i]);
	}
	printf("\n");
	printf("Arreglo B: ");
	for(i = 0; i < m; i++){
		B[i] = rand() % 500;
		printf("%d\t",B[i]);
	}
	printf("\n");
	printf("Arreglo concatenado:");
	for(i = n; B[k] != '\0'; i++){
		A[i] = B[k];
		k++;
	}
	for(i = 0; i < j; i++)
		printf("%d\t", A[i]);
	printf("\nArreglo ordenado:");
	i=0;
	while(A[i] != '\0'){
		if(A[i] >= A[i+1]){
			aux = A[i];
			A[i] = A[i + 1];
			A[i + 1] = aux;
			i=0;
		}
		else{
			i++;
		}
	}
	for (i = 0; i < j; i++)
		printf("%d\t", A[i]);
	printf("\n");
	free(A);
	free(B);
		
}
