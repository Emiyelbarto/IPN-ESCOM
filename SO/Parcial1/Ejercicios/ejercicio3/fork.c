#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(){
	int *status;
	//PASO 1: Creación de procesos hijo
	pid_t ph = fork();
	switch(ph){
		case 0:
			//código del hijo
			sleep(2);
			printf("Soy el proceso hijo y mi id es: %d.\nY el de mi padres es: %d\n",getpid(),getppid());
		break;

		case -1:
			printf("error al crear el hijo proceso.\n");
			return -1;
		break;

		default:
			printf("Soy el proceso padre y mi id es: %d.\n",getpid());
			//código del proceso padre.
			wait(status);

		break;
	}

return 0;
}
