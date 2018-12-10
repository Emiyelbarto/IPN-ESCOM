#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

int main(){
	int i, nivel, *status,lvl;
	printf("Escribir cuantas lineas habra en el programa.\n");
	scanf("%d",&nivel);
	int orig=nivel;
	lvl=2;
	do{

		for(i=0;i<2;i++){

			pid_t ph=fork();

			if(i == 0){

					switch(ph){
				
						case 0:
							sleep(2);
							if(nivel==orig)printf("\tSoy el proceso hijo %d: %d y mi padre es: %d\n",(i+1),getpid(),getppid());
				
							int j;
			    			int *status1;
				
						        for(j=0;j<3;j++){

			        				pid_t ph1=fork();
			    
			                			switch(ph1){
			                        			case 0:
			                                			sleep(2);
		                                				printf("\t\tSoy el proceso hijo izquierdo '%d' de nivel '%d' y mi padre es: %d\n",getpid(),lvl,getppid());
			                               				exit(0);
			                                			break;
			                        			
			                        			case -1:
			                                			printf("Error al crear el hijo.\n");
			                                			return -1;
			                                			break;
			                        			
			                        			default:
			                                			//printf("\tEl padre es :%d\n",getpid());
			                                			if(j==2)wait(status1);
			                		}

			        			}

			                exit(0);
							break;

						case -1:
							printf("Error al crear el hijo.\n");
							return -1;
							break;

						default:
							if(nivel==orig)printf("El padre es :%d\n",getpid());
							wait(status);
					}

			}
			
			else if(i == 1){
			
				switch(ph){
			
					case 0:
						sleep(2);
						if(nivel==orig)printf("\tSoy el proceso hijo %d: %d y mi padre es: %d\n",(i+1),getpid(),getppid());
			
						int j;
		    			int *status2;
			
					        for(j=0;j<4;j++){

		        				pid_t ph2=fork();
		    
		                			switch(ph2){
		                        			case 0:
		                                			sleep(3);
		                                			printf("\t\tSoy el proceso hijo derecho '%d' de nivel '%d' y mi padre es: %d\n",getpid(),lvl,getppid());
		                               				exit(0);
		                                			break;
		                        			
		                        			case -1:
		                                			printf("Error al crear el hijo.\n");
		                                			return -1;
		                                			break;
		                        			
		                        			default:
		                                			//printf("\tEl padre es :%d\n",getpid());
		                                			if(j==3)wait(status2);
		                		}

		        			}

		                exit(0);
						break;

					case -1:
						printf("Error al crear el hijo.\n");
						return -1;
						break;

					default:
						//if(nivel==orig)printf("El padre es :%d\n",getpid());
						wait(status);
				}

			}

		}
		lvl++;
		nivel--;

		}while(nivel!=0);

		exit(0);

}