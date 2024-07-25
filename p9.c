#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int arr[],int n)
{
	int i,j,minindex,temp;
	for(i=0;i<n-1;i++)
	{
		minindex=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minindex])
			{
				minindex=j;
			}
		}
		temp=arr[minindex];
		arr[minindex] = arr[i];
		arr[i] = temp;
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
	selectionsort(arr,n);
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
