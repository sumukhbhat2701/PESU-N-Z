#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS     5
/* compile using cc threads.c -lpthread */
void *PrintHello(void *threadid)
{
   printf("\n%d: Hello World! Threadid %d\n", *(int *)threadid, pthread_self());
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
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


