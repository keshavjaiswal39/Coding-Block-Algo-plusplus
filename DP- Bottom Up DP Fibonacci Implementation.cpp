#include<iostream>
using namespace std;

int fib(int n)
{
	int dp[100]={0};
	dp[1]=1;
	 
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

// space optimisation
int fibSpaceOpt(int n)
{
	if(n==0 || n==1)
	{
		return n;
	}
	int a=0;
	int b=1;
	int c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	
	cout<<fib(n)<<endl;
	cout<<fibSpaceOpt(n);
}
