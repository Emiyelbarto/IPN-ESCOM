#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

#define buffersize 20

void clean(char msg[]){
	for (int i = 0; i < buffersize; ++i)
	{
		msg[i]='\0';
	}
}

int main(int argc, char const *argv[])
{
	//Definimos el pid para el fork
	pid_t pid;
	//Definimos el mensaje
	char *msg;
	msg = malloc(sizeof(char));
	//Definimos la respuesta
	char *ans;
	ans = malloc(sizeof(char));
	//definimos los bytes leidos
	int bytes;
	//definimos el buffer de los pipes
	char buffer[buffersize];
	//Definimos el tamaño del pipe de lectura
	int pipeA[2];
	//Definimos el tamaño del pipe de escritura
	int pipeB[2];
	//Definimios el resultado del pipe de lectura
	int a;
	//Definimos el resutlado del pipe de escritura
	int b;
	//Definimos el tamaño de la cadena
	int l;
	//Definimos el estado
	int *status;/*
	char *anshijo;
	anshijo = malloc(sizeof(char));
	char *msghijo;
	msghijo = malloc(sizeof(char));*/
	//Definimos nuestras pipes
	a = pipe(pipeA);
	b = pipe(pipeB);
	//El extremo 0 del pipe es para leer y el 1 para escribir.
	//DEfinimos el error de pipe
	if (a == -1 || b == -1)
	{

		perror("pipe");
		exit(EXIT_FAILURE);

	}

	pid = fork();

	switch(pid){

		case -1:
			printf("Error al hacer fork\n");
			exit(-1);

		case 0:
			close(pipeA[1]);
			close(pipeB[0]);
			printf("\n");

			do{
				clean(buffer);
				clean(msg);
				read(pipeA[0],ans,buffersize);
				printf("El padre escribio: \n");
				printf("%s\n", ans);
				if(strcmp(msg,"fin")==0){
					printf("\n");
					return 1;
				}

				clean(msg);
				clean(buffer);

				printf("\nEscribir el mensaje que el hijo enviara al padre:\n");
				fflush(stdin);
				scanf("%s",msg);
				strcpy(buffer,msg);
				write(pipeB[1],msg,strlen(buffer)+1);	
			}while(strcmp(buffer,"fin")!=0);
			close(pipeB[1]);
			close(pipeA[0]);
			clean(ans);
			//exit(0);
			break;

		default:
			close(pipeA[0]);
			close(pipeB[1]);

			do{
				//memset(msg,0x00,20);
				clean(buffer);
				clean(ans);
				clean(msg);
				printf("Escribir mensaje del padre al hijo:\n");
				fflush(stdin);
				scanf("%s",msg);
				fflush(stdin);
				l = strlen(msg);
				strcpy(buffer,msg);
				write(pipeA[1],buffer,strlen(buffer)+1);
				if(strcmp(buffer,"fin") == 0){
					printf("\n");
					return 1;
				}
				read(pipeB[0],ans,buffersize);
				printf("El hijo escribio: ");
				printf("%s\n",ans);
			}while(strcmp(ans,"fin")!=0);
			close(pipeA[1]);
			close(pipeB[0]);
			wait(status);
			break;
	}
	close(pipeA[0]);
	close(pipeA[1]);
	close(pipeB[0]);
	close(pipeB[1]);
	return (0);
}
