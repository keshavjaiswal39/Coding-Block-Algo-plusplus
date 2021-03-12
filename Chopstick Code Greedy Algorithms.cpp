#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n,d;
	cin>>n>>d;
	
	int l[100000];
	
	for(ll i=0;i<n;i++)
	{
		cin>>l[i];
	}
	
	sort(l,l+n);
	
	int i=0;
	int count=0;
	while(i<n-1)
	{
		if(l[i+1]-l[i]<=d)
		{
			count++;
			i=i+2;
		}
		else
		{
			i=i+1;
		}
	}
	cout<<count;
}
