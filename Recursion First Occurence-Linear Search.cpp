#include<bits/stdc++.h>
using namespace std;


int firstOcc(int *a,int n,int key)
{
	if(n==0)
	{
		return -1;
	}
	if(a[0]==key)
	{
		return 0;
	}
	int index=firstOcc(a+1,n-1,key);
	if(index==-1)
	{
		return -1;
	}
	return index+1;
}

int LinearSearch(int *a,int i,int n,int key)
{
	if(i==n)
	{
		return -1;
	}
	if(a[i]==key)
	{
		return i;
	}
	return LinearSearch(a,i+1,n,key)
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
	int key;
	cin>>key;
	cout<<firstOcc(arr,n,key);
	cout<<LinearSearch(a,0,n,key);
}
