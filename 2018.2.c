#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
volatile sig_atomic_t counter = 5;
volatile sig_atomic_t pid=0;
static void handler(int sig ) 
{	char ans; 	
	printf ("\nReceived: %s\n", strsignal(sig));
	counter--;
	if(counter==0){
		printf("Exit (y/n)?\n");
		scanf("%c", &ans);
		if(ans=='y')
			kill(pid, SIGQUIT);
	}
}

int main (int argc, char *argv []) { 
	struct sigaction act = { {0} }; 
	act . sa_handler = &handler;
	sigaction (SIGINT, &act, NULL);
	signal(SIGINT, handler);
	pid=getpid();
	while(1);;
	return 0;

}
