//Autor: José emiliano Pérez Garduño/3CV3/Análisis de Algorítmos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int *LlenarArreglo(int *A, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; ++i)
	{
		A[i] = rand() % 1000;
	}
	A[length] = '\0';
}

void ImprimirArreglo(int *A, int length)
{
	for (int i = 0; i <= length-1; ++i)
	{
		if(i == length-1)
		{
			printf("%d\n", A[i]);
		}
		else
		{
			printf("%d, ", A[i]);
		}
	}
	printf("\n");
}

int CrearNiveles(int length)
{
	float div = length;
	int NumNiveles = 0;
	while(div > 2)
	{
		div = div / 2;
		NumNiveles++;
	}
	return NumNiveles;
}

int CrearTamLista(int length)
{	
	int NumNiveles, TamLista;
	float aux = 0;
	NumNiveles = CrearNiveles(length);
	for(int i = 0; i <= NumNiveles; i++)
	{
		aux += pow(2,i);
	}
	TamLista = (int)aux;
	return TamLista;
}

int **CrearLista(int **Lista,int length)
{
	//printf("La lista de arreglos es de tamaño: %d\n", CrearTamLista(length));
	Lista = calloc(0,CrearTamLista(length));
	return Lista;
}

int **ArregloImpar(int **Lista, int *A, int *auxright, int *auxleft, int length, int div, int nivel)
{
	for(int j = 0; j < div; j++)
	{
		auxleft[j] = A[j];
	}
	Lista[nivel] = auxleft;
	for(int j = div; j <= length; j++)
	{
		auxright[j-div] = A[j];
	}
	Lista[nivel+1] = auxright;
	printf("Lado izquierdo: ");
	for (int i = 0; i < div; ++i)
	{
		printf("%d\t", Lista[nivel][i]);
	}
	printf("\nLado Derecho: ");	
	for (int i = 0; i <= div; ++i)
	{
		printf("%d\t", Lista[nivel+1][i]);
	}
	Lista[nivel+2] = NULL;
	printf("\n");
	free(auxleft);
	free(auxright);
	return Lista;
}

int **ArregloPar(int **Lista, int *A, int *auxright, int *auxleft, int length, int div, int nivel)
{
	for(int j = 0; j < div; j++)
	{
		auxleft[j] = A[j];
		//printf("%d\n", auxleft[j]);
		auxleft[j + 1] = '\0';
	}
	Lista[1] = auxleft;
	for(int j = div; j <= length; j++)
	{
		auxright[j-div] = A[j];
		auxright[j -div + 1] = '\0';
	}
	Lista[2] = auxright;
	printf("Lado izquierdo: ");/*
	for (int i = 0; i < div; ++i)
	{
		printf("%d\t",Lista[nivel][i]);
	}*/
	int i = 0;
	while(Lista[nivel][i] != '\0')
	{
		printf("%d\t", Lista[nivel][i]);
		i++;
	}
	printf("\nLado Derecho: ");
	for (int i = 0; i < div; ++i)
	{
		printf("%d\t", Lista[nivel+1][i]);
	}
	Lista[nivel+2] = NULL;
	printf("\n");
	free(auxleft);
	free(auxright);
	return Lista;
}

int ContarApuntadores(int **Lista)
{
	int i = 0;
	while(Lista[i] != NULL)
	{
		i++;
	}
	return i;
}

int *Ordenar(int *apuntador)
{
	int length = 0;
	while(apuntador != NULL || !apuntador)
	{
		length++;
	}
	if(length == 1)
	{
		return apuntador;
	}
	else if(length == 2)
	{
		if(apuntador[0] < apuntador[1])
		{
			return apuntador;
		}
		else
		{
			int aux;
			aux = apuntador[0];
			apuntador[0] = apuntador[1];
			apuntador[1] = aux;
			return apuntador;
		}
	}
}

int *Dividir(int **Lista, int *auxright, int *auxleft, int length, int div, int nivel)
{
	for (int i = 0; i < div; ++i)
	{
		auxleft = &Lista[0][i];
	}
	printf("Dividido izquierdo es: ");
	for (int i = 0; i < div; ++i)
	{
		printf("%d\n", auxleft[i]);
	}
	for (int i = div-1; i < div*2; ++i)
	{
		auxright = &Lista[0][i];
	}
	printf("Dividido Derecho es: ");
	for (int i = div-1; i < div*2; ++i)
	{
		printf("%d\t", auxright[i]);
	}
	printf("\n");
	int ApuntadoresOcupados = ContarApuntadores(Lista);
	printf("Hay %d apuntadores ocupados\n", ApuntadoresOcupados);
	Lista[ApuntadoresOcupados]=auxleft;
	Lista[ApuntadoresOcupados+1]=auxright;
	Lista[ApuntadoresOcupados+2]=NULL;
	ApuntadoresOcupados = ContarApuntadores(Lista);
	printf("Ahora hay %d apuntadores ocupados\n", ApuntadoresOcupados);
	/*for (int i = 0; i < 6; ++i)
	{
		printf("Arreglo %d: %d\n", i,*Lista[i]);
	}*/
	//auxleft = Ordenar(auxleft);
	//auxright = Ordenar(auxright);

}

void LiberarMemoria(int **Lista)
{
	int TamLista = ContarApuntadores(Lista);
	//printf("Liberando Memoria con lista = %d\n", TamLista);
	for (int i = 0; i < TamLista; ++i)
	{
		if(/*Lista[i] == NULL || */Lista[i] == 0)
		{
			break;
		}
		else
		{
			printf("Liberando Arreglo de apuntadores, empezando por el Arreglo Lista[%d]\n",i);
			free(Lista[i]);
		}
	}
	printf("Termino liberación de apuntadores\n");
}

void ImprimirLista(int **Lista)
{
	int Apuntadores = ContarApuntadores(Lista);
	printf("Hay %d apuntadores en la lista\n", Apuntadores);
	int TamArreglo = 0;
	int j = 0;
	for (int i = 0; i < Apuntadores; ++i)
	{
		while(Lista[i][j] != '\0')
		{
			printf("entro al while para ver cuanto mide el arreglo\n");
			TamArreglo++;
			j++;
		}
		ImprimirArreglo(Lista[i],TamArreglo);
		printf("\n");
	}
}