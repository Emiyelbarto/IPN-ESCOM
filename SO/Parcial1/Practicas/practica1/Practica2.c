#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include"Procreador.h"
//#include"Prueba.h"

//#include"Hermanos.h"

void main()
{
	int level;
	printf("\nIngrese Hasta que nivel llegara el arbol: ");
	scanf("%d",&level);
	printf("\nSu arbol queda asi:\n\n");
	Nivel0(level,0);



}




