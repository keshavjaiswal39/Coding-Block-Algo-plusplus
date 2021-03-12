// Counting Set Bits Method 2

#include<bits/stdc++.h>
using namespace std;

int FastcountSetBits(int n)
{
	int ans=0;
	while(n>0)
	{
		n=n&(n-1);
		ans++;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<FastcountSetBits(n);
}

