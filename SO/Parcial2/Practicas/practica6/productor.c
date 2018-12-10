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

int main(int argc, char **argv){
    int i = 0, i2 = 0, producciones = 0, status[4];
    char mensaje[] = "Mensaje US ";
    char *numeroUsuarios[5] = {"1", "2", "3", "4", "5"};
    char *numeroLlamada[5] = {"13571899", "54895003", "38379249", "62709474", "21609754"};

    key_t llave;
    seccionCritica *apuSeccion;
    llave = ftok("/bin/ls", 21);
    crearLigarSemaforo(llave);
    apuSeccion = crearLigarMemoria(llave);
    
    pid_t pid;
    printf("idSemaforo:%d\t idMemoria:%d\n",idSemaforo,idMemoria);

    for(i2 = 0; i2 < 4; i2++){
		if((pid = fork()) == -1){
    		printf("error\n");
        	exit(-1);
    	}else if(pid == 0){
    		while(producciones < 25000){
    			esperar(10, idSemaforo);
   				for(i = 0; i < 10; i++){
   	     			esperar(i, idSemaforo);
                    if(apuSeccion[i]->producto < 10000){
                        if(apuSeccion[i]->bandera != 1){
                            if(i < 5){
                                strcpy(apuSeccion[i]->mensaje, numeroLlamada[i]);
                                printf("%d - Productor %d, escribio:%s en la seccion critica %d\n", apuSeccion[i]->producto, i2+1, apuSeccion[i]->mensaje, i);
                            }else{
                                strcpy(apuSeccion[i]->mensaje, strcat(mensaje, numeroUsuarios[i-5]));
                                printf("%d - Productor %d, escribio:%s en la seccion critica %d\n", apuSeccion[i]->producto, i2+1, apuSeccion[i]->mensaje, i);
                                strcpy(mensaje, "Mensaje US ");
                            }
                            apuSeccion[i]->producto++;
                            apuSeccion[i]->bandera = 1;
                            producciones++;
                            avisar(i, idSemaforo);
                            break;
                        }
                    }
        			avisar(i, idSemaforo);
        		}
       		 	avisar(10, idSemaforo);
    		}
    		exit(0);
    	}else{
    		if(i2 == 3){
    	    	for(i2 = 0; i2 < 4; i2++){
					wait(&status[i2]);
				}
    		}
	    }
	}

    shmdt(apuSeccion);
    printf("finaliza la producción\n");
    shmctl(idMemoria, IPC_RMID, 0);
    semctl(idSemaforo, 0, IPC_RMID);
    
    return 0;
}