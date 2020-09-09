#include<ctype.h> 
#include<sys/types.h> 
#include<sys/socket.h>
#include<sys/wait.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include<netinet/in.h> 
#include<signal.h> 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
volatile sig_atomic_t pd; 
volatile sig_atomic_t pd2;
volatile sig_atomic_t c=0;
static void catcher(int sig) 
{	if(c%2==0) 	
		printf ("I can continue now\n");
	//kill(pd, SIGCONT);
}
int main (int argc, char *argv []) { 
	struct sigaction act2 = { {0} };
	pid_t pid;
	act2.sa_handler = &catcher;
	sigaction (SIGCONT, &act2, NULL);
	signal(SIGCONT, catcher);
	pid=fork();
	if(pid==0){
		while (1) {
			pd=getpid();
			pd2=getppid();
			printf ("Luke I'm your father\n");
			sleep(2);
			printf("I'm getting paused\n");
			kill(pd2, SIGCONT);
			pause();
			c++;
		}
	}
	else{
		while(1){
			pause();
			sleep(1);				
			kill(pd, SIGCONT);
			c++;
		}
	}
	return 0;

}
