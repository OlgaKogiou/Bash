#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

int main(int argc, char *argv [])
{
int sock, i ;
char msg[SIZE];
struct sockaddr_in addr; // Internet socket

addr.sin_family = AF_INET; // Internet socket
inet_aton(argv[1], &addr.sin_addr);
addr.sin_port = htons(6000);
sock = socket(AF_INET, SOCK_DGRAM, 0); // Datagram socket

strcpy(msg, ””) ;
for ( i = 3; i < argc; i++) {
strcat (msg, argv[i ]) ;
strcat (msg, ” ”) ;
}
msg[strlen(msg)−1] = ’\0’; // Remove the last space

printf (”sending command : %s\n”, msg);

sendto(sock, msg, strlen (msg) + 1, 0,( struct sockaddr *)&addr, sizeof(addr));

close(sock);

return 0;
}
