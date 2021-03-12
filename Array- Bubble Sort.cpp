#include<iostream>
#include<algorithm>
using namespace std;

void BubbleSort(int arr[],unsigned long long int n)
{
	unsigned long long int i,j;
	unsigned long long int flag;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
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
	BubbleSort(arr,n);
	for(unsigned long long int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
