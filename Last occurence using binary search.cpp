#include<iostream>
using namespace std;

int Last_occurence(int arr[],int key,int n)
{
	int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==key)
		{
			ans=mid;
			low=mid+1;
		}
		else if(arr[mid]>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return ans;
}

int main()
{
	int n;
	cout<<"Enter the number of element you want in the array: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key;
	cout<<"Enter the key element to be found: "<<endl;
	cin>>key;
	cout<<"The last occurence is at index "<<Last_occurence(arr,key,n);
}
