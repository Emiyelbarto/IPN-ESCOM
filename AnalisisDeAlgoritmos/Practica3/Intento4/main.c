//Autor: José Emiliano Pérez Garduño 3CV3 Análisis de Algorítmos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LongArreglo(int *arreglo);
int *Dividir(int *arreglo);
void Imprimir(int *arreglo);

int main()
{
	srand(time(NULL));
	int Tam, opc;
	int *Principal;
	int *aux;
	printf("Introducir el numero del arreglo:\n");
	scanf("%d",&Tam);
	while(Tam <= 0)
	{
		printf("El arreglo debe ser mayor a cero!\nIntroducir de nuevo el tamaño:\n");
		scanf("%d",&Tam);
	}
	Principal = malloc(sizeof(int) * Tam);
	aux = malloc(sizeof(int) * Tam);
	for (int i = 0; i < Tam; ++i)
	{
		Principal[i] = rand() % 1000 + 1;
		printf("%d\t", Principal[i]);
	}
	Principal[Tam] = 0;
	int j = 0;
	printf("\n");
	if(Tam == 1)
	{
		printf("El arreglo ordenado es: %d\n", Principal[0]);
		return 0;
	}
	aux = Dividir(Principal);
	printf("Imprimir arreglo ordenado?\n1.-Si\n2.-No\n");
	scanf("%d",&opc);
	if(opc == 1)
	{
		Imprimir(aux);
	}
	return 0;
}

int LongArreglo(int *arreglo)
{
	int i = 0;
	while(arreglo[i] != 0)
	{
		i++;
	}
	return i;
}

int *Dividir(int *arreglo)
{
	float mitad;
	int *MitadIzquierda;
	int *MitadDerecha;
	int i, j, k, x;
	int opc;
	//printf("Arreglo a Dividir: [");
	//Imprimimos el arreglo introducido.
	for (int i = 0; i < LongArreglo(arreglo); ++i)
	{
		if(arreglo[i + 1] == '\0')
		{
			//printf("%d]\n", arreglo[i]);
		}
		else
		{
			//printf("%d ", arreglo[i]);			
		}
	}
	if(LongArreglo(arreglo) > 1)
	{
		mitad = LongArreglo(arreglo) / 2;
		MitadIzquierda = malloc(sizeof(int) * (mitad + 1));
		MitadDerecha = malloc(sizeof(int) * (mitad + 1));
		//printf("Mitad Izquierda: [");
		for (int i = 0; i < mitad; ++i)
		{
			MitadIzquierda[i] = arreglo[i];
			MitadIzquierda[i + 1] = 0;
			if(i + 1 == mitad)
			{
				//printf("%d]\n", MitadIzquierda[i]);
			}
			else
			{
				//printf("%d ", MitadIzquierda[i]);
			}
		}

		//printf("Mitad Derecha: [");
		j = 0;

		for (int i = mitad; i <= LongArreglo(arreglo); ++i)
		{
			MitadDerecha[j] = arreglo[i];
			MitadDerecha[j + 1] = 0;
			if(i + 1 == LongArreglo(arreglo))
			{
				//printf("%d]\n", MitadDerecha[j]);
			}
			else
			{
				//printf("%d ", MitadDerecha[j]);
			}
			j++;
		}
		
		Dividir(MitadIzquierda);
		Dividir(MitadDerecha);
		
		i = 0;
		j = 0;
		k = 0;

		while(i < LongArreglo(MitadIzquierda) && j < LongArreglo(MitadDerecha))
		{
			if(MitadIzquierda[i] < MitadDerecha[j])
			{
				arreglo[k] = MitadIzquierda[i];
				i++;
			}
			else
			{
				arreglo[k] = MitadDerecha[j];
				j++;
			}
			k++;
		}

		while(i < LongArreglo(MitadIzquierda))
		{
			arreglo[k] = MitadIzquierda[i];
			i++;
			k++;
		}

		while(j <= LongArreglo(MitadDerecha))
		{
			arreglo[k] = MitadDerecha[j];
			j++;
			k++;
		}
	}
	return arreglo;
}

void Imprimir(int *arreglo)
{
	int x;
	printf("Arreglo Ordenado: [");
		for(x = 0; x < LongArreglo(arreglo); x++)
		{
			if(arreglo[x + 1] == 0)
			{
				printf("%d]", arreglo[x]);
			}
			else
			{
				printf("%d ", arreglo[x]);
			}
		}
		printf("\n");
}