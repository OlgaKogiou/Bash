#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 
int n=2; //the number of rows
int m=3; //the number of column 
typedef struct data{ 
	int a[2][3]; //the table
	int row;
} data_t;
int *print_message(data_t *arg);
pthread_mutex_t lock;
int mo=0;
int main (int argc, char *argv [])
{	pthread_t thread;
	int ret, i=0, j=0;
	data_t d;
	int *result = malloc(sizeof(int)*n);
	if (pthread_mutex_init(&lock, NULL) < 0){
        	perror("Error on initializing mutex");
        	exit(1);
    	}
	d.a[0][0]=1;
	d.a[0][1]=2;
	d.a[0][2]=3;
	d.a[1][0]=8;
	d.a[1][1]=12;
	d.a[1][2]=10;
	for(i=0;i<n; i++)
	{	d.row=i;
		ret=pthread_create(&thread, NULL, (void * ( * ) (void *))print_message, &d);
		if ( ret != 0) {
			printf ("pthread_create() error\n");
			return 1;
		}
		pthread_join(thread, (void **) &result);
	}
	printf("I'm the main thread and the result is %d\n", mo/n);
	free(result);
	
	return 0;
}

int *print_message(data_t *arg)
{
	int *y = malloc(sizeof(int));
	int sum=0, i=0, j=0;
	printf("row:%d\n", arg->row);
	for(j=0;j<m;j++)
	{	printf("%d\n", arg->a[arg->row][j]);
		sum+=arg->a[arg->row][j];

	}
	
		
	*y=sum/m;
	printf("The result is %d\n", *y);
	pthread_mutex_lock(&lock);
        	mo+=*y;
        pthread_mutex_unlock(&lock);
	return y;
} 
