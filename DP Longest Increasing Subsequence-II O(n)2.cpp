#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1,5,2,3,4,9,6,10};
	int n=8;
	
	int dp[n+1]={0};
	dp[0]=-32767;
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=32767;  // Every element can end at length 1
	}
	
	for(int i=0;i<n;i++)
	{
		for(int len=0;len<n;len++)
		{
			if(dp[len]<a[i] and a[i]<dp[len+1])
			{
				dp[len+1]=a[i];
			}
		}
	}
	 
	int lis=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]!=32767)
		{
			lis=i;
		}
	}	
	cout<<lis;
	
}
