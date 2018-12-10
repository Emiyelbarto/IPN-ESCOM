#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

int main(){
	
	int *status;
	int i,j;

	for(i=0;i<2;i++){

		pid_t ph = fork();

		switch(ph){
			case 0:
				sleep(2);
				printf("\tSoy el hijo '%d' y mi padre es: '%d'\n",getpid(),getppid());
				exit(0);
				break;
			case -1:
				printf("Error al crear el hijo.\n");
				return -1;
				break;
			default:
				printf("El padre es: '%d'\n",getpid());
				break;
				wait(status);
		}

		if(i==0){
			//Hijo izquierdo
		}
		if(i==1){
			//Hijo derecho
		}

	}
	exit(0);
}