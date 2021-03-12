#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void Selection_Sort(int A[],int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=k=i;j<n;j++)
		{
			if(A[j]<A[k])
			{
				k=j;
			}
			swap(&A[i],&A[k]);
		}
	}
}


int main()
{
	int *A,n,i;
	printf("Selection Sort\n\n");
	printf("Enter the number of elements you want to input: \n");
	scanf("%d",&n);
	A=(int *)malloc(n*sizeof(int));
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	Selection_Sort(A,n);
	printf("The sorted array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
