#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	//Creacion del fifo, la orden para terminarlo, los mensajes.
	int pipe1;
	char * fifo1 = "/tmp/fifo1";
	char msg[100], ans[100];
	mkfifo(fifo1, 0666);

	do{

		pipe1 = open(fifo1, O_WRONLY);
		printf("Escriba mensaje: ");
		fgets(ans, 100, stdin);
		write(pipe1, ans, strlen(ans)+1);
		close(pipe1);

		pipe1 = open(fifo1, O_RDONLY);
		read(pipe1, msg, sizeof(msg));
		if(strncmp("FIN", msg, 2) == 0){
			close(pipe1);
			printf("Se corto la comunicacion con el chat principal\n");
			exit(0);
		}
		printf("Mensaje recibido: '%s'\n", msg);
		close(pipe1);
	}while((strcmp(ans, "fin\n") != 0) || (strcmp(msg, "fin") != 0) || (strcmp(ans, "FIN\n") != 0) || (strcmp(msg, "FIN") != 0));

	return 0;
}