#include<iostream>
using namespace std;

int minStepToMake1(int n)
{
	int dp[100]={0};

	dp[1]=0;

	for(int i=2;i<=n;i++)
	{
		int op1,op2,op3;
		op1=op2=op2=INT_MAX;
	
		if(i%2==0)
		{
			op1=dp[i/2];
		}
		if(i%3==0)
		{
			op2=dp[i/3];
		}
		op3=dp[i-1];
		
		dp[i]=min(op1,min(op2,op3))+1;	
	}
	
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	
	cout<<minStepToMake1(n);
}
