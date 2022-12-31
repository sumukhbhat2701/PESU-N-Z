#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 10
/* compile using cc threads.c -lpthread */
void *PrintHello(void *threadid)
{
	int time = 20*60;
	int p = getpid();
	printf("Thread# %d, PID = %d\n", *(int *)threadid, p);
	sleep(time);
   printf("\n%d: Hello World! Threadid %d\n", *(int *)threadid, pthread_self());
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int p = getpid();
   printf("Main PID = %d\n", p);
   int rc, t;
   int thread_id[NUM_THREADS];
   for (t=0; t < NUM_THREADS; t++) {
      printf("Creating thread %d\n", t);
      thread_id[t] = t;
      rc = pthread_create( &threads[t], NULL, PrintHello,(void *)&thread_id[t]);
      if (rc) {
         printf("ERROR return code from pthread_create(): %d\n", rc);
         exit(-1);
      }
   } 
   pthread_exit(NULL); 
}


