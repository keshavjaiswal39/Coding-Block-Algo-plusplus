#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[],int n)   // this is partially recursive
{
	if(n==1)
	{
		return;
	}
	for(int j=0;j<n-1;j++)
	{
		if(a[j]>a[j+1])
		{
			swap(a[j],a[j+1]);
		}
	}
	bubble_sort(a,n-1);
}

void bubble_sort_recursive(int a[],int j,int n)   // this is completely recursive
{
	if(n==1)
	{
		return;
	}
	if(j==n-1)
	{
		// single pass of the element is done
		return bubble_sort_recursive(a,0,n-1);
	}
	// rec case
	if(a[j]>a[j+1])
	{
		swap(a[j],a[j+1]);
	}
	bubble_sort_recursive(a,j+1,n);
	return;
}
 
int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	bubble_sort_recursive(arr,0,n);
 }
