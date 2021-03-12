#include<iostream>
using namespace std;

int maxProfitWine(int wines[],int i,int j,int cost,int dp[][100])
{
	// base case
	if(i>j)   // means no bottles are left
	{
		return 0;
	}
	
	// Return if dp[i][j] is known
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	
	// recursive case
	
	// option 1: sell 1st bottle and recursively call for the right array from 2 to n-1
	int op1=wines[i]*cost+maxProfitWine(wines,i+1,j,cost+1,dp);

	// option 1: sell last bottle and recursively call for the left array from 1 to (n-1)-1
	int op2=wines[j]*cost+maxProfitWine(wines,i,j-1,cost+1,dp);
	
	return dp[i][j]=max(op1,op2);
}

int main()
{
	int wines[]={2,3,5,1,4};	
	int dp[100][100]={0};
	int n=sizeof(wines)/sizeof(int);
	
	cout<<maxProfitWine(wines,0,n-1,1,dp);
}
