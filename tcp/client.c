#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
  char *ip = "127.0.0.1";
  int port = 0034;
  int sock;
  struct sockaddr_in addr;
  socklen_t addr_size;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  printf("[+]TCP server socket created.\n");

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);

  connect(sock, (struct sockaddr *)&addr, sizeof(addr));
  printf("Connected to the server.\n");

  printf("**Program To Square a Number**\n");
  int num, sq;
  printf("The Number is : ");
  scanf("%d", &num);
  send(sock, &num, sizeof(num), 0);

  recv(sock, &sq, sizeof(sq), 0);
  printf("The square is : %d\n", sq);
  close(sock);
  printf("Disconnected from the server.\n");

  return 0;
  
}


