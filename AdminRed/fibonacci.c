#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
SERIE DE FIBONACCI CON HILOS 
CREATED BY Victor Anaya - ESCOM IPN
sientete libre de usar mi codigo UwU
*/

void *fibo(void *arg)
{
    int a = 0;
    int b = 1;
    int c;
    int numero_max = *((int *)arg);
    if (numero_max == 0)
    {
        printf("la serie fibo es: 0\n");
    }
    else if (numero_max == 1)
    {
        printf("la serie fibo es: 0,1\n");
    }
    else
    {
        printf("la serie fibo es: 0, 1, ");
        do
        {
            c = a + b;
            if (c > numero_max)
            {
                break;
            }

            printf("%d, ", c);
            a = b;
            b = c;
        } while (c <= numero_max);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int num_param = argc - 1;
    int array_valores_consola[num_param];
    for (int i = 0; i < num_param; i++)
    {
        array_valores_consola[i] = atoi(argv[i + 1]);
        printf("%d\n", array_valores_consola[i]);
    } //fin del for

    printf("numero de parametros ingresados: %d\n", num_param);
    pthread_t *arreglo_hilos = (pthread_t *)malloc(sizeof(pthread_t) * num_param);
    for (int i = 0; i < num_param; i++)
    {
        int err = pthread_create(&arreglo_hilos[i], NULL, fibo, (void *)&array_valores_consola[i]);
        if (err != 0)
        {
            printf("error al crear los hilos\n");
            break;
        } //fin del if
    }     //fin del for
    for (int i = 0; i < num_param; i++)
    {
        int err_join = pthread_join(arreglo_hilos[i], NULL);
        if (err_join != 0)
        {
            printf("error al esperar un hilo\n");
            break;
        }

    } //fin del for
    free(arreglo_hilos);

} //fin del main