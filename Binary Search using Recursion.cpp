#include<bits/stdc++.h>
using namespace std;

int Bin_Search_Recursion(int arr[],int l,int h,int key)
{
	int mid=(l+h)/2;
	if(arr[mid]==key)
	{
		return mid;
	}
	if(key<arr[mid])
	{
		return Bin_Search_Recursion(arr,l,mid-1,key);
	}
	else
	{
		return Bin_Search_Recursion(arr,mid+1,h,key);
	}
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
	int l=0;
	int h=n-1;
	int key;
	cin>>key;
	cout<<Bin_Search_Recursion(arr,l,h,key);
	
}
