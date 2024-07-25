#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*a,int*b)
{
	int temp = *a;
	*a =*b;
	*b= temp;
}
int partition(int arr[],int low,int high)
{
	int pivot =arr[high];
	int i = (low-1);
	for (int j=low ; j<=high-1;j++)
	{
		if(arr[j] <pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}

void quicksort(int arr[], int low , int high)
{
	if(low<high)
	{
		int pi =partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int generaterandomnumber()
{
	return rand() % 100;
} 

int main()
{
	int n=10;
	int *arr = (int*)malloc(n*sizeof(int));
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		arr[i] =generaterandomnumber();
		printf("%d\t",arr[i]);
	}
	printf("\n");
	clock_t start =clock();
	quicksort(arr,0,n-1 );
	clock_t end =clock();
	double time_taken =((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n time taken to sort for n= %d: %lf seconds\n",n,time_taken);
	printf("sorted number for n=%d:\n",n);
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
	free(arr);
	return 0;
}



