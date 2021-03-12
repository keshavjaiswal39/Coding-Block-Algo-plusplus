#include<iostream>
using namespace std;

int numberOfWays(int n)
{
	int dp[n+1]={0};
	if(n==0 || n==1 || n==2)
	{
		return n;
	}
	
	if(dp[n]!=0)
	{
		return dp[n];
	}
	
	int ans;
	ans=numberOfWays(n-1)+(n-1)*numberOfWays(n-2);
	return dp[n]=ans;
}

int main()
{
	int n;
	cin>>n;
	
	cout<<numberOfWays(n);
}
