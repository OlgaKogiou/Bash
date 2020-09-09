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

int main (int argc, char *argv []) { 
	struct sigaction act2 = { {0} };
	pid_t pid;
	int signum=0;
	sigset_t s1,s2;
	sigemptyset(&s1); //αρχικοποιηση κενου συνολου
    	sigemptyset(&s2);
    	sigaddset(&s1, SIGUSR1); //προσθηκη σηματος
    	sigaddset(&s2, SIGUSR2);
    	sigprocmask(SIG_BLOCK,&s1,NULL); // μπλοκάρισμα των σημάτων του set
    	sigprocmask(SIG_BLOCK,&s2,NULL);

	pid=fork();
	if(pid==0){
		while (1) {
			sigwait(&s2, &signum);
			pd=getpid();
			pd2=getppid();
			printf ("Luke I'm your father\n");
			sleep(2);
			printf("I'm getting paused\n");
			kill(pd2, SIGUSR1);
			printf("I'm waking up\n");
		}
	}
	while(1){
		kill(pd, SIGUSR2);
		sigwait(&s1, &signum);					
	}
	
	return 0;

}
