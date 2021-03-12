#include<bits/stdc++.h>
using namespace std;

long long dp[1010],n,cap,wt[1010],val[1010];
int main()
{
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>wt[i];
    
	for(int i=1;i<=n;i++)
        cin>>val[i];
        
    for(int i=0;i<=cap;i++)
	{
        for(int j=0;j<n;j++)
		{
		    if(wt[j] <= i)
                dp[i] = max(dp[i], val[j]+dp[i-wt[j]]);
        }
    }
    cout<<dp[cap];

    return 0;
}
