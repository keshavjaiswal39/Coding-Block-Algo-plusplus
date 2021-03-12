#include<bits/stdc++.h>
using namespace std;

long long int partition(long long int *a,long long int s,long long int e)
{
	// inplace (cannot take extra array)
	long long int i=s-1;
	long long int j=s;
	long long int pivot=a[e];
	for(;j<=e-1;j++)
	{
		if(a[j]<=pivot)
		{
			// merge the smaller element in the region 1
			i=i+1;
			swap(a[i],a[j]);
		}
	}
	// place the pivot element in the correct index
	swap(a[i+1],a[e]);
	return i+1;
	
}

void quicksort(long long int *arr,long long int s,long long int e)
{
	if(s>=e)
	{
		return;
	}
	long long int p=partition(arr,s,e);
	// left part
	quicksort(arr,s,p-1);
	// right part
	quicksort(arr,p+1,e);
}

int main()
{
	long long int n;
	cin>>n;
	long long int a[1000000];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(long long int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0; 
}
