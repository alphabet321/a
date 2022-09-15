#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
    struct sockaddr_in server, client;
    int s, n;
    char b1[100], b2[100];
    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 3000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    n = sizeof(server);
    int r;
    double area;
    printf("Enter the radius : ");
    scanf("%d", &r);
    sendto(s, &r, sizeof(r), 0, (struct sockaddr *)&server, n);
    recvfrom(s, &area, sizeof(area), 0, NULL, NULL);
    printf("\n the area of circle is:  %f\n", area);
    close(s);
}
