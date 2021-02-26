#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include 'productor.h'

#define numeroSemaforos 1
int idSemaforo;
int idMemoria;

typedef struct{
    int bandera;
    int producto;
    char mensaje[15];
}seccionCritica[10];

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