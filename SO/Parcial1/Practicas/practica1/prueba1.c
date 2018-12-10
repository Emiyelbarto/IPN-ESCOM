#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>


int main(){
	int i, sel, *status;
	printf("Escribir cuantas lineas habra en el programa.\n");
	scanf("%d",&sel);
	int orig=sel;

		for(i=0;i<2;i++){

			pid_t ph=fork();

			if(i == 0){
			
				switch(ph){
			
					case 0:
						sleep(2);
						printf("\tSoy el proceso hijo %d: %d y mi padre es: %d\n",(i+1),getpid(),getppid());
			
						int j;
		    			int *status1;
			
					        for(j=0;j<3;j++){

		        				pid_t ph1=fork();
		    
		                			switch(ph1){
		                        			case 0:
		                                			sleep(2);
		                                			printf("\t\tSoy el proceso hijo '%d' y mi padre es: %d\n",getpid(),getppid());
		                               				exit(0);
		                                			break;
		                        			
		                        			case -1:
		                                			printf("Error al crear el hijo.\n");
		                                			return -1;
		                                			break;
		                        			
		                        			default:
		                                			//printf("\tEl padre es :%d\n",getpid());
		                                			wait(status1);
		                		}

		        			}

		                exit(0);
						break;

					case -1:
						printf("Error al crear el hijo.\n");
						return -1;
						break;

					default:
						printf("El padre es :%d\n",getpid());
						wait(status);
				}

			}
			
			else if(i == 1){
			
				switch(ph){
			
					case 0:
						sleep(2);
						printf("\tSoy el proceso hijo %d: %d y mi padre es: %d\n",(i+1),getpid(),getppid());
			
						int j;
		    			int *status2;
			
					        for(j=0;j<4;j++){

		        				pid_t ph2=fork();
		    
		                			switch(ph2){
		                        			case 0:
		                                			sleep(3);
		                                			printf("\t\tSoy el proceso hijo '%d' y mi padre es: %d\n",getpid(),getppid());
		                               				exit(0);
		                                			break;
		                        			
		                        			case -1:
		                                			printf("Error al crear el hijo.\n");
		                                			return -1;
		                                			break;
		                        			
		                        			default:
		                                			//printf("\tEl padre es :%d\n",getpid());
		                                			wait(status2);
		                		}

		        			}

		                exit(0);
						break;

					case -1:
						printf("Error al crear el hijo.\n");
						return -1;
						break;

					default:
						if(sel==orig)printf("El padre es :%d\n",getpid());
						wait(status);
				}

			}

		}

}
