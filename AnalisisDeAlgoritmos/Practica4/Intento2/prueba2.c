#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{	
	srand(time(NULL));
	char *A, *B;
	int tam1, tam2, aux;
	printf("Introducir el tamaño del arreglo 1:\n");
	scanf("%d",&tam1);
	while(tam1 <= 0)
	{
		printf("El numero debe ser mayor a cero!\nIntroducir el tamaño del arreglo 1 nuevamente:\n");
		fflush(stdin);
		scanf("%d",&tam1);
	}
	printf("Introducir el tamaño del arreglo 2:\n");
	scanf("%d",&tam2);
	while(tam2 <= 0)
	{
		printf("El numero debe ser mayor a cero!\nIntroducir el tamaño del arreglo 2 nuevamente:\n");
		fflush(stdin);
		scanf("%d",&tam2);
	}
	if(tam2 > tam1)
	{
		aux = tam1;
		tam1 = tam2;
		tam2 = aux;
	}
	A = malloc(tam1);
	B = malloc(tam2);	
	printf("El arreglo 1 es: ");
	for (int i = 0; i < tam1; ++i)
	{
		A[i] = rand() % 9 + 1;
		printf("%d", A[i]);
	}
	printf("\nEl arreglo 2 es: ");
	for (int i = 0; i < tam2; ++i)
	{
		B[i] = rand() % 9 + 1;
		printf("%d", B[i]);
	}
	printf("\n");
}