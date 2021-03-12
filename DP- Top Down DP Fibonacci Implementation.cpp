#include<iostream>
using namespace std;

int fib(int n,int dp[])
{
	// base case
	if(n==0 || n==1)
	{
		return n;
	}
	// recursive case
	// look up
	if(dp[n]!=0)
	return dp[n];
	
	int ans;
	ans = fib(n-1,dp)+fib(n-2,dp);
	return dp[n]=ans;
}

int main()
{
	int n;
	cin>>n;
	int dp[100]={0};
	cout<<fib(n,dp);
}
