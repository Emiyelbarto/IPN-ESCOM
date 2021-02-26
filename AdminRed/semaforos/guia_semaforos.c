#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SHARED 1

void *productor();
void *consumidor();

sem_t empty, full, sm;
int data;

int main(int argc, char const *argv[])
{
    pthread_t ptid1, ptid2, ptid3, ctid1, ctid2, ctid3;
    int x = 1, y = 2, z = 3;
    int *consumidor1 = &x;
    int *consumidor2 = &y;
    int *consumidor3 = &z;
    printf("\nComienzo del programa\n");
    sem_init(&empty, SHARED, 1);
    sem_init(&full, SHARED, 0);
    sem_init(&sm, SHARED, 1);

    pthread_create(&ptid1, NULL, productor, NULL);
    pthread_create(&ptid2, NULL, productor, NULL);
    pthread_create(&ptid3, NULL, productor, NULL);
    pthread_create(&ctid1, NULL, consumidor, (void*)consumidor1);
    pthread_create(&ctid2, NULL, consumidor, (void*)consumidor2);
    pthread_create(&ctid3, NULL, consumidor, (void*)consumidor3);
    printf("\nFin del programa\n");
}

void *productor()
{
    int producido;
    printf("Productor creado.\n");
    printf("id del productor: %ld\n", pthread_self());
    for (producido = 0; producido < 10; producido++)
    {
        sem_wait(&empty);
        // Comienza bloqueo
        sem_wait(&sm);
        // Seccion critica
        data = producido;
        // Seccion critica
        sem_post(&sm);
        // Acaba bloqueo
        sem_post(&full);
        printf("Productor: %d\n", data);
    }
}

void *consumidor(void *num_hilo) {
    int consumido, total = 0;
    int *hilo = (int*)num_hilo;
    printf("Consumidor creado\n");
    printf("ID de Consumidor: %ld\n", pthread_self());

    for (consumido = 0; consumido < 10; consumido++)
    {
        sem_wait(&full);
        //Bloqueo
        sem_wait(&sm);
        //Seccion critica
        total += data;
        printf("\nHilo %d, consumio: %d\n", *hilo, data);
        //SEccion critica
        sem_post(&sm);
        //Acaba bloqueo
        sem_post(&empty);
    }
    printf("Consumidor acabo sus 10 iteraciones para el hilo %d con %d valor\n", *hilo, total);
}