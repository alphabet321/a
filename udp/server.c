#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main()
{
    FILE *fp;
    struct sockaddr_in server, client;
    int s, n;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 3000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(s, (struct sockaddr *)&server, sizeof(server));
    n = sizeof(client);
    int r;
    // area of a circle
    recvfrom(s, &r, sizeof(r), 0, (struct sockaddr *)&client, &n);
    printf("\n the radius of circle is:  %d\n", r);
    double area;
    area = 22.0 * r * r / 7;

    sendto(s, &area, sizeof(area), 0, (struct sockaddr *)&client, n);
    printf("\n the area of circle is:  %f\n", area);

    close(s);
}
