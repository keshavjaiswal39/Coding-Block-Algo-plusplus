#include<iostream>
using namespace std;

int maxWater(long int A[],int n)
{
	int i,j,res=0;
	for(i=1;i<n-1;i++)
	{
		//		max value in the left side from 0 to i
		int left=A[i];
		for(j=0;j<i;j++)
		{
			left=max(left,A[j]);
		}
		
		//		max value in the right side from i+1 to n
		int right=A[i];
		for(j=i+1;j<n;j++)
		{
			right=max(right,A[j]);
		}
		
		//      update the res with the max water
		res = res + (min(left,right)-A[i]);
	}
	return res;
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
