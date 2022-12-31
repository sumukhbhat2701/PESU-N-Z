#include<stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) 
{ 
    int pivot = *(arr+high);  
    int i = (low - 1);   
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (*(arr+j) < pivot) 
        { 
            i++; 
            swap(&(*(arr+i)),&(*(arr+j))); 
        } 
    } 
    swap(&(*(arr+(i+1))), &(*(arr+high))); 
    return i+1;
} 

void QuickSort(int *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1); 
        QuickSort(arr, pi + 1, high); 
    } 
} 


void genRandom(int n)
{
    FILE *f = fopen("file.txt", "w");

    int i = 0;
    while(i++ < 10000)
    {
        fprintf(f, "%d", rand() % 10);
    }

    fclose(f);
}

int main()
{
    genRandom(10000);

    FILE* f = fopen("file.txt", "r");
    int n = 10000;

    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }

    QuickSort(arr, 0, n-1);

    fclose(f);
    return 0;
}
