#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr = (int*)malloc(5*sizeof(int));
	
	int n = sizeof(arr)/sizeof(int);
	printf("%d\n", n);
	return 0;
}
