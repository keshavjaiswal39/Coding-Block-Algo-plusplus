#include<iostream>
using namespace std;

int minCoin(int n,int coins[],int T)
{
	// base case
	if(n==0)
	{
		return 0;
	}
	
	// recursive case
	
	int ans=INT_MAX;
	
	for(int i=0;i<T;i++)
	{
		if(n-coins[i]>=0)
		{
			int subprob=minCoin(n-coins[i],coins,T)+1;
			ans=min(ans,subprob);
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	int coins[]={1,7,10};	

	int T=3;
	
	cout<<minCoin(n,coins,T);
}
