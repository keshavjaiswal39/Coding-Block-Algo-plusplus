#include<bits/stdc++.h>
using namespace std;

int knapsack(int size_item[],int value[],long long weight,long long n)
{
	int dp[n+1][weight+1];
	
	// Build the table in top down manner
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=weight;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}

			else if(size_item[i-1]<=j)
			{
				// if we include the option or leave it in case the weight of the item is less than the original weight
				dp[i][j]=max(value[i-1]+dp[i-1][j-size_item[i-1]],dp[i-1][j]);
			}

			else
			{
				dp[i][j]=dp[i-1][j];			
			}			
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=weight;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	//return dp[n][weight];

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
	
	cout<<knapsack(size_item,value,weight,n);
}
