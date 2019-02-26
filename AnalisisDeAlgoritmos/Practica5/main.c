//Autores: Uribe Hinojosa Gerardo Ángel y José Emiliano Pérez Garduño
#include <stdio.h>
#include <stdlib.h>

int EscogerEntrada();
int MedirCadena(char aux[1000]);

int main()
{
	int opc = EscogerEntrada();
	FILE *file;
	file = fopen("cadena.txt","r");
	char *cadena, *subcadena, aux[1000];
	int Tam1, Tam2, contador;
	if(!file)
	{
		printf("Error al leer archivo\n");
		EscogerEntrada();
	}
	if(opc == 1)
	{
		printf("Escribir cadena:");
		fflush(stdin);
		scanf("%[^\t]",aux);
		Tam1 = MedirCadena(aux);
		cadena = malloc(sizeof(char) * Tam1);
		for (int i = 0; i < Tam1; ++i)
		{
			cadena[i] = aux[i];
		}
		printf("Cadena escaneada de teclado: %s\n", cadena);
	}
	if(opc == 2)
	{
		while(!feof(file))
		{
			fscanf(file,"%[^\n]",aux);
		}
		Tam1 = MedirCadena(aux);
		cadena = malloc(sizeof(char) * Tam1);
		for (int i = 0; i < Tam1; ++i)
		{
			cadena[i] = aux[i];
		}
		printf("Cadena escaneada de archivo: %s\n", cadena);
	}
	printf("Escribir subcadena:\n");
	scanf("%s",aux);
	Tam2 = MedirCadena(aux);
	subcadena = malloc(sizeof(char) * Tam2);
	for (int i = 0; i < Tam2; ++i)
	{
		subcadena[i] = aux[i];
	}
	if (Tam2 > Tam1)
	{
		contador = 0;
		printf("La subcadena introducida es de mayor tamanio que la cadena principal, por lo que no es subcadena\n");
		return 0;
	}
	if(Tam2 == Tam1)
	{
		for (int i = 0; i < Tam1; ++i)
		{
			if (cadena[i] != subcadena[i])
			{
				printf("La cadena introducida no es subcadena de la cadena principal\n");
				return 0;
			}
		}
		printf("La subcadena introducida es subcadena de la cadena principal.\n");
		contador = 1;
		printf("Numero de iteraciones: %d\n", contador);
	}
	printf("subcadena: %s\n", subcadena);
	int j = 0, i = 0;
	if(Tam2 < Tam1)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == subcadena[j])
			{
				j++;
				if (subcadena[j] == '\0')
				{
					contador++;
					j=0;
				}
			}
			i++;
		}
		printf("Numero de iteraciones: %d\n", contador);
	}
}

int MedirCadena(char aux[1000])
{
	int Tam1 = 0;
	while(aux[Tam1] != '\0')
	{
		Tam1++;
	}
	return Tam1;
}

int EscogerEntrada()
{
	int opc;
	do
	{
		printf("Leer cadena desde:\n1.-Teclado\n2.-Archivo\n");
		scanf("%d",&opc);
		if(opc == 1 || opc == 2)
			break;
	}while(opc != 1 || opc != 2);
	return opc;
}