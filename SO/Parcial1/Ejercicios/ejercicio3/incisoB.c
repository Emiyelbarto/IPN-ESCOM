#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(){
	int *status;
	pid_t ph = fork();
	pid_t ph2;
	switch(ph){
		case 0:
			sleep(3);
			printf("\nSoy el proceso hijo %d y mi padres es: %d\n",getpid(),getppid());
			ph2 = fork();
		        switch(ph){
		                case 0:
                       			printf("\nSoy el proceso hijo %d y mi padres es: %d\n",getpid(),getppid());
                       			ph2 = fork();
                       		break;

		        	case -1:
        	                	printf("\nError al hacer fork.\n");
				break;

				default:
					wait(status);
     					printf("\nSoy el proceso padre y mi id es: %d\n",getpid());
      				break;
			}

                break;

		case -1:
			printf("\nError al hacer fork.\n");
                break;

                default:
			wait(status);
			printf("\nSoy el proceso padre y mi id es: %d\n",getpid());
                break;
	}

return 0;
}
