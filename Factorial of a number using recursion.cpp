#include<bits/stdc++.h>
using namespace std;

int factorial_recursion(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*factorial_recursion(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<factorial_recursion(n);
}
