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
    int i = 0, i2 = 0, producciones = 0, status[4];
    char mensaje[] = "Mensaje US ";
    char *numeroUsuarios[5] = {"1", "2", "3", "4", "5"};
    char *numeroLlamada[5] = {"13571899", "54895003", "38379249", "62709474", "21609754"};

    key_t llave;
    seccionCritica *apuSeccion;
    llave = ftok("/bin/ls", 21);
    crearLigarSemaforo(llave);
    apuSeccion = crearLigarMemoria(llave);
    
    for(i = 0; i < 10; i++){
        apuSeccion[i]->producto = 0;
    }

    pid_t pid;
    printf("idSemaforo:%d\t idMemoria:%d\n",idSemaforo,idMemoria);

    for(i2 = 0; i2 < 4; i2++){
		if((pid = fork()) == -1){
    		printf("error\n");
        	exit(-1);
    	}else if(pid == 0){
    		while(producciones < 10125){
    			esperar(10, idSemaforo);
   				for(i = 0; i < 10; i++){
   	     			esperar(i, idSemaforo);
       			 	if(apuSeccion[i]->bandera != 1){
       			 		if(i < 5){
       			 			strcpy(apuSeccion[i]->mensaje, numeroLlamada[i]);
           			 		printf("Productor %d, escribio:%s en la seccion critica %d\n", i2+1, apuSeccion[i]->mensaje, i);
       			 		}else{
       			 			strcpy(apuSeccion[i]->mensaje, strcat(mensaje, numeroUsuarios[i-5]));
           			 		printf("Productor %d, escribio:%s en la seccion critica %d\n", i2+1, apuSeccion[i]->mensaje, i);
       			 			strcpy(mensaje, "Mensaje US ");
       					}
            			apuSeccion[i]->bandera = 1;
            			producciones++;
           	 			avisar(i, idSemaforo);
           		 		break;
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