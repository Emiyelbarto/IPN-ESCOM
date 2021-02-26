#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 40
int contador1 = 0;
int contador2 = 0;
int contador3 = 0;

int cnt;
sem_t s_prod,s_cons;

void * Productor(void * a){
  int tmp;
  for(int i = 0; i < 20; i++)
  {
    sem_wait(&s_prod);
      tmp = 12;    
      cnt = tmp;           
    if (contador1 < 20)
      {
          contador1 = contador1+1;
          sem_post(&s_cons);
      }
      else
      {
          sem_post(&s_prod);
      }  
  }
    pthread_exit(NULL);
}


void * Productor2(void * a){
  int tmp;
  for(int i = 0; i < 20; i++)
  {
    sem_wait(&s_prod);
      tmp = 345;    
      cnt = tmp;     
      if (contador2 < 20)
      {
          contador2 = contador2+1;
          sem_post(&s_cons);          
      }
      else
      {
          sem_post(&s_prod);
      }    
  }
    pthread_exit(NULL);
}

void * Consumidor(void * a){
  int tmp;
    for(int i = 0; i < NITER; i++)
    {
      sem_wait(&s_cons);
        tmp = cnt;
        printf("Consumio %d, contador1: %d, contador2: %d\n",tmp,contador1,contador2); 
      sem_post(&s_prod);
    }
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    pthread_t prod, cons;
    sem_init(&s_prod, 0, 1);
    sem_init(&s_cons, 0, 0);

    if(pthread_create(&prod, NULL, Productor2, NULL))
    {
      printf("\n ERROR creating thread 1");
      exit(1);
    }

    if(pthread_create(&prod, NULL, Productor, NULL))
    {
      printf("\n ERROR creating thread 1");
      exit(1);
    }

    if(pthread_create(&cons, NULL, Consumidor, NULL))
    {
      printf("\n ERROR creating thread 2");
      exit(1);
    }    

    if(pthread_join(prod, NULL))	/* wait for the thread 1 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

    if(pthread_join(cons, NULL))        /* wait for the thread 2 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }
    sem_close( &s_prod );
    sem_destroy( &s_prod );
    sem_close( &s_cons );
    sem_destroy( &s_cons );
    return 0;
}