#include<iostream>
#include<algorithm>
using namespace std;

void SelectionSort(int arr[],unsigned long long int n)
{
	unsigned long long  int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i;j<n;j++)
		{
			if(arr[j]<arr[k])
			{
				k=j;
			}
		}
		swap(arr[i],arr[k]);
	}
}


int main()
{
	unsigned long long int n;
	cin>>n;
	int arr[100000];
	for(unsigned long long int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	SelectionSort(arr,n);
	for(unsigned long long int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
