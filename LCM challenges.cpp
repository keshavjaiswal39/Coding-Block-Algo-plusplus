#include<iostream>
using namespace std;

int GCD(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	b=GCD(b,a%b);
	return b;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int gcd=GCD(a,b);
	int lcm=(a*b)/gcd;
	cout<<lcm;
}
