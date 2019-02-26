//Autor: José emiliano Pérez Garduño/3CV3/Análisis de Algorítmos
#include <stdio.h>
int *LlenarArreglo(int *A, int length);
void ImprimirArreglo(int *A, int length);
int **CrearLista(int **Lista,int length);
void LiberarMemoria(int **Lista);
int CrearNiveles(int length);
int ContarApuntadores(int **Lista);
int **ArregloImpar(int **Lista, int *A, int *auxright, int *auxleft, int length, int div, int nivel);
int **ArregloPar(int **Lista, int *A, int *auxright, int *auxleft, int length, int div, int nivel);
int *Dividir(int **Lista, int *auxright, int *auxleft, int length, int div, int nivel);
int *Ordenar(int *apuntador);
void ImprimirLista(int **Lista);