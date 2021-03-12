#include<iostream>
using namespace std;

int maxWater(long int A[],int n)
{
	int L[100000],R[100000],i;
	L[0]=A[0];
	R[n-1]=A[n-1];
	for(i=1;i<n;i++)
	{
		L[i]=max(L[i-1],A[i]);
	}
	for(i=n-2;i>=0;i--)
	{
		R[i]=max(R[i+1],A[i]);
	}
	int water=0;
	for(i=0;i<n;i++)
	{
		water+=(min(L[i],R[i])-A[i]);
	}
	return water;
}

int main()
{
	int n;
	cin>>n;
	long int A[1000000];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<maxWater(A,n)<<endl;
}
