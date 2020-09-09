#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
volatile sig_atomic_t counter = 5;
volatile sig_atomic_t pid=0;
static void handler(int sig ) 
{ 	printf ("\nReceived: %s\n", strsignal(sig));
	counter++;
	if(counter==0)
		kill(pid, SIGQUIT);
}
static void catcher(int sig ) 
{ 	printf ("\nReceived: %s\n", strsignal(sig));
	counter--;
	if(counter==0)
		kill(pid, SIGQUIT);
}
int main (int argc, char *argv []) { 
	struct sigaction act = { {0} }; 
	act . sa_handler = &handler;
	struct sigaction act2 = { {0} }; 
	act2 . sa_handler = &catcher;
	sigaction (SIGINT, &act, NULL);
	sigaction(SIGTSTP, &act2, NULL);
	signal(SIGINT, handler);
	signal(SIGTSTP, catcher);
	pid=getpid();
	while(1);;
	return 0;

}
