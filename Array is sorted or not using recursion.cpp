#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n)
{
	if(n==0 || n==1)
	{
		return true;
	}
	if(arr[0]<arr[1] && isSorted(arr+1,n-1))
	{
		return true;
	}
	return false;
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
	if(isSorted(arr,n))
	{
		cout<<"The array is Sorted";
	}
	else
	{
		cout<<"The array is not Sorted";
	}
}
