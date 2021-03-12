#include<iostream>
using namespace std;

bool canPlaceCows(int stalls[],int n,int c,int min_step)
{
	int last_cow=stalls[0];
	int count=1;
	for(int i=1;i<n;i++)
	{
		if(stalls[i]-last_cow>=min_step)
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
	int j,t;
	cin>>t;
	for(j=0;j<t;j++)
	{ 
		int stalls[1000],i,n,cows;
		cin>>n;
		cin>>cows;
		for(i=0;i<n;i++)
		{
			cin>>stalls[i];
		}
		int ans=0;
		int s=0;
		int e=stalls[n-1]-stalls[0];
		while(s<=e)
		{
			int mid=(s+e)/2;
			bool cowsRakhPaye = canPlaceCows(stalls,n,cows,mid);
			if(cowsRakhPaye)
			{
				ans=mid;
				s=mid+1;
			}
			else
			{
				e=mid-1;
			}
		}
		cout<<ans<<endl;
	}
}
