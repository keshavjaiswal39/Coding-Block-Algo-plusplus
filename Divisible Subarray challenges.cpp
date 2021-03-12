#include<bits/stdc++.h>
using namespace std;

long long int a[100005],pre[100005];

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		memset(pre,0,sizeof(pre));
		pre[0]=1;   // we always include first element as 0 and its frequency is always 1
		
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			sum%=n;
			sum=(sum+n)%n; // sometime the sum may be in minus
			pre[sum]++;
		}
		long long int ans=0;
		for(int i=0;i<n;i++)
		{
			long long int m=pre[i];
			ans+=(m)*(m-1)/2;
		}
		cout<<ans;
	}
}
