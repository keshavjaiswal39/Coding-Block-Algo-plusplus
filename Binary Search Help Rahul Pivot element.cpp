#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Binary_search(int arr[],int n,int key)
{
	int l=0;
	int h=n-1;
	int mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[l]<=arr[mid])  // it means that the 1st part of the array is sorted and we have to search in this part
		{
			if(key>=arr[l] && key<=arr[mid])
			{
				h=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		else  // it means that the 2nd part of the array is sorted and we have to search in this part
		{
			if(arr[mid]<=key && arr[h]>=key)
			{
				l=mid+1;
			}
			else
			{
				h=mid-1;
			}
		}
	}
	return -1; // if not found
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<Binary_search(arr,n,key);

}
