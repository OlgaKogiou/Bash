#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 

int main (int argc, char *argv []){
	int N=0;
	printf("Give me the value N:");
	scanf("%d", &N);
	#pragma omp parallel num_threads(N)
	{	
		#pragma omp critical
 			N++;
	}
	printf("Hello from main thread. The result is %d\n", N);
	return 0;
}
