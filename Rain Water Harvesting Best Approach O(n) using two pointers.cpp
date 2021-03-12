#include<iostream>
using namespace std;

int maxWater(long int A[],int n)
{
	int l_max=0,r_max=0;
	int i=0;
	int j=n-1;
	int water=0;
	while(i<=j)
	{
		if(A[i]<A[j])
		{
			if(A[i]>l_max)
			{
				l_max=A[i];
			}
			else
			{
				water+=l_max-A[i];
			}
			i++;
		}
		else
		{
			if(A[j]>r_max)
			{
				r_max=A[j];
			}
			else
			{
				water+=r_max-A[j];
			}
			j--;
		}
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
