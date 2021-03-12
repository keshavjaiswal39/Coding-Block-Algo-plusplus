#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcsOf3strings(string a,string b,string c)
{
	int dp[120][120][120];
	int m = a.size();
	int n = b.size();
	int p = c.size();
	
	for (int i=0; i<=m; i++)    
	{
	    for (int j=0; j<=n; j++)        
		{
	        for (int k=0; k<=p; k++)            
			{
	            if (i == 0 || j == 0|| k == 0)
				{
	                dp[i][j][k] = 0;
	            }
	            else if (a[i-1] == b[j-1] && a[i-1] == c[k-1])
				{
	                dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
	            }
	            else
	                dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
	        }
	    }
	}
    return dp[m][n][p];

}
    
int main()
{
	string s1;
	string s2;
	string s3;
	
	cin>>s1;
	cin>>s2;
	cin>>s3;
	
	cout<<lcsOf3strings(s1,s2,s3);
	
}
