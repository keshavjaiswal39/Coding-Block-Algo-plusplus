#include<bits/stdc++.h>
using namespace std;

int power_recursion(int a,int n)
{
	if(n==0)
	{
		return 1;
	}
	int pow=a*power_recursion(a,n-1);
	return pow;
}

int main()
{
	int a,n;
	cin>>a>>n;
	cout<<power_recursion(a,n);
}
