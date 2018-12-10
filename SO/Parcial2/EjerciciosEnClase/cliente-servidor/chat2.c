#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	//Creacion del fifo, la orden para terminarlo, los mensajes.
	int pipe2;
	char * fifo2 = "/tmp/fifo2";
	char msg[100], ans[100];
	mkfifo(fifo2, 0666);

	do{
		pipe2 = open(fifo2, O_WRONLY);
		printf("Escriba mensaje: ");
		fgets(ans, 100, stdin);
		write(pipe2, ans, strlen(ans)+1);
		close(pipe2);

		pipe2 = open(fifo2, O_RDONLY);
		read(pipe2, msg, sizeof(msg));
		if(strncmp("FIN", msg, 2) == 0){
			close(pipe2);
			printf("Se corto la comunicacion con el chat principal\n");
			exit(0);
		}
		printf("Mensaje recibido: '%s'\n", msg);
		close(pipe2);
	}while((strcmp(ans, "fin") != 0) || (strcmp(msg, "fin") != 0));

	return 0;
}