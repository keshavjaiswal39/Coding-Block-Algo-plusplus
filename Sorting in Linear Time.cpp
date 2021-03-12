#include<iostream>
using namespace std;

void SortLinearTime(int arr[],int n)
{
	int l,m,h;
	l=m=0;h=n-1;
	while(m<=h)
	{
		if(arr[m]==0)
		{
			swap(arr[l],arr[m]);
			l++;
			m++;
		}
		else if(arr[m]==1)
		{
			m++;
		}
		else
		{
			swap(arr[h],arr[m]);
			h--;
		}
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
	SortLinearTime(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
