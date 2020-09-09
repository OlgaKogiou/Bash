#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv []) 
{ 	pid_t pid, pid2;
  	pid = fork();
	if(pid == 0) 
  	{ 	printf("I am 1st processes, my id is %d, and my parent's id is %d\n", getpid(), getppid());
		execvp("ls", argv);
    		printf("execlp error\n");
    		exit(1) ;
	}
  	else
	{	waitpid(-1, NULL, 0);
		pid2=fork();
		if(pid2==0)
		{
			printf("I am 2nd processes, my id is %d, and my parent's id is %d\n", getpid(), getppid());
			execlp("cd", "cd", "-", (char *)NULL);
    			printf("execlp error\n");
    			exit(1) ;
		}
		else waitpid(-1, NULL, 0);
	}
  	return 0;

}
