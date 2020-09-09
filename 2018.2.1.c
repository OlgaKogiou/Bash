#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (int argc, char *argv []) 
{
	pid_t pid, pid2, pid3, pid4;
  
  	pid = fork();
  	if(pid == 0) 
  	{ 	
		execvp("ls", argv);
    		printf("execlp error\n");

  	}
	else{
		pid2=fork();
		if(pid2==0)
			printf("I'm the 2nd process and my id is %d, my parents id is %d\n", getpid(), getppid());
		else{
			pid2=wait(NULL);
			pid3=fork();
			if(pid3==0)
				printf("I'm the 3rd process and my id is %d, my parents id is %d\n", getpid(), getppid());
			else{
				pid4=fork();
				if(pid4==0)
  				{ 
					execlp("date","date", NULL); 
    					printf("execlp error\n") ;
				}
				else
					pid4=wait(NULL);
			}
		}		
	}	
 	return 0;

}
