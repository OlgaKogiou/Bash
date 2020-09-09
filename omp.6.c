#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 

int main (int argc, char *argv []){
	int n=2; //the number of rows
	int m=3; //the number of column
	int a[n][m];
	int mo;
	a[0][0]=1;
	a[0][1]=2;
	a[0][2]=3;
	a[1][0]=8;
	a[1][1]=12;
	a[1][2]=10;
	#pragma omp parallel num_threads(2)
	{	int i=0, result;
		int ID = omp_get_thread_num();
 		for(i=0;i<m;i++)
			result+=a[ID][i];
		#pragma omp critical
 			mo+=result;
	}
	printf("Hello from main thread. The result is %d\n", mo/3);
	return 0;
}
