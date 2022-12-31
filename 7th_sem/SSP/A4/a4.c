#include<stdio.h>
#include <stdlib.h>
#include <time.h>

enum { NS_PER_SECOND = 1000000000 };

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

void row_major_2d(int** arr, long n)
{
	for(long i = 0; i<n; ++i)
	{
		for(long j = 0; j<n; ++j)
		{
			arr[i][j] = arr[i][j]/2;
		}
	}
}

void row_major_3d(int*** arr, long n)
{
	for(long i = 0; i<n; ++i)
	{
		for(long j = 0; j<n; ++j)
		{
			for(long k = 0; k<n; ++k)
			{
				arr[i][j][k] = arr[i][j][k]/2;
			}
		}
	}
}

void column_major_2d(int** arr, long n)
{
	for(long i = 0; i<n; ++i)
	{
		for(long j = 0; j<n; ++j)
		{
			arr[j][i] = arr[j][i]/2;
		}
	}
}

void column_major_3d(int*** arr, long n)
{
	for(long i = 0; i<n; ++i)
	{
		for(long j = 0; j<n; ++j)
		{
			for(long k = 0; k<n; ++k)
			{
				arr[k][j][i] = arr[k][j][i]/2;
			}
		}
	}
}

void gen_random_2d(int** arr, long n)
{
	for(long i = 0; i<n; ++i)
		for(long j = 0; j<n; ++j)
			arr[i][j] = rand();
}

void gen_random_3d(int*** arr, long n)
{
	for(long i = 0; i<n; ++i)
		for(long j = 0; j<n; ++j)
			for(long k = 0; k<n; ++k)
				arr[i][j][k] = rand();
}

int main(int argc, char **argv)
{
	int sizes[] = {100, 500, 1000, 5000, 10000};
	struct timespec start, finish, delta;
	double time;
	for(int i = 4; i<5; ++i)
	{
		long n = sizes[i];
		int** arr1;
		int*** arr2;
		
		arr1 = (int **) malloc (n * sizeof(int *));
    		for (long j = 0; j < n; j++)
        		arr1[j] = (int *) malloc (n * sizeof(int));
        		
		
		gen_random_2d(arr1, n);
		
		clock_gettime(CLOCK_MONOTONIC, &start);
		row_major_2d(arr1, n);
		clock_gettime(CLOCK_MONOTONIC, &finish);
		sub_timespec(start, finish, &delta);
		printf("Row major; 2d ; n = %ld => %d.%.9lds\n", n, (int)delta.tv_sec, delta.tv_nsec); 
		
		clock_gettime(CLOCK_MONOTONIC, &start);
		column_major_2d(arr1, n);
		clock_gettime(CLOCK_MONOTONIC, &finish);
		sub_timespec(start, finish, &delta);
		printf("Column major; 2d ; n = %ld => %d.%.9lds\n", n, (int)delta.tv_sec, delta.tv_nsec); 
		
		for (long j = 0; j < n; j++)
			free(arr1[j]);
		free(arr1);

		if(i < 3)
		{
			arr2 = (int ***) malloc (n * sizeof(int **));
			for (long j = 0; j < n; j++)
			{
				arr2[j] = (int **) malloc (n * sizeof(int *));
				for(int k = 0; k<n; ++k)
					arr2[j][k] = (int *) malloc (n * sizeof(int));
			}

			gen_random_3d(arr2, n);

			clock_gettime(CLOCK_MONOTONIC, &start);
			row_major_3d(arr2, n);
			clock_gettime(CLOCK_MONOTONIC, &finish);
			sub_timespec(start, finish, &delta);
			printf("Row major; 3d ; n = %ld => %d.%.9lds\n", n, (int)delta.tv_sec, delta.tv_nsec); 

			clock_gettime(CLOCK_MONOTONIC, &start);
			column_major_3d(arr2, n);
			clock_gettime(CLOCK_MONOTONIC, &finish);
			sub_timespec(start, finish, &delta);
			printf("Column major; 3d ; n = %ld => %d.%.9lds\n", n, (int)delta.tv_sec, delta.tv_nsec); 
			
			
			for (long j = 0; j < n; j++)
			{
				for(int k = 0; k<n; ++k)
					free(arr2[j][k]);
				free(arr2[j]);
			}
			free(arr2);
		}
		
	}
	
	return 0;
	
}
