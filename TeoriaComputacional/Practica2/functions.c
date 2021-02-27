#include <stdio.h>
#include <stdlib.h>
void Operaciones(char *Lenguaje);
int Opcion()
{
	int opc;
	printf("Escoger desde:\n1.-Teclado\n2.-Archivo\n");
	scanf("%d",&opc);
	while(opc < 1 || opc > 2)
	{
		printf("Escoger una opcion valida\n");
		printf("Escoger desde:\n1.-Teclado\n2.-Archivo\n");
		scanf("%d",&opc);
	}
	return opc;
}

char *LenguajeTeclado()
{
	char *aux;
	aux = (char *) malloc(sizeof(char) * 100);
	printf("Escribir lenguaje:\n");
	getchar();
	scanf("%[^\n]",aux);
	return aux;
}

void VerifyFile(FILE *file)
{
	if (!file)
	{
		printf("-----Error al abrir el archivo.-----\n");
		exit(1);
	}
	else
	{
		printf("Archivo abierto correctamente.\n");
	}
}

int Longitud(char *array)
{
	int x = 0;
	while(array[x] != '\0')
	{
		x++;
	}
	return x;
}

char *LenguajeFile(FILE *file)
{
	char **Opciones;
	int x = 0, y = 0, opc, tam;
	Opciones = (char **) malloc(sizeof(char *) * 1024);
	size_t line_size = 1024;
	char *line = (char *) malloc(line_size);
	printf("Escoger el lenguaje a utilizar\n");
	while(fgets(line,line_size,file) != NULL)
	{
		tam = Longitud(line);
		line[tam - 1] = '\0';
		Opciones[x] = (char*) malloc(sizeof(char) * tam);
		while(line[y] != '\0')
		{
			Opciones[x][y] = line[y];
			y++;
		}
		printf("%d.-%s\n", x, Opciones[x]);
		x++;
		y=0;
	}
	free(line);
	scanf("%d",&opc);
	return Opciones[opc];
}

int Menu()
{
	int opc;
	do
	{
		printf("Escoger operacion a realizar:\n");
		printf("1. Reflexion\n");
		printf("2. Cerradura positiva\n");
		printf("3. Cerradura de Kleen\n");
		printf("4. Potencia\n");
		printf("5. Nuevo Lenguaje\n");
		printf("6. Salir\n");
		scanf("%d",&opc);
	}while(opc < 1 || opc > 6);
	return opc;
}

void Reflexion(char *Lenguaje)
{
	printf("\n\tReflexion\n");
	int i = 0, Tam = 0;
	while(Lenguaje[i] != '\0')
	{
		Tam++;
		i++;
	}
	char *Reflejo;
	Reflejo = (char *) malloc(sizeof(char) * Tam);	
	for(i=0; i<Tam; i++)
		Reflejo[i]=Lenguaje[(Tam-1)-i];
	printf("\nLenguaje a usar: %s\n", Lenguaje);
	printf("\nLenguaje reflejado: %s\n", Reflejo);
}

void CerraduraPos(char *Lenguaje)
{
	printf("\n\tCerradura positiva\n");	
	int n, Tam = Longitud(Lenguaje);
	char *Cerradura = (char*) malloc(sizeof(char) * Tam);	
	for(int i=0; i<=Tam; i++)
		Cerradura[i]=Lenguaje[i];	
	printf("\nIngrese grado para n: ");
	scanf("%d", &n);
	while(n<=0)
	{
		printf("Ingrese grado mayor a 0\n");
		scanf("%d", &n);
	}
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			printf("%s", Cerradura);
		}
		printf(",");				
		}
	printf("\n");
}


void CerraduraKleen(char *Lenguaje)
{
	printf("\n\tCerradura de Kleen\n");
	int n, Tam = Longitud(Lenguaje);
	char *cKleen;
	cKleen = (char *) (malloc(sizeof(char) * Tam));
	for(int i=0; i<Tam; i++)
		cKleen[i]=Lenguaje[i];
	printf("\nIngrese grado para n: ");
	scanf("%d", &n);
	while(n<=0)
	{
		printf("Ingrese grado mayor a 0\n");
		scanf("%d", &n);
	}
	for (int i=0; i <= n; i++)
	{		
		if(i == 0)
		{
		printf("@");		
		printf(", ");
		}
		else
		{
			for(int j = 1; j <= i; j++)
			{
				printf("%s", cKleen);
			}
			printf(",");
		}
	}
	printf("\n");
}

void Potencia(char *Lenguaje)
{
	printf("\n\tPotencia\n");
	int x = 0, y = 0, n, Tam = Longitud(Lenguaje);
	char *Pot = (char *) malloc(sizeof(char) * Tam);	
	for(int i = 0; i <= Tam; i++)
		Pot[i]=Lenguaje[i];	
	printf("\nIngrese grado para n: ");
	scanf("%d", &n);
	while(n<0)
	{
		printf("Ingrese grado positivo\n");
		scanf("%d", &n);
	}
	if (n==0)
		printf("1\n");
	else
	{	
		for (int i = 0; i < n; i++)
		{		
			for(int j=0; j < i; j++)
			{
				printf("%d.-", j);
				while(Pot[x] != '\0')
				{
					while(Pot[y] != '\0')
					{
						printf("%c%c\n", Pot[x], Pot[y]);
						y++;
					}
					y = 0;
					printf("\n");
					x++;
				}
				printf("\n");
			}
		}
		printf("\n");
	}
}

void EscogerLenguaje()
{
	char *Aux;
	Aux = (char*) malloc(sizeof(char) * 1024);
	int opc;
	opc = Opcion();
	switch(opc)
	{
		case 1:
			Aux = LenguajeTeclado();
			Operaciones(Aux);
			break;

		case 2:
			char NomFile[1024];
			printf("Escribir nombre del archivo:\n");
			scanf("%s",NomFile);
			FILE *file = fopen(NomFile,"r");
			VerifyFile(file);
			Aux = LenguajeFile(file);
			Operaciones(Aux);
			break;
	}
}

void Operaciones(char *Lenguaje, int NumLenguajes)
{
	char **Opciones = malloc(sizeof(char) * 1024);
	int opc = Menu();
	do
	{
		switch(opc)
		{
			case 1:
				Reflexion(Lenguaje);
				break;
			case 2:
				CerraduraPos(Lenguaje);
				break;
			case 3:
				CerraduraKleen(Lenguaje);
				break;
			case 4:
				Potencia(Lenguaje);
				break;
			case 5:
				printf("\n\tNuevo Lenguaje\n");
				EscogerLenguaje();
				break;
			case 6:
				printf("\n\tSalir\n");
				exit(1);
		}
		opc = Menu();
	}while(opc!=6);
}