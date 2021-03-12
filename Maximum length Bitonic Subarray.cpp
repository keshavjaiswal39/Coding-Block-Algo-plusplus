#include<iostream>
using namespace std;

int maxLengthBitonicSubArray(int A[],int n)
{
	int i;
	int inc[n];
	int dec[n];
	inc[0]=1;
	dec[n-1]=1;
	for(i=1;i<n;i++)
	{
		if(A[i]>A[i-1])
		{
			inc[i]=inc[i-1]+1;
		}
		else
		{
			inc[i]=1;
		}
	}
	for(i=n-2;i>=0;i--)
	{
		if(A[i]>A[i+1])
		{
			dec[i]=dec[i+1]+1;
		}
		else
		{
			dec[i]=1;
		}
	}
	int max_length=inc[0]+dec[0]-1;
	for(i=1;i<n;i++)
	{
		if (inc[i]+dec[i]-1>max_length)
		{
		
			max_length=inc[i]+dec[i]-1;
		}
	}
	return max_length;
}

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int n;
		cin>>n;
		int A[1000000];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		cout<<maxLengthBitonicSubArray(A,n)<<endl;
	}
}
