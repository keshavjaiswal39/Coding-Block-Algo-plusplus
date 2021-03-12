#include<iostream>
using namespace std;

bool isSorted(long long int arr[],int n)
{
	// Base case
	if(n==0 || n==1)
	{
		return true;
	}
	// Recursive case
	if(arr[0]<=arr[1] and isSorted(arr+1,n-1))
	{
		return true;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	long long int arr[100005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(isSorted(arr,n))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
