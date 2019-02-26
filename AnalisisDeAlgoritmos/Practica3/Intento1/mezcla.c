//Autor: José emiliano Pérez Garduño/3CV3/Análisis de Algorítmos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <math.h>

int main(int argc, char const *argv[])
{
	int length, div, nivel;
	int **Lista, *A, *auxleft, *auxright;
	printf("¿De qué tamaño será el arreglo?\n");
	scanf("%d",&length);
	A = malloc(sizeof(int) * length + 1);
	LlenarArreglo(A,length);
	auxleft = malloc(sizeof(int) * length + 1);
	auxright = malloc(sizeof(int) * length + 1);
	printf("El arreglo original es: ");
	ImprimirArreglo(A,length);
	CrearLista(Lista,length);
	Lista[0] = A;
	nivel = CrearNiveles(length);
	printf("Numero de niveles: %d\n", nivel+1);
	div = length;
	for(int i = 0; i < nivel; i++)
	{
		div = div / 2;
		if(i == 0)
		{
			if((length % 2) == 1)
			{
				//Arreglo Impar
				ArregloImpar(Lista,A,auxright,auxleft,length,div,i+1);
			}
			else
			{
				//Arreglo Par
				ArregloPar(Lista,A,auxright,auxleft,length,div,i+1);
			}
		}/*
		else
		{
			printf("Dividimos de nuevo:\n");
			if((div % 2) == 1)
			{
				//Arreglo Impar
				Dividir(Lista, auxright, auxleft, length, div, nivel);
			}
			else
			{
				//Arreglo Par
				//Ordenar(*apuntador);
			}
		}*/
	}
	ImprimirLista(Lista);
	LiberarMemoria(Lista);
	return 0;
}