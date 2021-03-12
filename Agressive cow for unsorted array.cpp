#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(long long int stalls[],long long int n,long long int c,long long int min_step)
{
	long long int last_cow=stalls[0];
	long long int count=1;
	for(long long int i=1;i<n;i++)
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
		long long int stalls[10000],i,n,cows;
		cin>>n;
		cin>>cows;
		for(i=0;i<n;i++)
		{
			cin>>stalls[i];
		}
		sort(stalls,stalls+n);
		long long int ans=0;
		long long int s=0;
		long long int e=stalls[n-1]-stalls[0];
		while(s<=e)
		{
			long long int mid=(s+e)/2;
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
