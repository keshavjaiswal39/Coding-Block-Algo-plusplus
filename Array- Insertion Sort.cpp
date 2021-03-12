#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=arr[i];
		j=i-1;
		while(arr[j]>x && j>-1)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=x;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	InsertionSort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
