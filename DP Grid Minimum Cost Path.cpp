#include<iostream>
using namespace std;

int cost[100][100]={{1,5,2},{7,1,1},{8,1,3}};

int min_cost(int R,int C)
{
	int dp[100][100]={0};
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(i==0 and j==0)
			{
				dp[i][j]=cost[0][0];
			}
			else if(i==0)
			{
				dp[i][j]=dp[0][j-1]+cost[0][j];
			}
			else if(j==0)
			{
				dp[i][j]=dp[i-1][0]+cost[i][0];
			}
			else
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
			}
		}
	}
	return dp[R-1][C-1];
}

int main()
{
	cout<<min_cost(3,3);
}
