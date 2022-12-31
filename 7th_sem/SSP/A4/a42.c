#include<stdio.h>
#include<stdlib.h>
#define ROW_MAJOR 1
#define COL_MAJOR 2

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
    int n = atoi(argv[1]);
    int mode = atoi(argv[2]); 
    int dim = atoi(argv[3]);

    int** arr1;
	int*** arr2;

    if(dim == 2)
    {
        arr1 = (int **) malloc (n * sizeof(int *));
        for (long j = 0; j < n; j++)
            arr1[j] = (int *) malloc (n * sizeof(int));
        
        gen_random_2d(arr1, n);

        if(mode == ROW_MAJOR)
        {
            row_major_2d(arr1, n);
        }
        else
        {
            column_major_2d(arr1, n);
        }

        for (long j = 0; j < n; j++)
			free(arr1[j]);
		free(arr1);
    }
    else if(dim == 3)
    {
        arr2 = (int ***) malloc (n * sizeof(int **));
        for (long j = 0; j < n; j++)
        {
            arr2[j] = (int **) malloc (n * sizeof(int *));
            for(int k = 0; k<n; ++k)
                arr2[j][k] = (int *) malloc (n * sizeof(int));
        }


        gen_random_3d(arr2, n);
        
        if(mode == ROW_MAJOR)
        {
            row_major_3d(arr2, n);
        }
        else
        {
            column_major_3d(arr2, n);
        }

        for (long j = 0; j < n; j++)
        {
            for(int k = 0; k<n; ++k)
                free(arr2[j][k]);
            free(arr2[j]);
        }
        free(arr2);
    } 
	
	return 0;
	
}
