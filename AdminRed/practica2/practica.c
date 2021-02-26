#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>
#define SHARED 1
#define PRODUCCIONES 10000

int value;
int consumos_totales=0;

sem_t in_main_section, out_main_section;
sem_t crit_sec[6];
sem_t crit_sec_cons[6];
sem_t escribiendo;

FILE * fichero1;
FILE * fichero2;
FILE * fichero3;
FILE * fichero4;

int w=1,x=2,y=3,z=4;
int *a=&w;
int *b=&x;
int *c=&y;
int *d=&z;

int data1, data2, data3, data4, data5, data6;

void crear_semaforos_CS();
void * producer();
void * consumer();
void producir();
void consumir();
void preguntar();
void preguntar_consumidor();
void escribir_txt();

int main(){

    pthread_t prod1, prod2, prod3, prod4;   //4 productores
    pthread_t cons1, cons2, cons3;          //3 consumidores

    // inicializacion de semaforos
    crear_semaforos_CS();

    pthread_create(&prod1, NULL, producer,(void*)a);
    pthread_create(&prod2, NULL, producer,(void*)b);
    pthread_create(&prod3, NULL, producer,(void*)c);
    pthread_create(&prod4, NULL, producer,(void*)d);

    pthread_create(&cons1,NULL,consumer,(void*)a);
    pthread_create(&cons2,NULL,consumer,(void*)b);
    pthread_create(&cons3,NULL,consumer,(void*)c);
    
    pthread_join(prod1,NULL);
    pthread_join(prod2,NULL);
    pthread_join(prod3,NULL);
    pthread_join(prod4,NULL);

    pthread_join(cons1,NULL);
    pthread_join(cons2,NULL);
    pthread_join(cons3,NULL);

    
    return 0;
}

void * producer(void * no){
    int contador1111=1;
    int dato1=1111;

    int contador2222=1;
    int dato2=2222;

    int contador3333=1;
    int dato3=3333;
    
    int contador4444=1;
    int dato4=4444;

    int *thread = (int*)no;
    printf("Hi, i'm the producer %d - ID: %ld\n",*thread,pthread_self());
    switch (*thread){
        case 1:
        printf("voy a producir 1111\n");
        producir(contador1111,dato1);
        break;

        case 2:
        printf("voy a producir 2222\n");
        producir(contador2222,dato2);
        break;

        case 3:
        printf("voy a producir 3333\n");
        producir(contador3333,dato3);
        break;
        
        case 4:
        printf("voy a producir 4444\n");
        producir(contador4444,dato4);
    }
}

void producir(int contador, int dato){
    int count=contador;
    for(int i=0;i<PRODUCCIONES;i++){
        sem_wait(&in_main_section);
            preguntar(count, dato);
        sem_post(&out_main_section);
    }

}

void * consumer(void * no){
    int *thread = (int*)no;
    printf("\nConsumer %d created-ID %d",*thread,pthread_self());
    //este for nomas es para ver que jale 
    //debemos de quitarlo y usar un while que pueda terminar de alguna forma
    if (*thread == 1 || *thread == 2){
        for (int i = 0; i<13333; i++){
            consumir();
        }
    }else{
        for (int i = 0; i<13334; i++){
        consumir();
        }
    }
}


void consumir(){
    sem_wait(&out_main_section);
        preguntar_consumidor();
    sem_post(&in_main_section);
}


void crear_semaforos_CS(){

    sem_init(&in_main_section, SHARED, 6);//empieza en 6 para poder acceder a las 6 secciones criticas
    sem_init(&out_main_section,SHARED,0);
    sem_init(&escribiendo,SHARED,1);

    for(int i=0;i<6;i++){
        sem_init(&crit_sec[i],SHARED,1);
    }
    int value;

    for(int i=0;i<6;i++){
        sem_init(&crit_sec_cons[i],SHARED,0);
    }
}

void preguntar(int contador, int dato){
    if (sem_trywait(&crit_sec[0])==-1){
        printf("seccion critica 1 OCUPADA, intentando entrar a seccion critica 2\n");
        if (sem_trywait(&crit_sec[1])==-1){
            printf("seccion critica 2 OCUPADA, intentando entrar a seccion critica 3\n");
            if(sem_trywait(&crit_sec[2])==-1){
                printf("seccion critica 3 ocupada, intentando entrar a la seccion critica 4\n");
                if(sem_trywait(&crit_sec[3])==-1){
                    printf("seccion critica 4 ocupada, intentando entrar a la seccion critica 5\n");
                    if(sem_trywait(&crit_sec[4])==-1){
                        printf("seccion critica 5 ocupada, intentando entrar a la seccion critica 6\n");
                        if(sem_trywait(&crit_sec[5])==-1){
                            printf("seccion critica 6 ocupada, intentando entrar a la seccion critica 1\n");
                            preguntar(contador, dato);
                        }else{
                            printf("Productor entro en la seccion critica 6\n");
                            data6 = dato;
                            sem_post(&crit_sec_cons[5]);
                            return;
                        }
                    }else{
                        printf("Productor entro en la seccion critica 5\n");
                        data5 = dato;
                        sem_post(&crit_sec_cons[4]);
                        return;
                    }
                }else{
                    printf("Productor entro en la seccion critica 4\n");
                    data4 = dato;
                    sem_post(&crit_sec_cons[3]);
                    return;
                }
            }else{
                printf("Productor entro en la seccion critica 3\n");
                data3 = dato;
                sem_post(&crit_sec_cons[2]);
                return;
            }
        }else{
            printf("Productor entro a la seccion critica 2\n");
            data2 = dato;
            sem_post(&crit_sec_cons[1]);
            return;
        }
    }else{
        printf("Productor entro en la seccion critica 1\n");
        data1 = dato;
        sem_post(&crit_sec_cons[0]);
        return;
    }
}

void preguntar_consumidor(){
    if (sem_trywait(&crit_sec_cons[0])==-1){
        printf("no se puede Consumir lo que esta en la SC1, intentando consumir lo de la SC2\n");
        if(sem_trywait(&crit_sec_cons[1])==-1){
            printf("no se puede consumir lo de SC2, intentando consumir SC3\n");
            if(sem_trywait(&crit_sec_cons[2])==-1){
                printf("no se puede consumir lo de SC3, intentando consumir SC4\n");
                if(sem_trywait(&crit_sec_cons[3])==-1){
                    printf("no se puede consumir lo de SC4, intentando consumir SC5\n");
                    if(sem_trywait(&crit_sec_cons[4])==-1){
                        printf("no se puede consumir lo de SC5, intentando consumir SC6\n");
                        if(sem_trywait(&crit_sec_cons[5])==-1){
                            printf("no se puede consumir lo de SC6, intentando consumir SC1\n");
                            preguntar_consumidor();
                        }else{
                            printf("se consumio SC6\n");
                            escribir_txt(5,data6);
                        }
                    }else{
                        printf("se consumio SC5\n");
                        escribir_txt(4,data5);
                    }
                }else{
                    printf("se consumio SC4\n");
                    escribir_txt(3,data4);
                }
            }else{
                printf("se consumio SC3\n");
                escribir_txt(2,data3);
            }
        }else{
            printf("se consumio SC2\n");
            escribir_txt(1,data2);
        }
    }else{
        printf("se consumio SC1\n");
        escribir_txt(0,data1);
    }   
}

void escribir_txt(int crit_sec_num, int numero_guardar){
    switch(numero_guardar){
        case 1111:
            sem_wait(&escribiendo);
            printf("se guardo el dato 1111\n");
            consumos_totales++;
            printf("%d\n",consumos_totales);
            fichero1 = fopen("unos.txt","a");
            fprintf(fichero1,"%d\n",numero_guardar);
            fclose(fichero1);
            sem_post(&escribiendo);
            sem_post(&crit_sec[crit_sec_num]); 
            break;

        case 2222:
            sem_wait(&escribiendo);
            printf("se guardo el dato 2222\n");
            consumos_totales++;
            printf("%d\n",consumos_totales);
            fichero2 = fopen("doses.txt","a");
            fprintf(fichero2,"%d\n",numero_guardar);
            fclose(fichero2);
            sem_post(&escribiendo);
            sem_post(&crit_sec[crit_sec_num]);
            break;

            case 3333:
            sem_wait(&escribiendo);
            printf("se guardo el dato 3333\n");
            consumos_totales++;
            printf("%d\n",consumos_totales);
            fichero3 = fopen("tres.txt","a");
            fprintf(fichero3,"%d\n",numero_guardar);
            fclose(fichero3);
            sem_post(&escribiendo);
            sem_post(&crit_sec[crit_sec_num]);
            break;

            case 4444:
            sem_wait(&escribiendo);
            printf("se guardo el dato 4444\n");
            consumos_totales++;
            printf("%d\n",consumos_totales);
            fichero4 = fopen("cuatros.txt","a");
            fprintf(fichero4, "%d\n",numero_guardar);
            fclose(fichero4);
            sem_post(&escribiendo);
            sem_post(&crit_sec[crit_sec_num]);
            break;   
    }
}
