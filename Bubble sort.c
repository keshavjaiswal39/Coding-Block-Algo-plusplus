#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void Bubble_Sort(int A[],int n)
{
	int i,j,flag;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}


int main()
{
	int *A,n,i;
	printf("Bubble Sort\n\n");
	printf("Enter the number of elements you want to input: \n");
	scanf("%d",&n);
	A=(int *)malloc(n*sizeof(int));
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	Bubble_Sort(A,n);
	printf("The sorted array: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
