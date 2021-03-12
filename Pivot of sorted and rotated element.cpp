#include<iostream>
using namespace std;

int findIndexPivot(int a[],int n)
{
	int s=0;
	int e=n-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(a[mid]>=a[mid+1] and a[mid]>=a[mid-1])
		{
			return mid;
		}
		if(a[mid]<a[e])
		{
			e=mid-1;
		}
		if(a[mid]>a[e])
		{
			s=mid+1;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;
	int a[1000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<findIndexPivot(a,n);
}
