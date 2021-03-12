#include<bits/stdc++.h>
using namespace std;

long long dp[1010][1010],n,cap,wt[1010],val[1010];
int main()
{
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>wt[i];
    
	for(int i=1;i<=n;i++)
        cin>>val[i];

    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    
	for(int j=1;j<=cap;j++)
        dp[0][cap] = 0;

    for(int i=1;i<=cap;i++)
	{
        for(int j=1;j<=n;j++)
		{
            dp[i][j] = dp[i][j-1];
        
		    if(wt[j] <= i)
                dp[i][j] = max(dp[i][j], val[j]+dp[i-wt[j]][j]);
        }
    }
    cout<<dp[cap][n];

    return 0;
}
