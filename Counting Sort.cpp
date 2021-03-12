#include<bits/stdc++.h>
using namespace std;

void Counting_Sort(int *a,int n)
{
	// Largest in the array assuming no>0
	int largest=-1;
	for(int i=0;i<n;i++)
	{
		largest=max(largest,a[i]);
	}
	
	// creating a frequency array
	int *freq=new int[largest+1]; // frequency array
	for(int i=0;i<=largest+1;i++)
	{
		freq[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		freq[a[i]]++;
	}
	
	
	// Putting all the elements back into the array by readinf frequency array
	int j=0;
	for(int i=0;i<=largest;i++)
	{
		while(freq[i]>0)
		{
			a[j]=i;
			freq[i]--;
			j++;
		}
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
	Counting_Sort(arr,n);
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	return 0;
}
