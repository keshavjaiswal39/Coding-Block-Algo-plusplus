#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll countNumberofBits(int n)
{
	ll a[n],b[n];
	a[0]=b[0]=1;
	
	for(ll i=1;i<n;i++)
	{
		a[i]=a[i-1]+b[i-1];  // we can append 0 with the string ending with both 0 or 1
		b[i]=a[i-1];  // we can only append 1 with the string ending with 0
	}
	
	return a[n-1]+b[n-1];   // total ways
}

int main()
{
	ll t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		
		cout<<countNumberofBits(n)<<endl;
	}
}
