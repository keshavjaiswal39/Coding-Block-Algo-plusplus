#include<stdio.h>
#include<stdlib.h>


void Insertion_Sort(int A[],int n)
{
	int i,j,x;
	for(i=0;i<n;i++)
	{
		j=i-1;
		x=A[i];
		while(A[j]>x && j>-1)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}


int main()
{
	int *A,n,i;
	printf("Insertion Sort\n\n");
	printf("Enter the number of elements you want to input: \n");
	scanf("%d",&n);
	A=(int *)malloc(n*sizeof(int));
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	Insertion_Sort(A,n);
	printf("The sorted array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
