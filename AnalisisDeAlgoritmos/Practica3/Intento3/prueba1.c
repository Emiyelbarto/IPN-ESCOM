#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int LongArreglo;
	float aux;
	int **Lista;
	int *ArregloPrincipal;
	printf("Escribir el tamaño del arreglo: \n");
	scanf("%d", &LongArreglo);
	ArregloPrincipal = calloc(0,sizeof(int) * LongArreglo);
	printf("El arreglo es: ");
	for (int i = 0; i < LongArreglo; ++i)
	{
		ArregloPrincipal[i] = (rand() % 1000) + 1;
		printf("%d\t", ArregloPrincipal[i]);
	}
	aux = LongArreglo;
	aux = aux / 2;
	printf("\nDivisión: %f\n", aux);
	printf("\n");
	return 0;
}