#include<bits/stdc++.h>
using namespace std;

int partition(int *a,int s,int e)
{
	// inplace (cannot take extra array)
	int i=s-1;
	int j=s;
	int pivot=a[e];
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

void quicksort(int *arr,int s,int e)
{
	if(s>=e)
	{
		return;
	}
	int p=partition(arr,s,e);
	// left part
	quicksort(arr,s,p-1);
	// right part
	quicksort(arr,p+1,e);
}

int main()
{
	int n;
	cin>>n;
	int a[10005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0; 
}
