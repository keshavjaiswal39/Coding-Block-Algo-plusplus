#include<bits/stdc++.h>
using namespace std;

int clearRangeIJBits(int n,int i,int j)
{
	int mask_A=(~0)<<j+1;
	int mask_B=(1<<i)-1;
	int mask=mask_A|mask_B;
	int ans=n&mask;
	return ans;
}

int replaceBits(int n,int m,int i,int j)
{
	int n_new=clearRangeIJBits(n,i,j);
	int ans=n_new|(m<<i);
	return ans;
}

int main()
{
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	cout<<replaceBits(n,m,i,j);
}
