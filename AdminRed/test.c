#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

// Recibir la funcion en memoria global para los hilos
void *function(void *);
// void *thread_func(void *args);
//recibir desde parametros de consola el numero de hilos a crear
int main(int argc, char const *argv[])
{
    //paso 0: Recepcion del numero de hilos a crear
    if (argc == 2)
    {
        int num_hilos;
        //Definir el numero de hilos
        num_hilos = atoi(argv[1]);
        printf("num de hilos: %d\n", num_hilos);
        //Definir los hilos que se crearan
        pthread_t *hilo;
        hilo = (pthread_t *)malloc(num_hilos * sizeof(pthread_t));
        int retvals;
        for (size_t i = 0; i < num_hilos; i++)
        {
            retvals = pthread_create(&hilo[i], NULL, function, (void *)&i);
            if (retvals != 0)
            {
                printf("pthread fallo en el hilo %d_th \n", i);
                break;
            }
            usleep(1000);
        }
        for (size_t i = 0; i < num_hilos; i++)
        {
            retvals = pthread_join(hilo[i], NULL);
            if (retvals != 0)
            {
                printf("pthread_join fallo en el hilo %d_th", i);
                exit(EXIT_FAILURE);
            }
        }
        return 0;
    }
    else
    {
        printf("Introducir el numero de hilos\n");
        return -1;
    }
}

void *function(void *parametro)
{
    int var = *((int *)parametro);
    pid_t tid = syscall(SYS_gettid);
    printf("Hola desde el hilo %d con ID: %d\n", var, (int)tid);
    pthread_exit(NULL);
}

// void *thread_func(void *args)
// {
//     const char *str = (const char *)args;

//     printf("Threading %s\n", str);
//     usleep(1000);
// }
