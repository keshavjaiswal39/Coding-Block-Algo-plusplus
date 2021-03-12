#include<bits/stdc++.h>
using namespace std;

int fibonacci_recursion(int n)
{
	if(n==0 || n==1)
	{
		return n;
	}
	return fibonacci_recursion(n-2)+fibonacci_recursion(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<fibonacci_recursion(n);
}
