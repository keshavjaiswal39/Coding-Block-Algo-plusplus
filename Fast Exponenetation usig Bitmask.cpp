#include<bits/stdc++.h>
using namespace std;

int PowerOptimised(int a,int n)
{
	int ans=1;
	while(n>0)
	{
		int last_bit=(n&1);
		if(last_bit)
		{
			ans=ans*a;
		}
		a=a*a;
		n=n>>1;
	}
	return ans;
	return 0;
}

int main()
{
	int a,n;
	cin>>a>>n;	
	cout<<PowerOptimised(a,n);
}
