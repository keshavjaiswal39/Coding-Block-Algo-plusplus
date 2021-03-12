#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(string s1,string s2,string s3)
{
	// bottom up approach to lcs
	int n1=s1.length();
	int n2=s2.length();
	int n3=s3.length();
	
	// 3d DP array
	int dp[120][120][120];
	
	// 1,1,........n1,n2
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			for(int k=0;k<=n3;k++)
			{
				if(i==0 || j==0 || k==0)
				{
					dp[i][j][k]=0;
				}
				else if(s1[i-1]==s2[j-1] and s1[i-1]==s3[k-1])
				{
					dp[i][j][k]=1+dp[i-1][j-1][k-1];
				}
				else
				{
					int op1=dp[i-1][j][k];
					int op2=dp[i][j-1][k];
					int op3=dp[i][j][k-1];
					dp[i][j][k]=max(op1,max(op2,op3));
				}
			}
		}
	}
	
	return dp[n1][n2][n3];
	
}

int main()
{
	string s1;
	string s2;
	string s3;
	
	cin>>s1;
	cin>>s2;
	cin>>s3;
	
	cout<<lcs(s1,s2,s3);
	
}
