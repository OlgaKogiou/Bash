#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 
typedef struct data { 
	int x ; 
	int y ;  
} data_t; 

int *print_message(data_t *arg);


int main (int argc, char *argv [])
{
	int ret ;
	pthread_t thread;
	data_t d;
	int *result = malloc(sizeof(int));
	d.x = atoi(argv[1]);
	d.y = atoi(argv[2]);
	ret=pthread_create(&thread, NULL, (void * ( * ) (void *))print_message, &d);
	if ( ret != 0) {
		printf ("pthread_create() error\n");
		return 1;
	}
	pthread_join(thread, (void **) &result);
	printf("I'm the main thread and the result is %d\n", *result);
	free(result);
	
	return 0;
}

int *print_message(data_t *arg)
{
	int *y = malloc(sizeof(int));
	*y=arg->x + arg->y;
	return y;
} 
