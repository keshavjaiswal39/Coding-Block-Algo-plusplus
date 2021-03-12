#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int numWays(int R,int C)
{
	// base case
	if(dp[0][0]==-1)
	{
		return 0;
	}
	
	// compute the no. of ways for the first row
	for(int j=0;j<C;j++)
	{
		if(dp[0][j]==-1)
		{
			break;
		}
		dp[0][j]=1;
	}
	
	// compute the no. of ways for the first col
	for(int j=0;j<R;j++)
	{
		if(dp[j][0]==-1)
		{
			break;
		}
		dp[j][0]=1;
	}
	
	// Bottom up approach for the rest of the matrix
	for(int i=1;i<R;i++)
	{
		for(int j=1;j<C;j++)
		{
			if(dp[i][j]==-1)
			{
				continue;
			}
			dp[i][j]=0;
			
			if(dp[i][j-1]!=-1);
			{
				dp[i][j]=dp[i][j-1]%MOD;
			}
			
			if(dp[i-1][j]!=-1)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
			}
		}
	}
	
	// check for the final calls
	if(dp[R-1][C-1]==-1)
	{
		return 0;
	}
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return dp[R-1][C-1];
	
}


int main()
{
	memset(dp,0,sizeof dp);
	
	int M,N,P;   // number of rows and number of columns
	cin>>M>>N>>P;
	
	for(int i=0;i<P;i++)
	{
		int x,y;
		cin>>x>>y;
		
		// Marks all the blocked cell as -1;
		dp[x-1][y-1]=-1;
	}
	
	cout<<numWays(M,N)<<endl;
	
	
	return 0;
}
