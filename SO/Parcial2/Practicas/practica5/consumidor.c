#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define numeroSemaforos 22

int idSemaforo;
int idMemoria;

typedef struct{
    int bandera;
    int producto;
    char mensaje[15];
}seccionCritica[10];

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
            printf("consumidor se ligo a memoria\n");
        }
    }else{
        printf("consumidor creo memoria\n");
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
            printf("consumidor se ligo a semaforos\n");
        }
    }else{
        printf("consumidor creo semaforos\n");
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

int main(int argc, char **argv){
    int i = 0, i2 = 0, consumos = 0, status[3];
    char mensaje[15];
    char *rutas[10] = {"/home/gordy/llamada1.txt", "/home/gordy/llamada2.txt", "/home/gordy/llamada3.txt",
                    "/home/gordy/llamada4.txt", "/home/gordy/llamada5.txt",
                    "/home/gordy/mensaje1.txt", "/home/gordy/mensaje2.txt", "/home/gordy/mensaje3.txt",
                    "/home/gordy/mensaje4.txt", "/home/gordy/mensaje5.txt"};
    FILE *archivo;
    
    key_t llave;
    seccionCritica *apuSeccion;
    llave = ftok("/bin/ls",21);
    crearLigarSemaforo(llave);
    apuSeccion = crearLigarMemoria(llave);

    pid_t pid;
    printf("idSemaforo:%d\t idMemoria:%d\n",idSemaforo,idMemoria);

    for(i2 = 0; i2 < 3; i2++){
        if((pid = fork()) == -1){
            printf("error\n");
            exit(-1);
        }else if(pid == 0){
            while(consumos < 13500){
                esperar(11, idSemaforo);
                for(i = 0; i < 10; i++){
                    esperar(i, idSemaforo);
                    if(apuSeccion[i]->bandera == 1){
                        esperar(i+12, idSemaforo);
                        archivo = fopen(rutas[i], "a");
                        fprintf(archivo, "%s\n", apuSeccion[i]->mensaje);
                        fclose(archivo);
                        avisar(i+12, idSemaforo);
                        printf("Consumidor %d, consumio:%s en la seccion critica %d\n", i2+1, apuSeccion[i]->mensaje, i);
                        apuSeccion[i]->bandera = 0;
                        consumos++;
                        avisar(i, idSemaforo);
                        break;
                    }
                    avisar(i, idSemaforo);
                }
                avisar(11, idSemaforo);
            }
            exit(0);
        }else{
            if(i2 == 2){
                for(i2 = 0; i2 < 3; i2++){
                    wait(&status[i2]);
                }
            }
        }
    }

    shmdt(apuSeccion);
    printf("finaliza el consumo\n");
    shmctl(idMemoria, IPC_RMID, 0);
    semctl(idSemaforo, 0, IPC_RMID);
    
    return 0;
}