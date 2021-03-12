#include<iostream>
using namespace std;

int minCoin(int n,int coins[],int T,int dp[])
{
	// base case
	if(n==0)
	{
		return 0;
	}
	
	// recursive case
	// look out case
	if(dp[n]!=0)
	{
		return dp[n];
	}
	
	int ans=INT_MAX;
	
	for(int i=0;i<T;i++)
	{
		if(n-coins[i]>=0)
		{
			int subprob=minCoin(n-coins[i],coins,T,dp)+1;
			ans=min(ans,subprob);
		}
	}
	
	dp[n]=ans;
	
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	
	int coins[]={1,7,10};	
	int dp[100]={0};
	int T=3;
	
	cout<<minCoin(n,coins,T,dp);
}
