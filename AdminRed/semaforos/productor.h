#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>

typedef struct{
    int bandera;
    int producto;
    char mensaje[15];
}seccionCritica[10];

void esperar(int numsem, int idSemaforo);
void avisar(int numsem, int idSemaforo);
seccionCritica *crearLigarMemoria(key_t llave_mem);
void crearLigarSemaforo(key_t llave);

void esperar(int numsem, int idSemaforo){
    struct sembuf operacion;
    operacion.sem_num = numsem;
    operacion.sem_op = -1;
    operacion.sem_flg = SEM_UNDO;
    semop(idSemaforo, &operacion, 1);
}

void avisar(int numsem, int idSemaforo){
    struct sembuf operacion;
    operacion.sem_num = numsem;
    operacion.sem_op = 1;
    operacion.sem_flg = SEM_UNDO;
    semop(idSemaforo, &operacion, 1);
}

seccionCritica *crearLigarMemoria(key_t llave_mem){
    int i= 0;
    seccionCritica *apuSeccion = NULL;

    if((idMemoria = shmget(llave_mem, sizeof(seccionCritica), IPC_CREAT | IPC_EXCL| 0600)) == -1){
        if((idMemoria = shmget(llave_mem, sizeof(seccionCritica), 0600)) == -1){
            printf("no se puede ligar con la memoria\n");
            exit(-1);
        }else{
            printf("productor se ligo a memoria\n");
        }
    }else{
        printf("productor creo memoria\n");
    }

    if((apuSeccion = (seccionCritica*)shmat(idMemoria, 0, 0)) == NULL){
        printf("no se pude crear memoria compartida\n");
        exit(-1);
    }

    return apuSeccion;
}

void crearLigarSemaforo(key_t llave){
    if((idSemaforo = semget(llave, numeroSemaforos, IPC_CREAT| IPC_EXCL | 0600)) == -1){
        if((idSemaforo = semget(llave, numeroSemaforos, 0600)) == -1){
            printf("error al enlazar\n");
            exit(-1);
        }else{
            printf("productor ligo semaforos\n");
        }
    }else{
        printf("productor creo semaforos\n");
        semctl(idSemaforo, 0, SETVAL, 1); //Semaforo PRODUCTOR (interno) 1
        semctl(idSemaforo, 1, SETVAL, 1); //Semaforo PRODUCTOR (interno) 2 
        semctl(idSemaforo, 2, SETVAL, 1); //Semaforo PRODUCTOR (interno) 3
        semctl(idSemaforo, 3, SETVAL, 1); //Semaforo PRODUCTOR (interno) 4
        semctl(idSemaforo, 4, SETVAL, 1); //Semaforo PRODUCTOR (interno) 5
        semctl(idSemaforo, 5, SETVAL, 1); //Semaforo PRODUCTOR (interno) 6
        semctl(idSemaforo, 6, SETVAL, 1); //Semaforo PRODUCTOR (interno) 7
        semctl(idSemaforo, 7, SETVAL, 1); //Semaforo PRODUCTOR (interno) 8
        semctl(idSemaforo, 8, SETVAL, 1); //Semaforo PRODUCTOR (interno) 9
        semctl(idSemaforo, 9, SETVAL, 1); //Semaforo PRODUCTOR (interno) 10
        semctl(idSemaforo, 10, SETVAL, 1); //Semaforo PRODUCTOR
        semctl(idSemaforo, 11, SETVAL, 1); //Semaforo CONSUMIDOR
        semctl(idSemaforo, 12, SETVAL, 1); //Semaforo ARCHIVO 1
        semctl(idSemaforo, 13, SETVAL, 1); //Semaforo ARCHIVO 2
        semctl(idSemaforo, 14, SETVAL, 1); //Semaforo ARCHIVO 3
        semctl(idSemaforo, 15, SETVAL, 1); //Semaforo ARCHIVO 4
        semctl(idSemaforo, 16, SETVAL, 1); //Semaforo ARCHIVO 5
        semctl(idSemaforo, 17, SETVAL, 1); //Semaforo ARCHIVO 6
        semctl(idSemaforo, 18, SETVAL, 1); //Semaforo ARCHIVO 7
        semctl(idSemaforo, 19, SETVAL, 1); //Semaforo ARCHIVO 8
        semctl(idSemaforo, 20, SETVAL, 1); //Semaforo ARCHIVO 9
        semctl(idSemaforo, 21, SETVAL, 1); //Semaforo ARCHIVO 10
    }
}

