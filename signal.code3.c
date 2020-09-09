#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
volatile sig_atomic_t counter = 1;
static void handler(int sig ) 
{ 	printf ("\nCaught signal: %s\n", strsignal(sig));
	counter++;
}
int main (int argc, char *argv []) { 
	struct sigaction act = { {0} }; 
	act . sa_handler = &handler;
	sigaction (SIGINT, &act, NULL);
	sigaction (SIGQUIT, &act, NULL);

	while (1) {
		printf ("sleep for secs ...\n");
		sleep(5) ;
	}

	return 0;

}
