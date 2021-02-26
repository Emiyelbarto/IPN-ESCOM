#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MENS_MAX_LEN 500

void usage()
{
  fprintf (stderr, "Wrong arguments. Must give two:\n");
  fprintf (stderr, "tcpclient SERVER PORT\n\n");
  fprintf (stderr, "For example:\n");
  fprintf (stderr, "  tcpclient totaki.com 80\n");
  exit(1);
}

void panic(char *msg)
{
  fprintf (stderr, "Fatal error: %s (errno %d, %s)\n", msg, errno, strerror(errno));
  exit(2);
}

int main(int argc, char *argv[])
{
  char *server;
  int port;
  int socketfd;
  int finish = 0;
  struct sockaddr_in serverAddress, clientAddress;
  struct hostent *h;
  char mens [MENS_MAX_LEN];
  size_t recvsize;

  if (argc<3)
    usage();

  server = argv[1];
  port = atoi(argv[2]);

  /* Create a TCP socket */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd==-1)
    panic("Failed to create socket");

  /* Sets client address */
  clientAddress.sin_family = AF_INET;
  clientAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  clientAddress.sin_port = htons(0);

  /* Bind the address to the socket */
  if (bind(socketfd, (struct sockaddr *)&clientAddress, sizeof(clientAddress))==-1)
    panic("Binding address");

  /* Get the hostname address */
  h = gethostbyname(server);

  /* Sets server address */
  serverAddress.sin_family = h->h_addrtype;
  memcpy((char*) &serverAddress.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  serverAddress.sin_port = htons(port);

  if (connect(socketfd, (struct sockaddr * )&serverAddress, sizeof(serverAddress))==-1)
    panic("Cannot connect");

  do
    {
      fgets(mens, MENS_MAX_LEN, stdin);

      if (send(socketfd, mens, strlen(mens)+1, 0)==-1)
    panic ("Cannot sent message");

    } while (!finish);      /* Never finish */

  return EXIT_SUCCESS;
}