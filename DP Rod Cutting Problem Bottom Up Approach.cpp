#include<iostream>
using namespace std;

int max_profit(int price[],int n)
{
	int dp[n+1];
	dp[0]=0;
	
	int ans=INT_MIN;
	for(int len=1;len<=n;len++)
	{
		for(int i=0;i<len;i++)
		{
			int cut=i+1;
			int current_ans=price[i]+dp[len-cut];
			ans=max(current_ans,ans);
		}
		dp[len]=ans;
	}
	
	return dp[n];
}

int main()
{
	int price[]={1,5,8,9,10,17,17,20};
	int n=sizeof(price)/sizeof(int);
	
	cout<<max_profit(price,n);
	
}
