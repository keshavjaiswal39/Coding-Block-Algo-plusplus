#include<iostream>
using namespace std;

int max(int A[],int n)
{
	int max_val=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(A[i]>max_val)
		{
			max_val=A[i];
		}
	}
	return max_val;
}

int main()
{
	int n;
	cin>>n;
	int A[1000000];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<max(A,n);
}
