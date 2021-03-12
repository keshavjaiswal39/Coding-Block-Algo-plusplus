#include<iostream>
using namespace std;

void Binary_Search(int arr[],int key,int n)
{
	int x=0;
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==key)
		{
			cout<<"Element found at index: "<<mid<<endl;
			x=1;
			break;
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
	if(x==0)
	{
		cout<<"Element not found"<<endl;
	}
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
	Binary_Search(arr,key,n);
}
