//Autor: José Emiliano Pérez Garduño/Teoría Computacional/2CV3
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int LongArreglo(char * palabra)
{
	int i=0;
	while(palabra[i] != '\0')
	{
		i++;
	}
	return i;
}

int TamArreglo(char *palabra)
{
	int i=0, length=0;
	while(palabra[i] != '\0')
	{
		length++;
		i++;
	}
	return length;
}

int TamLista(char **Lista)
{
	int i = 1;
	while(Lista[i] != NULL)
	{
		i++;
	}
	return i;
}

void GuardarPalabra(char **Lista, char *palabra)
{
	int lugar;
	lugar = TamLista(Lista);
	printf("El lugar donde se guardara la palabra de la lista es Lista[%d] = %s\n", lugar, palabra);
	Lista[lugar] = palabra;
	Lista[lugar+1] = NULL;
}

void ImpPalabra(char *palabra, int length)
{
	printf("La palabra escaneada es: ");
	printf("%s", palabra);
	printf("\n");
}

void ImpLongitud(char *palabra)
{
	int length = 0;
	while(palabra[length] != '\0')
	{
		length++;
	}
	printf("La longitud es: %d\n", length);
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void MostrarLista(char **Lista)
{
	int k = TamLista(Lista);
	printf("Hay %d palabras en la lista.\n", k-1);
	for (int i = 1; i < k; ++i)
	{
		printf("%d.-%s\n", i,Lista[i]);
	}
}

char *IgualarAux(char * aux, char * palabra, int length)
{
	for (int i = 0; i < length; ++i)
	{
		palabra[i] = aux[i];
	}
	return palabra;
}

void Concatenacion(char *Palabra1, char *Palabra2, char **Lista)
{
	int long1 = 0, long2 = 0;
	char *res;
	long1 = TamArreglo(Palabra1);
	long2 = TamArreglo(Palabra2);
	res = calloc('\0',sizeof(char) * long1+long2+1);
	for (int i = 0; i <= long1; ++i)
	{
		res[i] = Palabra1[i];
	}
	for (int i = 0; i < long2; ++i)
	{
		res[i+long1] = Palabra2[i];
	}
	printf("\n");
	printf("La concatenación es:");
	printf("%s\n", res);
	printf("\n");
	GuardarPalabra(Lista,res);
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void Invertir(char * palabra, char **Lista)
{
	printf("Inversión\n");
	char * aux;
	int i=0;
	int Tam = LongArreglo(palabra)-1;
	aux = malloc(sizeof(char) * Tam);
	while(palabra[i] != '\0')
	{
		aux[i] = palabra[Tam];
		i++;
		Tam--;
	}
	i = 0;
	printf("La palabra invertida es: ");
	printf("%s\n", aux);	
	GuardarPalabra(Lista,aux);
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void Sufijos(char *palabra)
{
	int LongSufijo, TamPalabra,k;
	char *aux;
	TamPalabra = TamArreglo(palabra);
	printf("Indicar cuantos caracteres se tomarán en cuenta para el sufijo de la palabra '%s':\n",palabra);
	scanf("%d",&LongSufijo);
	for (int i = 0; i < LongSufijo; ++i)
	{
		k=0;
		aux = calloc('\0',sizeof(char) * TamPalabra);
		for (int j = LongSufijo-1-i; j <= TamPalabra; j++)
		{
			aux[k] = palabra[j];
			k++;
		}
		int j = 0;
		printf("Sufijo %d: ", i+1);
		while(aux[j] != '\0')
		{
			printf("%c", aux[j]);
			j++;
		}
		printf("\n");
	}
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void Prefijos(char *palabra)
{
	int LongPrefijo, TamPalabra;
	char *aux;
	TamPalabra = TamArreglo(palabra);
	printf("Indicar cuantos caracteres se tomarán en cuenta para el prefijo:\n");
	scanf("%d",&LongPrefijo);
	for (int i = 0; i < LongPrefijo; ++i)
	{
		aux = calloc('\0',sizeof(char) * LongPrefijo+1);
		printf("Sufijo %d: ", i+1);
		for (int j = 0; j < LongPrefijo-(i); j++)
		{
			aux[j] = palabra[j];
		}
		int j = 0;
		while(aux[j] != '\0')
		{
			printf("%c", aux[j]);
			j++;
		}
		printf("\n");
	}
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void SubCadenas(char *palabra)
{
	int Tam, flag=0, k;
	Tam = TamArreglo(palabra);
	char *aux;
	for (int i = 0; i < Tam; ++i)
	{
		aux = calloc('\0',sizeof(char) * Tam+1);
		printf("%d.- ", i+1);
		for (int j = 0; j < Tam-(i); j++)
		{
			aux[j] = palabra[j];
		}
		int j = 0;
		while(aux[j] != '\0')
		{
			printf("%c", aux[j]);
			j++;
		}
		printf("\n");
		flag++;
	}
	for (int i = 1; i < Tam-1; ++i)
	{
		flag++;
		printf("%d.- %c\n", flag,palabra[i]);
	}
	for (int i = 0; i < Tam; ++i)
	{
		flag++;
		k=0;
		aux = calloc('\0',sizeof(char) * Tam);
		for (int j = Tam-1-i; j <= Tam; j++)
		{
			aux[k] = palabra[j];
			k++;
		}
		int j = 0;
		printf("%d.- ", flag);
		while(aux[j] != '\0')
		{
			printf("%c", aux[j]);
			j++;
		}
		printf("\n");
	}


	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

void SubSecuencias(char *palabraA, char *palabraB)
{
	int TamA,TamB;
	TamA = TamArreglo(palabraA);
	TamB = TamArreglo(palabraB);
	printf("Subsecuencias de '%s' con '%s'\n", palabraA, palabraB);
	for(int i = 0; i < TamA; i++)
	{
		for(int j = 0; j < TamB; j++)
		{
			printf("Subsecuencia: %c%c\n", palabraA[i], palabraB[j]);
		}
		printf("Subsecuencia: %c\n", palabraA[i]);
	}
	printf("\nPresionar cualquier tecla para continuar.\n");
	getchar();
}

int GetNumWordsFile()
{	
	FILE *auxarchivo;
	auxarchivo = fopen("palabras.txt","r");
	char str[100];
	int k = 0;
	while(fgets(str,100,auxarchivo) != NULL)
	{
		k++;
	}
	fclose(auxarchivo);
	return k;
}

void VerificarArchivo(FILE *archivo)
{
	if(archivo == NULL)
	{
		printf("Error al abrir archivo\n");
		exit(-1);
	}
}

int SubMenu(int submenu, char **Lista, int NumWords)
{
	int opcion = 0, PalA, PalB;
	clrscr();
	printf("Sub Menu:\n1.-Aplicar Operacion\n2.-Regresar\n");
	scanf("%d",&submenu);					
	switch(submenu)
	{
		case 1:
			printf("Aplicar Operacion\n");
			printf("1.-Longitud\n2.-Concatenar\n3.-Inversion\n4.-Sufijos\n5.-Prefijos\n6.-SubCadenas\n7.-Subsecuencias\n8.-Regresar\n");
			fflush(stdin);
			scanf("%d",&opcion);
			switch(opcion)
			{
				case 1:
					printf("Escoger la palabra que se usará: \n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					ImpLongitud(Lista[PalA]);
					getchar();
					break;

				case 2:
					printf("Escoger la primer palabra:\n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					printf("Escoger la segunda palabra:\n");
					MostrarLista(Lista);
					scanf("%d",&PalB);
					printf("Las palabras seleccionadas son:\n%d.-%s\n%d.-%s\n",PalA,Lista[PalA],PalB,Lista[PalB]);
					Concatenacion(Lista[PalA],Lista[PalB],Lista);
					getchar(); 
					break;

				case 3:
					printf("Escoger la palabra a invertir: \n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					Invertir(Lista[PalA],Lista);
					getchar();
					break;

				case 4:
					printf("Escoger la palabra para mostrar sus sufijos:\n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					Sufijos(Lista[PalA]);
					getchar();
					break;

				case 5:
					printf("Escoger la palabra para mostrar sus prefijos:\n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					Prefijos(Lista[PalA]);
					getchar();
					break;

				case 6:
					printf("Escoger la palabra :\n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					SubCadenas(Lista[PalA]);
					getchar();
					break;

				case 7:
					printf("Escoger la palabra 1:\n");
					MostrarLista(Lista);
					scanf("%d",&PalA);
					printf("Escoger la palabra 2:\n");
					MostrarLista(Lista);
					scanf("%d",&PalB);
					SubSecuencias(Lista[PalA],Lista[PalB]);
					getchar();
					break;

				case 8:
					break;

				default:
					printf("El valor introducido no es válido.\n");
					break;
			}
			break;
		case 2:
			break;
	}
	return submenu;
}

int MenuPrincipal(int menu)
{
	clrscr();
	int submenu, k, j, NumWords, length;
	char *palabra, *aux, auxstr[1000];
	char **Lista;
	FILE *archivo;
	archivo = fopen("palabras.txt","r");
	submenu = k = j = 0;
	printf("Menu Principal:\n1.- Seleccionar Palabra de Archivo\n2.- Introducir palabra desde teclado\n3.- Salir\n");
	scanf("%d",&menu);
	switch(menu)
	{
		case 1:
			printf("Palabra desde archivo\n");
			VerificarArchivo(archivo);
			NumWords = GetNumWordsFile();
			Lista = calloc('\0',sizeof(char) * NumWords+1);
			int i = 1;
			while(fgets(auxstr,100,archivo) != NULL)
			{
				j=0;
				while(auxstr[j] != ',')
				{
					j++;
				}
				aux = calloc('\0',sizeof(char)*j);
				for (int x = 0; x < j; ++x)
				{
					aux[x] = auxstr[x];
				}
				Lista[i] = aux;
				i++;
				Lista[i] = NULL;
			}
			MostrarLista(Lista);
			fflush(stdin);
			getchar();
			getchar();
			while(submenu != 2)
			{
				submenu = SubMenu(submenu,Lista,NumWords);
			}
			break;

		case 2:
			submenu = 0;
			printf("Palabras desde teclado\nEscribir el número de palabras:\n");
			scanf("%d",&NumWords);
			Lista = malloc(sizeof(char *) * NumWords);
			for (int i = 1; i <= NumWords; ++i)
			{
				aux = calloc('\0',sizeof(char) * 1000);
				printf("Escribir la palabra %d\n", i);
				scanf("%s",aux);
				int length = TamArreglo(aux);
				palabra = malloc(sizeof(char) * length);
				IgualarAux(aux,palabra,length);
				ImpPalabra(palabra,length);
				Lista[i] = palabra;
				Lista[i+1] = NULL;
				MostrarLista(Lista);
			}
			while(submenu != 2)
			{
				submenu = SubMenu(submenu,Lista,NumWords);
			}
			break;

	}
	if(Lista != NULL)
	{
		free(Lista);
		free(aux);	
	}
	return menu;
}