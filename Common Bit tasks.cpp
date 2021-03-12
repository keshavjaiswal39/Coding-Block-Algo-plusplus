#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n)
{
	return (n&1);
}

int getBits(int n,int i)
{
	int mask=1<<i;
	return (n&mask)>0?1:0;
}

void setBits(int n,int i)
{
	int mask=1<<i;
	int ans=n|mask;
	cout<<n<<endl;
}

void clearBits(int n,int i)
{
	int mask=~(1<<i);
	int ans=n&mask;
	cout<<ans<<endl;
}

void updateBits(int n,int i,int v)
{
	int mask=~(1<<i);   // clear Bits
	int ans=n&mask;		// clear bits
	int mask_v=v<<i;    // mask for v
	int new_ans=ans | mask_v;
	cout<<new_ans<<endl;
}

void clearLastIBits(int n,int i)
{
	int mask=(~0)<<i;
	int ans=n&mask;
	cout<<ans<<endl;
}

void clearRangeIJBits(int n,int i,int j)
{
	int mask_A=(~0)<<j+1;
	int mask_B=(1<<i)-1;
	int mask=mask_A|mask_B;
	int ans=n&mask;
	cout<<ans<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i;
	cin>>i;
	if(isOdd(n))
	{
		cout<<"Odd";
	}
	else
	{
		cout<<"Even";
	}
	cout<<endl;
	cout<<"The ith bit is: "<<getBits(n,i)<<endl;
	setBits(n,i);
	clearBits(n,i);
	int v;
	cout<<"Enter the v"<<endl;
	cin>>v;
	updateBits(n,i,v);
	clearLastIBits(n,i);
	int j;
	cout<<"Enter the range j"<<endl;
	cin>>j;
	clearRangeIJBits(n,i,j);
}
