#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(){
	int *status;
	pid_t ph1, ph2 = fork();
	ph1 = ph2;
	switch(ph1){
		case 0:
			sleep(2);
			printf("yo soy el proceso hijo 1: %d y mi padre es: %d\n",getpid(),getppid());
		break;

		case -1:
			printf("Error");
		break;

		default:
			printf("Proceso padre: %d\n",getpid());
			wait(status);
			break;
	}

        switch(ph2){
                case 0:
                        sleep(2);
                        printf("yo soy el hijo 2: %d y mi padre es: %d\n",getpid(),getppid());
                break;

                case -1:
                        printf("Error");
                break;

                default:
                        printf("Proceso padre: %d\n",getpid());
                        wait(status);
			break;
        }

return 0;
}
