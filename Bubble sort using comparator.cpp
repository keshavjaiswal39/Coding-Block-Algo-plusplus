#include<iostream>
using namespace std;

bool compare(int a,int b)
{
	return a>b;
}

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

void Bubble_sort(int a[],int n,bool (&cmp)(int a,int b))
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(cmp(a[j],a[j+1]))
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

int main()
{
	int a[1000];
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	Bubble_sort(a,n,compare);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
