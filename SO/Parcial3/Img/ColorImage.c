#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define READ  0
#define WRITE 1

int main(void)
{
    pid_t pid;
    //open two pipes, one for each direction
    int pipeA[2];
    int pipeB[2];
    int pipeC[2];
    int pipeD[2];

	char WriteMsg;
	char ReadMsg;
    /* create the pipe */
    if (pipe(pipeA) == -1 || pipe(pipeB) == -1 || pipe(pipeC) == -1 || pipe(pipeD) == -1) {
    	fprintf(stderr,"Pipe failed");
    	return 1;
    }

    int status = system("display 1.png");

  /* now fork a child process */

    for(int hijo = 0; hijo < 3 ; hijo++){
    	int pid = fork();
    	if(hijo == 0){
			switch(pid){
				case 0:
			  		WriteMsg = 'c';
    				printf("Soy el hijo %d\n",hijo);
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    printf("child: writeValue value : %c\n", WriteMsg);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork failed");
				    return 1;
			    break;

			  	default:
			  		WriteMsg = 'a';
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("Parent: reads value : %c\n", ReadMsg);
				    close(pipeB[READ]);
			    break;
			}
    	}

    	if(hijo == 1){
			switch(pid){
				case 0:
			  		WriteMsg = 'c';
    				printf("Soy el hijo %d\n",hijo);
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    printf("child: writeValue value : %c\n", WriteMsg);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork failed");
				    return 1;
			    break;

			  	default:
			  		WriteMsg = 'a';
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("Parent: reads value : %c\n", ReadMsg);
				    close(pipeB[READ]);
			    break;
			}
    	}

    	if(hijo == 2){
			switch(pid){
				case 0:
			  		WriteMsg = 'c';
    				printf("Soy el hijo %d\n",hijo);
				    close(pipeA[WRITE]);   //close write end, read, and then close read end
				    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("child: read value : %c\n", ReadMsg);
				    //WriteMsg+=ReadMsg;
				    close(pipeA[READ]);
				    close(pipeB[READ]);       //close read end, write and then close write end
				    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
				    printf("child: writeValue value : %c\n", WriteMsg);
				    close(pipeB[WRITE]);
				    exit(0);
			    break;

			  	case -1:
				    fprintf(stderr, "Fork failed");
				    return 1;
			    break;

			  	default:
			  		WriteMsg = 'a';
				    close(pipeA[READ]);      //close read end, write and then close write end
				    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
				    printf("Parent: writes char : %c\n", WriteMsg);
				    close(pipeA[WRITE]);
				    close(pipeB[WRITE]);        //close write end, read, and then close read end
				    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
				    printf("Parent: reads value : %c\n", ReadMsg);
				    close(pipeB[READ]);
			    break;
			}
    	}
    }

	for (int hijo = 0; hijo < 3; hijo++) {
	    int status;
	    pid_t pid = wait(&status);
	}
/*
  if (pid_A < 0) {
    fprintf(stderr, "Fork failed");
    return 1;
  }

  if (pid_A > 0) {  /* parent process *//*
    char WriteMsg = 'a';
    char ReadMsg;
    close(pipeA[READ]);      //close read end, write and then close write end
    write(pipeA[WRITE],&WriteMsg,sizeof(WriteMsg));    //write to pipe one
    printf("Parent: writes char : %c\n", WriteMsg);
    close(pipeA[WRITE]);
    close(pipeB[WRITE]);        //close write end, read, and then close read end
    read(pipeB[READ],&ReadMsg,sizeof(ReadMsg));
    printf("Parent: reads value : %c\n", ReadMsg);
    close(pipeB[READ]);
  }
  else { /* child process *//*
  	char WriteMsg = 'c';
  	char ReadMsg;
    close(pipeA[WRITE]);   //close write end, read, and then close read end
    read(pipeA[READ],&ReadMsg,sizeof(ReadMsg));
    printf("child: read value : %c\n", ReadMsg);
    //WriteMsg+=ReadMsg;
    close(pipeA[READ]);
    close(pipeB[READ]);       //close read end, write and then close write end
    write(pipeB[WRITE],&WriteMsg,sizeof(WriteMsg));
    printf("child: writeValue value : %c\n", WriteMsg);
    close(pipeB[WRITE]);

  }*/

  return 0;
}