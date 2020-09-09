#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main (int argc, char *argv [])
{
	int count;

	count = 3;
	while (count > 0) {
		printf("exit in %d sec(s)\n", count);
		sleep(1) ;
		count--;
	}

	printf("message before kill()\n") ;
	kill(getpid(), SIGINT);
	printf("message after kill ()\n") ; //den ektypvnetai pote

	return 0;
}
