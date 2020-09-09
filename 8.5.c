#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
void *print_message(void *arg);
pthread_mutex_t lock;
int N;
int main (int argc, char *argv [])
{
	int x=0 , ret, i=0;
	pthread_t thread;
	if (pthread_mutex_init(&lock, NULL) != 0) 
    	{ 
        	printf("\n mutex init has failed\n"); 
        	return 1; 
    	} 
  

	printf("Give me the N value:");
	scanf("%d", &N);
	while(i<N){
		ret=pthread_create(&thread, NULL, print_message, (void*)&i);
		if ( ret != 0) {
			printf ("pthread_create() error\n");
			return 1;
		}
		pthread_join(thread, NULL);
		i++;
	}
	
	pthread_mutex_destroy(&lock);
	return 0;
}
void *print_message(void *arg)
{
	int *dat;
	dat = (int *)arg;
	pthread_mutex_lock(&lock);
        	N++;
        pthread_mutex_unlock(&lock);
	return 0;
}
