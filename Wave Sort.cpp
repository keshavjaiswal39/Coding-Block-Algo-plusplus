#include<bits/stdc++.h>
using namespace std;

void wave_Sort(int arr[],int n)
{
	for(int i=0;i<n;i+=2)
	{
		// Previous elemeent
		if(i!=0 and arr[i]<arr[i-1])
		{
			swap(arr[i],arr[i-1]);
		}
		
		// next element
		if(i!=(n-1) and arr[i]<arr[i+1])
		{
			swap(arr[i],arr[i+1]);
		}	
	}
}

int main()
{
	int a[]={1,3,4,2,7,8};
	int n=sizeof(a)/sizeof(int);
	wave_Sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
