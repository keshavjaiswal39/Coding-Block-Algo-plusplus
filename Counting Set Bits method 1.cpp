// Counting Set Bits Method 1

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
	int ans=0;
	while(n>0)
	{
		ans=ans+(n&1);
		n=n>>1;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<countSetBits(n);
}
