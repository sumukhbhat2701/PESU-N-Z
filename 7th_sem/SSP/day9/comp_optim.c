#include<stdio.h>
#define vec_ptr double*
#define data_t double
#define IDENT 1.0
#define OP *
void f1(vec_ptr v, long n, data_t *dest)
{
    long length = n;
    long limit = length-1;
    data_t *d = v;
    data_t x = IDENT;
    long i;
    /* Combine 2 elements at a time */
    for (i = 0; i < limit; i+=2) {
    	x = (x OP d[i]) OP d[i+1];
    }
    /* Finish any remaining elements */
    for (; i < length; i++) {
    	x = x OP d[i];
    }
    *dest = x;
}

void f2(vec_ptr v, long n, data_t *dest)
{
    long length = n;
    long limit = length-1;
    data_t *d = v;
    data_t x = IDENT;
    long i;

    for (i = 0; i < length; i++) {
    	x = x OP d[i];
    }
    *dest = x;
}



int main()
{
	double arr[10000000];
	long n = 10000000;
	for(int i = 0; i<n; ++i)
		arr[i] = (double)(1/(i+1));
	double res;
	f2(arr, n, &res);
	printf("%lf\n", res);
	return 0; 
}
