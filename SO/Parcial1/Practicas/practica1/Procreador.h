#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>

void Procreacion(int level,int lv,int NumHijos);
void Nivel0(int level,int lv);


void Nivel0(int level, int lv)//Crea primeros dos hijos
{
	if(level==0)
	{
		printf("\nNivel: %d\n",lv);
		printf("\nSoy el padre con el PID: %d\n",getpid());
		exit(0);
	}
	for(int i=0;i<2;i++)
	{
		int *status;
		int NumH;
		pid_t hijo=fork();
	        switch(hijo)
	        {
        	        case -1:
                	        printf("\nERROR\n");
	                        break;
        	        case 0:
				printf("\nNivel: %d\n",lv+1);
                	        printf("\nSoy el hijo con el PID: %d y",getpid());
                        	printf(" mi padre es %d\n\n",getppid());
	                        sleep(2);
				if(level<2)
		                        exit(0);
				else
				{
					if(i==0)
						Procreacion(level-1,lv+1,3);
					else
					{
						Procreacion(level-1,lv+1,4);
					}
				}
				//wait(status);
				sleep(2);
				break;
        	        default:
				printf("\nNivel: %d\n",lv);
	                        printf("\nSoy el padre con el PID: %d\n",getpid());
	                        
						if(i==1)
						{
							for(int x=0;x<(lv+1);x++)
								wait(status);
						}
						sleep(2);
	                        break;
	        }
	}
	exit(0);
}

void Procreacion(int level, int lv,int NumHijos)//Crea arboles simetricos
{
	for(int i=0;i<NumHijos;i++)
	{
		int *status;
		int NumH;
		pid_t hijo=fork();
	        switch(hijo)
	        {
        	        case -1:
                	        printf("\nERROR\n");
	                        break;
        	        case 0:
				printf("\nNivel: %d\n",lv+1);
                	        printf("\nSoy el hijo con el PID: %d y",getpid());
                        	printf(" mi padre es %d\n\n",getppid());
	                        sleep(2);
				if(level<2)
		                        exit(0);
				else
					Procreacion(level-1,lv+1,NumHijos);
				//sleep(2);
				//wait(status);
				break;
        	        default:
				printf("\nNivel: %d\n",lv);
	                        printf("\nSoy el padre con el PID: %d\n",getpid());
	                        
	                        if(i==(NumHijos-1))
						{
							for(int x=0;x<(lv+1);x++)
								wait(status);
						}
						//sleep(2);
	                        break;
	        }
	}
	exit(0);
}
