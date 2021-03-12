#include<bits/stdc++.h>
using namespace std;

int lastOcc(int *a,int n,int key)
{
	if(n==0)
	{
		return -1;
	}
	int index=lastOcc(a+1,n-1,key);
	if(index==-1)
	{
		if(a[0]==key);
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	return index+1;
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
	cout<<lastOcc(arr,n,key);
}
