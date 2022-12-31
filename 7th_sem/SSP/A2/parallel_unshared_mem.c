#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_RECT 10000000
int NUMTHREADS;
//#define NUMTHREADS 4

typedef struct 
{
	int tid;
	double *sum;
} param_t;

void *Area(void *pArg){
           param_t myArg = *((param_t *)pArg);
           int myNum = myArg.tid;
           double h = 2.0 / NUM_RECT;
           double x, partialSum = 0.0;  // local to each thread

           // use every NUMTHREADS-th ste
           for (int i = myNum; i < NUM_RECT; i += NUMTHREADS){
       		x = -1 + (i + 0.5f) * h;
                partialSum += sqrt(1.0 - x*x) * h;
           }

           *(myArg.sum) = partialSum;  // add partial to global final answer
           return 0;
}



int main(int argc, char **argv) {
	NUMTHREADS = atoi(argv[1]);
	pthread_t tHandles[NUMTHREADS]; int i;
	double sums[NUMTHREADS];
	param_t params[NUMTHREADS];
	struct timespec start, finish;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for ( i = 0; i < NUMTHREADS; ++i ) {
		params[i].tid = i;
		params[i].sum = &sums[i];
		pthread_create(&tHandles[i],           // Returned thread handle
                       NULL,                 // Thread Attributes
                       Area,                   // Thread function
                       (void*)&params[i]);        // Data for Area()
	}
	
	for ( i = 0; i < NUMTHREADS; ++i ) {
   		pthread_join(tHandles[i], NULL);
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	double time = (((double)finish.tv_nsec)/1000000) - (((double)start.tv_nsec)/1000000);
	printf("Time taken to execute the parallel portion = %lf ms\n", time);
	double gPi = 0.0;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for(i = 0; i < NUMTHREADS; i++)
	{
		gPi += sums[i];
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	time = (((double)finish.tv_nsec)/1000000) - (((double)start.tv_nsec)/1000000);
	printf("Time taken to execute the serial portion = %lf ms\n", time);
	gPi *= 2.0;
	printf("Computed value of Pi:  %12.9f\n", gPi );
	return 0;
}

