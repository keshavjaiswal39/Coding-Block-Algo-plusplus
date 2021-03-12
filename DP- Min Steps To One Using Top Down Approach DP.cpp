#include<iostream>
using namespace std;

int minStepToMake1(int n,int dp[])
{
	// base case
	if(n==1)
	{
		return 0;
	}
	
	
	// lets look up if n is already computed
	
	if(dip[n]!=0)
	{
		return dp[n];
	}
	
	// compute if dp[n] is not known for first time
	int op1,op2,op3;
	
	if(n%2==0)
	{
		op1= minStepToMake1(n/2,dp)+1;
	}
	else if(n%3==0)
	{
		op2= minStepToMake1(n/3,dp)+1;
	}
	
	op3= minStepToMake1(n-1,dp)+1;
	int ans=min(op1,min(op2,op3));
	
	return dp[n]=ans;   // here dp[n] is stored and it return to the call stack 
}

int main()
{
	int n;
	cin>>n;
	
	int dp[100]={0};
	
	cout<<minStepToMake1(n,dp);
}
