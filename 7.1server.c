#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define LSH_TOK_DELIM " \t\r\n\a"
#define SIZE 1024

int main(int argc, char *argv [])
{
int sock, i=0, position=0,j=0;
int result=0;
char msg[SIZE], c[1];
int integers[SIZE];
int characters[SIZE];
struct sockaddr_in addr; // Internet socket

addr.sin_family = AF_INET; // Internet socket
addr.sin_addr.s_addr = htonl(INADDR_ANY); // All interfaces
addr.sin_port = htons(6000);
sock = socket(AF_INET, SOCK_DGRAM, 0); // Datagram socket
bind(sock, (struct sockaddr*)&addr, sizeof(addr));

recvfrom(sock, msg, SIZE, 0, NULL, NULL);
fputs(msg, stdout);


for(i=0;i<strlen(msg); i++)
{
	if((msg[i]!='*')||(msg[i]!='-')||(msg[i]!='+')||(msg[i]!='/')){
		c[0]=msg[i];
		integers[position]=atoi(c);
		printf("int= %d\n", integers[position]);
	}
	else
		characters[j]=i;
	j++;
	position++;
}


characters[j]=-1;
j=0;
i=0;
position=0;
while((characters[j]!=-1)||(i+1!=strlen(msg)))
{
	if(msg[characters[j]]=='*')
		result=integers[i]*integers[i+1];
	if(msg[characters[j]]=='/')
		result=integers[i]/integers[i+1];
	if(msg[characters[j]]=='+')
		result=integers[i]+integers[i+1];
	if(msg[characters[j]]=='-')
		result=integers[i]-integers[i+1];
	result+=result;	
	i++;
	j++;
}	
printf("%d\n", result);
close(sock);

return 0;
}
