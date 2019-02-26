//Autor: José Emiliano Pérez Garduño 3CV3 Análisis de Algorítmos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Multiplicacion(char *A, char *B, int TamA, int TamB);
int Longitud(char *puntero);
char *Poblar(char *puntero, int TamPuntero);
void ImprimirArreglo(char *puntero);

int main()
{
	srand(time(NULL));
	int Tam1, Tam2;
	char *Num1, *Num2;
	printf("Introducir el tamaño del numero 1:\n");
	scanf("%d", &Tam1);
	while(Tam1 <= 0)
	{
		printf("El tamaño debe ser mayor a cero\nIntroducir de nuevo:\n");
		scanf("%d", &Tam1);
	}
	Num1 = malloc(sizeof(int) * Tam1);
	printf("Introducir el tamaño del numero 2:\n");
	scanf("%d", &Tam2);
	while(Tam2 <= 0)
	{
		printf("El tamaño debe ser mayor a cero\nIntroducir de nuevo:\n");
		scanf("%d", &Tam2);
	}
	Num2 = malloc(sizeof(int) * Tam2);
	Num1 = Poblar(Num1, Tam1);
	Num2 = Poblar(Num2, Tam2);
	printf("Numero 1: ");
	ImprimirArreglo(Num1);
	printf("\nNumero 2: ");
	ImprimirArreglo(Num2);
	printf("\n");
	Multiplicacion(Num1, Num2, Tam1, Tam2);
}

int Longitud(char *puntero)
{
	int i = 0;
	while(puntero[i] != '\0')
	{
		i++;
	}
	return i;
}

int Multiplicacion(char *A, char *B, int TamA, int TamB)
{
	char *C, *aux;
	int x = 0;
	int carry, mult, flag;
	int prueba[2];
	C = malloc(sizeof(int) * (TamA + TamB));
	aux = malloc(sizeof(int) * ((TamA + 1) * (TamB + 1)));
	flag = 10;
	while(TamA > 0 && TamB > 0)
	{
		for (int j = TamB-1; j >= 0; j--)
		{
			for (int i = TamA-1; i >= 0; i--)
			{
				prueba[1] = A[i] * B[j];
				if(A[i] * B[j] > 9)
				{
					prueba[0] = (prueba[1] / 10) * flag;
					printf("prueba[0] = (%d / 10) * %d\n", prueba[1], flag);
				}
				else
					prueba[0] = 0;
				printf("(B[%d] = %d) * (A[%d] = %d) = %d\n", j, B[j], i, A[i], prueba[1]);
				if(prueba[0] == 0)
				{
					prueba[0] = 10;
					if(prueba[1] > 99)
						aux[x] = (prueba[1] - prueba[0] / (flag / 10)) * (flag / 10);
					else
						aux[x] = prueba[1] - prueba[0] / (flag / 10);
				}
				else
				{				
					if(prueba[1] > 99)
						aux[x] = (prueba[1] - prueba[0] / (flag / 10)) * (flag / 10);
					else
						aux[x] = prueba[1] - prueba[0] / (flag / 10);
				}
				printf("Carry: %d\n", prueba[0]);
				printf("Multiplicación: %d\n", aux[x]);
				aux[x + 1] = '\0';
				C[x] = aux[x];
				x++;
				flag = flag * 10;
			}
		}
		TamA--;
		TamB--;
	}
	while(x > 0)
	{
		x--;
		printf("C[%d] + C[%d] = %d\n", x, x+1, C[x] + C[x + 1]);
	}
}

char *Poblar(char *puntero, int TamPuntero)
{
	for (int i = 0; i < TamPuntero; ++i)
	{
		puntero[i] = rand() % 8 + 1;
		puntero[i + 1] = '\0';
	}
	return puntero;
}

void ImprimirArreglo(char *puntero)
{
	int i = 0;
	while(puntero[i] != '\0')
	{
		printf("%d", puntero[i]);
		i++;
	}
}