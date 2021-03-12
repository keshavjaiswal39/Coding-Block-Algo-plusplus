#include<iostream>
using namespace std;

int max_element(int arr[],int n)
{
	int i;
	int max=-32767;
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

void CountSort(int arr[],int n)
{
	int i,j,max,*h;
	max=max_element(arr,n);
	h=new int[max];
	for(int i=0;i<=max;i++)
	{
		h[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		h[arr[i]]++;
	}
	i=0;j=0;
	while(j<=max)
	{
		if(h[j]>0)
		{
			arr[i]=j;
			h[j]--;
			i++;
		}
		else
		{
			j++;
		}
	}
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
	CountSort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
