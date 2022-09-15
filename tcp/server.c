#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
  char *ip = "127.0.0.1";
  int port = 0034;

  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  printf("[+]TCP server socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  printf("[+]Bind to the port number: %d\n", port);

  listen(server_sock, 5);
  printf("Listening...\n");
  int num, sq;

  addr_size = sizeof(client_addr);
  client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
  printf("[+]Client connected.\n");

  printf("**Program To Square a Number**\n");
  recv(client_sock, &num, sizeof(num), 0);
  printf("The number is : %d\n", num);
  sq = num * num;
  send(client_sock, &sq, sizeof(sq), 0);
  printf("The sq is : %d\n", sq);

  close(client_sock);
  printf("[+]Client disconnected.\n\n");

  return 0;
}
