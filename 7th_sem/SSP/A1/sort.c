#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A,  long long int l,  long long int m,  long long int h){
     long long int n1 = m - l + 1;
     long long int n2 = h - m;
    int *Left = (int*)malloc(sizeof(int)*n1);
    int *Right = (int*)malloc(sizeof(int)*n2);
    for ( long long int i = 0; i < n1; i++)
        Left[i] = A[l + i];
    for ( long long int j = 0; j < n2; j++)
        Right[j] = A[m + 1 + j];
     long long int i = 0;
     long long int j = 0;
    // Initial index of merged subarray
     long long int k = l;
    while (i < n1 && j < n2) {
        //*count+=1;
        if (Left[i] <= Right[j]) {
            A[k] = Left[i];
            i++;
        }
        else {
            A[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = Right[j];
        j++;
        k++;
    }
}

void merge_sort(int *A,  long long int l,  long long int h){
    if(l<h){
         long long int m = (l+h)/2;
        merge_sort(A, l, m);
        merge_sort(A, m+1, h);
        merge(A, l ,m ,h);
    }
}

void genRandom( long long int n)
{
    time_t t1;
    FILE *f = fopen("file.txt", "w");

     long long int i = 0;
    srand ( (unsigned) time (&t1));
    while(i++ < n)
    {
        fprintf(f, "%d\n", rand());
    }

    fclose(f);
}

void print_array(int *A,  long long int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

 long long int partition(int *arr,  long long int low,  long long int high) 
{ 
    int pivot = *(arr+high);  
     long long int i = (low - 1);   
    
    for ( long long int j = low; j <= high - 1; j++) 
    { 
        if (*(arr+j) < pivot) 
        { 
            i++;   
            swap(arr+i ,arr+j); 
        } 
        
    } 
    
    swap(arr+i+1, arr+high);
    return i+1;
} 

void quick_sort(int *arr,  long long int low,  long long int high) 
{ 
    if (low < high) 
    { 
         long long int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
} 

void heapify(int *arr, long long int N, long long int i)
{
    long long int largest = i;
    long long int left = 2 * i + 1;
    long long int right = 2 * i + 2;
 
    if (left < N && arr[left] > arr[largest])
        largest = left;
 
    if (right < N && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heap_sort(int arr[], long long int N)
{
     for (long long int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    for (long long int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void runSuite( long long int n, int j)
{
    genRandom(n);

    FILE* f = fopen("file.txt", "r");

    int *arr = (int*)malloc(sizeof(int)*n);
    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }

    switch(j)
    {
    	case 1:
    		merge_sort(arr, 0, n-1);
    		break;
    	case 2:
    		quick_sort(arr, 0, n-1);
    		break;
    	case 3:
    		heap_sort(arr, n);
    		break;
    	default:
    		return;
    		
    };
    free(arr);
    printf("Done for:%lld : %d\n", n, j);
    // print_array(arr, n);
    fclose(f);
}

int main(int argc, char** argv)
{

    if(argc != 3)
        return 0;
     long long int n = atoll(argv[1]);
    int sort = atoi(argv[2]);

    runSuite(n, sort);

    // printf("Done\n");
    return 0;
}
