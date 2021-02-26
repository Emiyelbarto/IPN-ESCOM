#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

struct sockaddr_in serv; //This is our main socket variable.
int fd;                  //This is the socket file descriptor that will be used to identify the socket
int conn;                //This is the connection file descriptor that will be used to distinguish client connections.
char message[100] = "";  //This array will store the messages that are sent by the server

int main(int argc, char const *argv[])
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8096);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);  //This binds the client to localhost
connect(fd, (struct sockaddr *)&serv, sizeof(serv))); //This connects the client to the server.
while (1)
{
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    send(fd, message, strlen(message), 0);
    //An extra breaking condition can be added here (to terminate the while loop)
}
}
