#include<bits/stdc++.h>
using namespace std;

int knapsack(int size_item[],int value[],long long weight,long long n,int dp[][1000])
{
	
	// base condition
	if(n==0 || weight==0)   
	{
		return 0;
	}
	
	// look out phase
	if(dp[n][weight]!=-1)
	{
		return dp[n][weight];
	}
	
	// recursive case
	// two option
	// either take a particular item or dont take it
	// will take the max among both
	
	if(size_item[n-1]<=weight)   // if value for the item which we are picking is less than the weight
	{
		// option 1- take that item
		int op1=value[n-1]+knapsack(size_item,value,weight-size_item[n-1],n-1,dp);
		// option 2- dont take that item
		int op2=knapsack(size_item,value,weight,n-1,dp);
		
		return dp[n][weight]=max(op1,op2);
	}
	
	// if the weight is greater than the selected size then we dont take that element

	return dp[n][weight]=knapsack(size_item,value,weight,n-1,dp);

}

int main()
{
	long long n;
	cin>>n;
	
	long long weight;
	cin>>weight;
	
	int size_item[n];
	int value[n];
	
	for(long long i=0;i<n;i++)
	{
		cin>>size_item[i];
	}
	
	for(long long i=0;i<n;i++)
	{
		cin>>value[i];
	}
	
	int dp[1000][1000];
	memset(dp,-1,sizeof(dp));
	
	cout<<knapsack(size_item,value,weight,n,dp);
}
