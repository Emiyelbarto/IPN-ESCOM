#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/shm.h>
#define SEM_CONSUMIDOR1 0
#define SEM_CONSUMIDOR2 1
#define SEM_PRODUCTOR1 2
#define SEM_PRODUCTOR2 3
#define NUM_SEM 4
#define PRODUCCION 20

int semid;
int memid;

typedef struct
{
    int bandera;
    char msg[10];
}seccion_crt[2];

void esperar(int numsem, int semid);
void avisar(int numsem, int semid);
void crear_ligar_sem(key_t llave);
seccion_crt * crear_ligar_mem(key_t mem, cha caracter[]);

int main(int argc, char const *argv[])
{
    key_t llave;
    seccion_crt *ptr;
    llave = ftok("/bin/ls",21);
    crear_ligar_sem(llave);
    crear_ligar_sem(llave);
    ptr =  crear_ligar_mem(llave);
    int i, j;

    printf("semid : %d \n memid : %d \n",semid,memid);

    pid_t pid;

    if(pid = fork() == -1)
    {
        printf("error\n");
        exit(-1);
    }
    else if (pid == 0){
        for(j=0;j<=10;j++){
            esperar(SEM_CONSUMIDOR2, semid);
            strcat(ptr[0]->msg , "z");
            printf("CONSUMIDOR2 escribio: %s en seccion_crt[1]\n",ptr[0]->msg);
            avisar(SEM_PRODUCTOR2, semid);
        }
    }
    else
    {
        int *estado;
        for(i=0;i<=10;i++){
            esperar(SEM_CONSUMIDOR1, semid);
            strcat(ptr[0]->msg , "a");
            printf("CONSUMIDOR1, consumio: %s en seccion_crt[0]\n",ptr[0]->msg);
            avisar(SEM_PRODUCTOR1, semid);
        }
        wait(estado);
    }

    //Desligando de la memoria
    shmdt(ptr);
    printf("Finaliza la produccion\n");
    //Destruyendo memoria compartida y semaforos
    shmctl(memid, IPC_RMID, 0);
    semctl(semid, 0, IPC_RMID);
    


    return 0;
}

seccion_crt * crear_ligar_mem(key_t llave_mem)
{
    int i = 0;
    seccion_crt *ptr = NULL;
    int memid;


    if()
    {
        //Creamos la memoria
        if((memid = shmget(llave_mem, sizeof(seccion_crt),IPC_CREAT | IPC_EXCL | 0600))==-1)
        {
            //Ligamos a la memoria
            if((memid = shmget(llave_mem, sizeof(seccion_crt), 0600))==-1)
            {
                printf("No se puede crear memoria compartida \n");
                exit(-1);
            }
            else
            {
                printf("CONSUMIDOR se ligo\n");
            }
        }
        else
        {
            printf("CONSUMIDOR creo la memoria compartida");
        }

        if((ptr = (seccion_crt *)shmat(memid,0,0))==   -1)
        {
            printf("No se puede crear memoria compartida\n");
            exit(-1);
        }

        while(i < PRODUCCION)
        {
            esperar(SEM_PRODUCTOR, semid);
            strcat(productor,caracter);
        }
    }
}

void esperar(int numsem, int semid)
{
    struct sembuf operacion;
    operacion.sem_num = numsem;
    operacion.sem_op = -1;
}

void crear_ligar_sem(key_t llave)
{
    //Creamos el semaforo
    if((semid = semget(llave, NUM_SEM, IPC_CREAT | IPC_EXCL | 0600))==-1)
    {
        //Ligamos el semaforo
        if((semid = semget(llave, NUM_SEM, 0600))==-1)
        {
            printf("Error al enlazar \n");
            exit(-1);
        }
        else
        {
            printf("CONSUMIDOR se ligó al semaforo")
        }
    }
    else
    {
        semctl(semid,SEM_CONSUMIDOR1,SETVAL,0);
        semctl(semid,SEM_CONSUMIDOR2,SETVAL,0);
        semctl(semid,SEM_PRODUCTOR1,SETVAL,0);
        semctl(semid,SEM_PRODUCTOR2,SETVAL,0);
    }
}