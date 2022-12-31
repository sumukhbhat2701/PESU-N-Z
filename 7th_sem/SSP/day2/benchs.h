#ifndef _BENCHS_H
 #define _BENCHS_H
 
 #include <time.h>
 #include<pthread.h>
//  #include "sys/param.h"
//  #include "sys/ports.h"
 
 struct bench
 {
   unsigned short b_start;
 
   unsigned short b_stop;
 
   unsigned short b_correction;
 
   unsigned short b_delta;
 };
 typedef struct bench bench_t;
 
 extern pthread_mutex_t lock;

 extern void
 bench_init (bench_t *b);
 
 extern void bench_start (bench_t *b);
 
 extern void
 bench_start (bench_t *b);
 
 extern void
 bench_stop (bench_t *b);
 
 extern void
 bench_stop (bench_t *b);
 
 extern void
 bench_report (bench_t *b, const char *msg, ...);
 

 extern void 
 bench_end();
 
 extern void
 bench_empty (bench_t *b);
 
 #endif

