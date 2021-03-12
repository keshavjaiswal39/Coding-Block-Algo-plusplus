#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	int primes[]={2,3,5,7,11,13,17,19};
		
	while(t--)
	{
		long long int n;
		cin>>n;
		
		long long int subset=(1<<8)-1; // 2^n-1
		long long int ans=0;
		
		for(long long int i=1;i<=subset;i++)
		{
			long long int denom=1ll;
			long long int setBits=__builtin_popcount(i);
			
			for(long long int j=0;j<=7;j++)
			{
				if(i&(i<<j))
				{
					denom=denom*primes[j];
				}
			}
			if(setBits&1)
			{
				ans+= n/denom;
			}
			else
			{
				ans-= n/denom;
			}
		}
		cout<<ans<<endl;
	}

}
