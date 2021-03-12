#include<iostream>
using namespace std;

int minCoin(int n,int coins[],int T)
{
	int dp[100]={0};
	
	// iterate over all state
	for(int i=1;i<=n;i++)
	{
		// init the current ans as INT_MAX
		dp[i]=INT_MAX;
		for(int j=0;j<T;j++)
		{
			if(i-coins[j]>=0)
			{
				int subprob=dp[i-coins[j]]+1;
				dp[i]=min(dp[i],subprob);
			}
		}
	}
	return dp[n];
			
}

int main()
{
	int n;
	cin>>n;
	
	int coins[]={1,7,10};	

	int T=3;
	
	cout<<minCoin(n,coins,T);
} 
