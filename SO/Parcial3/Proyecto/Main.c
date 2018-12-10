#include<stdio.h>
#include<stdlib.h>
#include"Swap.h"

void MenuPrincipal();
void CapturarProces();
void CapturarId();
void CapturarSwap();
void CapturarR();
int ValidarSwap(int idP);
int ValidarRecuperacion(int idP);

void main()
{
	InitSeg();
	MenuPrincipal();
}

void MenuPrincipal()
{
	int opc;
	printf("\nBienvenido\n\nIngrese:\n");
	printf("1 Para crear proceso\n") ;
	printf("2 Para eliminar un proceso\n");
	printf("3 Para hacer swapping\n");
	printf("4 Para recuperar procesos\n");
	printf("5 Para mostrar RAM\n");
	printf("6 Para mostrar SWAP\n");
	printf("7 Para mostrar Segmentos\n");
	printf("8 Para salir\n");
	scanf("%d",&opc);
	switch(opc)
	{
		case 1:
			system("clear");
			CapturarProces();
			MenuPrincipal();
		case 2:
			system("clear");
			CapturarId();
			MenuPrincipal();
		case 5:
			system("clear");
			MostrarRam();
			MenuPrincipal();
		case 3:
			system("clear");
			CapturarSwap();
			MenuPrincipal();
		case 6:
			system("clear");
			MostrarSwap();
			MenuPrincipal();
		case 4:
			system("clear");
			CapturarR();
			MenuPrincipal();
		case 7:
			system("clear");
			MostrarSegmentos();
			MenuPrincipal();
		case 8:
			exit(0);
		default:
			system("clear");
			printf("\nOpcion invalida");
			sleep(1);
			MenuPrincipal();
	}
}

void CapturarR()
{
	int ids;
	printf("\nIngrese el proceso a recuperar: ");
	scanf("%d",&ids);
	if(ValidarRecuperacion(ids))
		Recuperar(ids);
	else
	{
		printf("\n No hay espacio en RAM");
		sleep(1);
	}
}

void CapturarSwap()
{
	int IDp;
	printf("\nIngrese el id del proceso que se movera a swap: ");
	scanf("%d",&IDp);
	if(ValidarSwap(IDp))
		Swapping(IDp);
	else
	{
		printf("\n No hay espacio en swap");
		sleep(1);
	}
}

void CapturarId()
{
	int idP;
	system("clear");
	printf("\nIngrese el id del proceso a eliminar: ");
	scanf("%d",&idP);
	EliminarProceso(idP);
}

void CapturarProces()
{
	int tam;
	system("clear");
	printf("\nIngrese el tamanio del proceso: ");
	scanf("%d",&tam);
	CrearProceso(tam);
}

