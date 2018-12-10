#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
	//Creamos 3 pipes, una para cada cliente
	int pipe1, pipe2, pipe3, i, j;
	//Estado para no tener problema con los hijos
	int *status;
	//Creamos el pid
	pid_t pid;
	//Paths para los fifos
	char * fifo1 = "/tmp/fifo1";
	char * fifo2 = "/tmp/fifo2";
	char * fifo3 = "/tmp/fifo3";
	//Se crea la orden con la que se cerrara el pipe
    char * fin = "fin\n";
	char pidnum[5];
	//Creamos el mensaje y la respuesta
	char msg[100], ans[100];

	//Crear FIFOS con nombre
	mkfifo(fifo1,0666);
	mkfifo(fifo2,0666);
	mkfifo(fifo3,0666);
	//Creamos los hijos
	for(i = 0; i < 3; i ++)
	{
		//Hacemos el FORK!!!!!!!!!!!!!!!!!!
		pid = fork();
		//Hacemos el caso para cada hijo
		switch(pid)
		{
			//Caso de switch erroneo
			case -1:
				printf("Error al hacer el fork\n");
				return -1;
				break;

			case 0:
				//CASO  DE LOS HIJOS
				printf("Soy el hijo %d con el padre %d con pid %d\n",i,getppid(),getpid() );
				if(i == 0)
				{
					do{
						//Se abre el primer fifo de lectura y se lee su contenido para despues imprimirlo y cerrarlo
						pipe1 = open(fifo1,O_RDONLY);
						read(pipe1,msg,80);
						printf("Soy el cliente 1 y envié: %s\n",msg);
						close(pipe1);
						//Se abre de nuevo el fifo para escribir 
						pipe1 = open(fifo1, O_WRONLY);
						if(strcmp(msg,fin)==0)
						{
							strcmp(ans,fin);
						}
						else
						{
							strcpy(ans,"Soy una respuesta del servidor al cliente1, mi PID es:");
							sprintf(pidnum,"%d\n",getpid());
							strcat(ans,pidnum);
						}
						write(pipe1,ans,strlen(ans)+2);
						close(pipe1);
					}while((strcmp(msg, fin) != 0) || (strcmp(ans, fin) != 0));
					printf("Termino la coneccion con el hijo3\n");
				}
				else if (i == 1)
				{
					do{
						//Se abre el primer fifo de lectura y se lee su contenido para despues imprimirlo y cerrarlo
						pipe2 = open(fifo2,O_RDONLY);
						read(pipe2,msg,80);
						printf("Soy el cliente 2 y envié: %s\n",msg);
						close(pipe2);
						//Se abre de nuevo el fifo para escribir 
						pipe2 = open(fifo2, O_WRONLY);
						if(strcmp(msg,fin)==0)
						{
							strcmp(ans,fin);
						}
						else
						{
							strcpy(ans,"Soy una respuesta del servidor al cliente2, mi PID es:");
							sprintf(pidnum,"%d\n",getpid());
							strcat(ans,pidnum);
						}
						write(pipe2,ans,strlen(ans)+2);
						close(pipe2);
					}while((strcmp(msg, fin) != 0) || (strcmp(ans, fin) != 0));
					printf("Termino la coneccion con el hijo 2\n");
				}
				else if (i == 2)
				{
					do{
						//Se abre el tercer fifo de lectura y se lee su contenido para despues imprimirlo y cerrarlo
						pipe3 = open(fifo3,O_RDONLY);
						read(pipe3,msg,80);
						printf("Soy el cliente 3 y envié: %s\n",msg);
						close(pipe3);
						//Se abre de nuevo el fifo para escribir 
						pipe3 = open(fifo3, O_WRONLY);
						if(strcmp(msg,fin)==0)
						{
							strcmp(ans,fin);
						}
						else
						{
							strcpy(ans,"Soy una respuesta del servidor al cliente1, mi PID es:");
							sprintf(pidnum,"%d\n",getpid());
							strcat(ans,pidnum);
						}
						write(pipe3,ans,strlen(ans)+2);
						close(pipe3);
					}while((strcmp(msg, fin) != 0) || (strcmp(ans, fin) != 0));
					printf("Termino la coneccion con el hijo 3\n");
				}
				exit(0);
				break;

			default:
				if(i == 2)
				{
					for(j = 0 ; j < 3 ; j ++)
					{
						wait(status);
					}
					exit(0);
				}
				break;
		}
	}
	return 0;
}