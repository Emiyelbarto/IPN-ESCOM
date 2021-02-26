#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

int N;
int global = 10;
int entrando[100];
int numero[100];

int max(int numero[100]) {
    int i = 0;
    int maximo = numero[0];
    for (i = 0; i < N; i++) {
        if (maximo < numero[i])
            maximo = numero[i];
        }
    return maximo;
    }

void bloquear(int i) {
    int j = 0;
    entrando[i] = TRUE;
    numero[i] = 1 + max(numero);
    entrando[i] = FALSE;
    for (j = 0; j < N; j++) {
        while (entrando[j]);
        while (numero[j] != 0 && (numero[j] < numero[i] || (numero[i] == numero[j]) && j < i)) {}
    }
}

void desbloquear(int i) {
    numero[i] = 0;
}

void *productor(void *integer) {
    int i = (int) integer;
    bloquear(i);
    printf("\n\n-----------Proceso %d---------",i);
    printf("\nProceso %d entra a seccion de memoria critica\n",i);
    global+= 20;
    printf("%d es el valor de global \n",global);
    printf("Proceso %d sale de seccion de memoria critica\n",i);
    printf("----------------------------------\n\n");
    desbloquear(i);
}

void *consumidor(void *integer) {
    int i = (int) integer;
    bloquear(i);
    printf("\n\n-----------Proceso %d---------",i);
    printf("\nProceso %d entra a seccion de memoria critica\n",i);
    global-= 20;
    printf("%d es el valor de global \n",global);
    printf("Proceso %d sale de seccion de memoria critica\n",i);
    printf("----------------------------------\n\n");
    desbloquear(i);
}    


int main()
{
    N = 2;
    int th[N];
    void *productor(void *);
    void *consumidor(void *);
    pthread_t hilo[N];
    int i = 0; 
    for (i = 0; i < N; i++) {
        th[i] = pthread_create(&hilo[i], NULL, productor, (void *)i); 
        pthread_join(hilo[i], NULL);
    }
    return EXIT_SUCCESS;
}