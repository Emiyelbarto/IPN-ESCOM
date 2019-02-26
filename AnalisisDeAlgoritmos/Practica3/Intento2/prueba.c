#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *CrearMain(int *Main, int TamPrincipal);

int main(int argc, char const *argv[])
{
	int **Lista;
	int *auxright, *auxleft, *Main;
	int TamPrincipal, div;
	printf("Escribir el tamaño que tendrá el arreglo:\n");
	scanf("%d",&TamPrincipal);
	Lista = calloc(0,sizeof(int *) * TamPrincipal);
	Main = CrearMain(Main,TamPrincipal);
	Lista[0] = Main;
	div = (TamPrincipal/2);
	auxleft = calloc(0,sizeof(int) * div);
	auxright = calloc(0,sizeof(int) * div);
	if(TamPrincipal % 2 == 1)
	{

	}
	else if(TamPrincipal % 2 == 0)
	{
		for (int i = 0; i < div; ++i)
		{
			auxleft[i] = Main[i];
		}
		printf("\nPrimera división izquierda:");
		for (int i = 0; i < div; ++i)
		{
			printf("%d\t", auxleft[i]);
		}
		printf("\n");
		for (int i = div; i < TamPrincipal; ++i)
		{
			auxright[i-div] = Main[i];
		}
		printf("\nPrimera Divison Derecha:");
		for (int i = div; i < TamPrincipal; ++i)
		{
			printf("%d\t", auxright[i-div]);
		}
		printf("\n");
		Lista[1] = auxleft;
		Lista[2] = auxright;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < TamPrincipal; ++j)
			{
				if (Lista[i][j] == 0)
				{
					break;
				}
				printf("Lista[%d][%d] = %d\n", i, j, Lista[i][j]);
			}
			printf("\n");
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (Lista[i]==0)
		{
			break;
		}
		else
		{
			free(Lista[i]);
		}
		free(Lista);
	}
	return 0;
}

int *CrearMain(int *Main, int TamPrincipal)
{
	srand(time(NULL));
	Main = calloc(0,sizeof(int) * TamPrincipal);
	for (int i = 0; i < TamPrincipal; ++i)
	{
		Main[i] = rand() % 1000;
	}
	printf("Arreglo principal:");
	for (int i = 0; i < TamPrincipal; ++i)
	{
		printf("%d\t", Main[i]);
	}
	printf("\n");
	return Main;
}