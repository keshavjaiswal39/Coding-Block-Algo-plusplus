#include<bits/stdc++.h>
#include<algorithm>
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
		int length=upper_bound(dp,dp+(n+1),a[i])-dp; // will give me the index
		
		if(dp[length-1]<a[i] and a[i]<dp[length])
		{
			dp[length]=a[i];
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
