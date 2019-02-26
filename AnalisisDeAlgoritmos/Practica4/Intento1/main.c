#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

void main(int argc, char const *argv[])
{
	srand(time(NULL));
	char *aux1, *aux2;
	char *A, *B, *C;
	int tam1, tam2, flag1, flag2, aux;
	flag1 = flag2 = 1;
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
	if(A[0] > 5)
	{
		C = calloc('\0',sizeof(char) * (tam1 + tam2));
	}
	else
	{
		C = calloc('\0',sizeof(char) * (tam1 + tam2 - 1));
	}
	aux1 = calloc('\0',tam1 * tam2 * 10);
	aux2= calloc('\0',tam1 * tam2 * 10);
	int x, y;
	x = y = 0;
	printf("\n");
	for (int i = tam2; i > 0; i--)
	{
		for(int j = tam1; j > 0; j--)
		{
			aux1[x] = (A[j] * flag1) * (B[i] * flag2);
			printf("aux1[%d] = %d * %d = %d\n", x, A[j] * flag1, B[j] * flag2, A[j] * flag1 * B[j] * flag2);
			flag1 = flag1 + 10;
			x++;
		}/*
		aux2[y] = (A[i] * flag2) * (B[i] * flag2);
		printf("aux2[%d] = %d * %d = %d\n", y, A[i] * flag1, B[i] * flag2, A[i] * flag1 * B[i] * flag2);*/
		flag2 = flag2 + 10;
		y++;
	}
	int i, j, TamLista, iteracion;
	i = j = TamLista = iteracion = 0;
	while(aux2[TamLista] != '\0')
	{
		while(aux1[TamLista] != '\0')
		{
			TamLista++;
		}
		TamLista++;
	}
	char *Lista;
	printf("\ntamaño lista: %d\n", TamLista);
	Lista = calloc('\0', TamLista * 4);
	while(aux2[i] != '\0')
	{
		while(aux1[j] != '\0')
		{
			Lista[iteracion] = aux1[i] + aux2[j];
			iteracion ++;
			j++;
		}
		iteracion++;
		i++;	
	}
	printf("\nHubo %d sumas\n", iteracion);
	int k = 0;
	while(Lista[k] != '\0')
	{
		printf("%d\n", Lista[k]);
		k++;
	}
	printf("\n");
}