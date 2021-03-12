#include<iostream>
using namespace std;

long long int Binary_Search(long long int arr[],long long int key,long long int n)
{
	long long int low=0;
	long long int high=n-1;
	while(low<=high)
	{
		long long int mid=(low+high)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}

int main()
{
	long long int n;
	cin>>n;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long int key;
	cin>>key;
	cout<<Binary_Search(arr,key,n);
}
