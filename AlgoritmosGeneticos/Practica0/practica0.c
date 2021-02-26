/*
Codigo para generar una lista de numeros aleatorios
Autor: José Emiliano Pérez Garduño
Materia: Genetic Algorithms
Grupo: 3CM8
*/

#include <stdio.h>
#include <stdlib.h>

int ConseguirLongitudLista(char * L);           //Función para conseguir la longitud y crear la lista
char * PoblarLista(int l, char * L);            //Función para poblar aleatoriamente la lista
void MostrarLista(char * L);                    //Función para mostrar la Lista
char * AcomodarLista(char * L);                 //Función para acomodar la Lista
void ListaBinario(char * L);                    //Función para imprimir la lista en binario
void NumBinario(int n);                         //Función para imprimir un numero entero en binario (16 bits)

int main(int argc, char const *argv[])
{
    int l;
    char *L;

    printf("Programa para generar una lista de numeros aleatorios.\n\n");
    printf("Escribir cuantos numeros quiere que tenga la lista:\n");

    scanf("%d",&l);
    printf("Creando Lista de %d numeros.\n",l);

    L = calloc(sizeof(int) * (l+1),0);
    L = PoblarLista(l,L);
    MostrarLista(L);
    L = AcomodarLista(L);
    ListaBinario(L);
    return 0;
}

int ConseguirLongitudLista(char * L)                //Función para conseguir la longitud de una lista
{
    int l;
    l = 0;
    while (L[l] != '\0')
        l++;
    return l;
}

char * PoblarLista(int l, char * L)                 //Función para poblar la lista con numeros aleatorios
{
    int i, n, fin, inicio;
    time_t t;
    srand((unsigned) time(&t));
    printf("Escribir el inicio del rango de numeros aleatorios\n");
    scanf("%d",&inicio);
    printf("Escribir el fin del rango de numeros aleatorios:\n");
    scanf("%d",&fin);
    for (i = 0; i <= l; i++)
    {
        if(i == l)
        {
            L[i] = '\0';
        }
        else
        {
            n = rand() % (fin-inicio) + inicio;
            L[i] = n;
        }
    }
    return L;
}

void MostrarLista(char * L)
{
    int l = ConseguirLongitudLista(L);
    int i;
    printf("[");
    for (i = 0; i < l; i++)
    {
        if(i != l-1)
            printf("%d,",L[i]);
        else
            printf("%d]\n",L[i]);
    }    
}

char * AcomodarLista(char * L)
{
    int i, j, aux;
    int l = ConseguirLongitudLista(L);
    printf("Acomodando Lista.\n");
    for(i = 0; i < l; i++)
    {
        for(j = i + 1; j < l; j++)
        {
            if(L[i] >= L[j])
            {
                aux = L[i];
                L[i] = L[j];
                L[j] = aux;
            }
        }
    }
    MostrarLista(L);
    return L;
}

void ListaBinario(char * L)
{
    int i, l;
    l = ConseguirLongitudLista(L);
    printf("Index\tNumeroEntero\tNumeroBinario\n");
    for (i = 0; i < l; i++)
    {
        printf("%d.- \t%d\t\t",i,L[i]);
        NumBinario(L[i]);
    }
}

void NumBinario(int num)
{
    int i, j;
    for (i = 15; i >= 0; i--)
    {
        j = num >> i;
        if (j & 1)
            printf("1");
        else
            printf("0");
    }
  printf("\n");
}
