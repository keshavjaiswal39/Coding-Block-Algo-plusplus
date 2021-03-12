#include<iostream>
using namespace std;

bool canPlaceCows(int stalls[],int n,int c,int min_sep)
{
	int count=1;
	int last_cow=stall[0];
	for(int i=1;i<n;i++)
	{
		if(stalls[i]-last_cow>=min_sep)
		{
			last_cow=stalls[i];
			count++;
			if(count==c)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int stalls[]={1,2,4,8,9};
	int n=5;
	int cows=3;
	
	// binary search algorithm
	int l=0;int h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		bool cowsRakhPaye=canPlaceCows(stalls,n,cows,mid);
		if(cowsRakhPaye)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	cout<<ans;	
}
