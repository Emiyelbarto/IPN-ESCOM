#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	//Creacion del fifo, la orden para terminarlo, los mensajes.
	int pipe3;
	char * fifo3 = "/tmp/fifo3";
	char msg[100], ans[100];
	mkfifo(fifo3, 0666);

	do{

		pipe3 = open(fifo3, O_WRONLY);
		printf("Escriba mensaje: ");
		fgets(ans, 100, stdin);
		write(pipe3, ans, strlen(ans)+1);
		close(pipe3);

		pipe3 = open(fifo3, O_RDONLY);
		read(pipe3, msg, sizeof(msg));
		if(strncmp("FIN", msg, 2) == 0){
			close(pipe3);
			printf("Se corto la comunicacion con el chat principal\n");
			exit(0);
		}
		printf("Mensaje recibido: '%s'\n", msg);
		close(pipe3);
	}while((strcmp(ans, "fin") != 0) || (strcmp(msg, "fin") != 0));

	return 0;
}