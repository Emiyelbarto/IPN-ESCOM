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

typedef struct
{
    int bandera;
    char msg[10];
}seccion_crt[2];

void esperar(int numsem, int semid);
void avisar(int numsem, int semid);
void crear_ligar_sem(key_t llave);
seccion_crt * crear_ligar_mem(key_t llave_mem, cha caracter[]);

int main(int argc, char const *argv[])
{
    key_t llave;
    seccion_crt *ptr;
    llave = ftok("/bin/ls",21);
    crear_ligar_sem(llave);
    crear_ligar_sem(llave);
    ptr =  crear_ligar_mem(llave);
    int i, j;

    for(i=0;i<=10;i++){
        esperar(SEM_PRODUCTOR1, semid);
        strcat(ptr[0].msg , "a");
        printf("Productor1 escribio: %s en seccion_crt[0]\n",ptr[0].msg);
        avisar(SEM_CONSUMIDOR1, semid);
    }

    pid_t pid;

    if(pid = fork() == -1)
    {
        printf("error\n");
        exit(-1);
    }
    else if (pid == 0){
        for(j=0;j<=10;j++){
            esperar(SEM_PRODUCTOR2, semid);
            strcat(ptr[0].msg , "z");
            printf("Productor2 escribio: %s en seccion_crt[0]\n",ptr[0].msg);
            avisar(SEM_CONSUMIDOR2, semid);
        }
    }
    else
    {
        int *estado;
        for(i=0;i<=10;i++){
            esperar(SEM_PRODUCTOR1, semid);
            strcat(ptr[0].msg , "a");
            printf("Productor1 escribio: %s en seccion_crt[0]\n",ptr[0].msg);
            avisar(SEM_CONSUMIDOR1, semid);
        }
        wait(estado);
    }

    //Desligando de la memoria
    shmdt(ptr);
    printf("Finaliza la produccion\n");
    


    return 0;
    /*
    //Creamos la memoria
    if((memid = shmget(llave_mem, sizeof(seccion_crt),IPC_CREAT | IPC_EXCL | 0600))==-1)
    {
        //Ligamos a la memoria
        if((memid = shmget(llave_mem, sizeof(seccion_crt), 0600))==-1)
        {
            printf("No se puede crear memoria compartida \n");
            exit(-1);
        }
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

    */
}

void esperar(int numsem, int semid)
{
    struct sembuf operacion;
    operacion.sem_num = numsem;
    operacion.sem_op = -1;
}

void crear_ligar_sem(key_t llave)
{
    int it = 0, memid;
    seccion_crt *ptr

        //Creamos la memoria
    if((semid = semget(llave_sem, NUM_SEM, IPC_CREAT | IPC_EXCL | 0600))==-1)
    {
        //Ligamos a la memoria
        if((semid = semget(llave_sem, NUM_SEM, 0600))==-1)
        {
            printf("Error al enlazar \n");
            exit(-1);
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