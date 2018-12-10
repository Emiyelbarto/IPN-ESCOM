#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEM_HIJO 0
#define SEM_PADRE 1
#define NUM_SEM 6
//3 SEMAFOROS PRODUCTORES EMPIZAN EN 1 Y LOS 3 CONSUMIDORES EMPIEZAN EN 0

void wait(int numsem,int semid);
void signal(int numsem,int semid);

/*
struct{
	int bandera;
	char [3];
	3 seccioncritica[3];
}
*/

int main(int argc, char **argv)
{
    int i = 100, semid;
    pid_t pid;
    key_t llave;

    /*Es una llave requeria para que el semaforo sea identificado por el kernel*/
    llave = ftok(argv[0],'K');
    /*forma de incializar semáforos, en este caso se ocupan dos semaforos*/
    /*(clave para referense al kernel,numero de semáforos,bandera para crear semáforos)*/
    if((semid = semget(llave,NUM_SEM,IPC_CREAT | 0600)) == -1)
    
    {
        if((semid = semget(llave,NUM_SEM,0600)) == -1)
        {
            printf("error al enlazar\n");
            exit(-1);
        }
    }
    
    else
    
    {
        /*inicializamos los semáforos*/
        /*cerramos el semáforo del proceso hijo*/
        semctl(semid,SEM_HIJO,SETVAL,0);
        /*Abrimos el semáforo del proceso padre*/
        semctl(semid,SEM_PADRE,SETVAL,1);
    }

        if((pid = fork()) == -1)
        {
            perror("fork");
            exit(-1);
        }
        else if(pid == 0)
        {
            while(i)
            {
                wait(SEM_HIJO,semid);
                printf("soy el proceso hijo id:%d y consumo i = %d\n" ,getpid(),i--);
                sleep(.5);
                signal(SEM_PADRE,semid);
            }
            
            /*borramos el semáforo*/
            semctl(semid,0,IPC_RMID,0);
        }
        else
        {
            while(i)
            {
                wait(SEM_PADRE,semid);
                printf("proceso padre id:%d, produzco  i = %d\n\n",getpid(),i--);
                signal(SEM_HIJO,semid);
            }
            /*borrado del semáforo*/
            semctl(semid,0,IPC_RMID,0);
        }
    return 0;
}
void wait(int numsem,int semid)
{  
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
/*restamos una unidad al semáforo*/
    operacion.sem_op = -1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
 * tiene el arreglo*/
    semop(semid,&operacion,1);
}

void signal(int numsem,int semid)
{
    struct sembuf operacion;
    /*cerramos el semáforo del proceso padre*/
    operacion.sem_num = numsem;
/*restamos una unidad al semáforo*/
    operacion.sem_op = 1;
    operacion.sem_flg = SEM_UNDO;
    /*aplicamos las operaciones, el 1 indica el numero de structuras que
 * tiene el arreglo*/
    semop(semid,&operacion,1);
}
