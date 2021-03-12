#include<bits/stdc++.h>
using namespace std;

int multiple_recursion(int a,int b)
{
	if(b==0)
	{
		return 0;
	}
	int prod=a+multiple_recursion(a,b-1);
	return prod1;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<multiple_recursion(a,b);
}
