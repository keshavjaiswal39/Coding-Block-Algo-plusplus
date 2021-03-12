#include<iostream>
using namespace std;

float Square_root_binsearch(int n, int p)
{
	int l=0;
	int h=n-1;
	float ans=-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(mid*mid==n)
		{
			return mid;
		}
		else if(mid*mid<n)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	
	// For floating part
	// Brute force
	
	float inc=0.1;
	for(int times=1;times<=p;times++)
	{
		while(ans*ans<=n)
		{
			ans=ans+inc;
		}
		ans=ans-inc;
		inc=inc/10;
	}
	return ans;
}

int main()
{
	int n;
	int p;
	cin>>n;
	cin>>p;   // this says upto what place we want the decimal or the floating part.
	cout<<Square_root_binsearch(n,p);
}
