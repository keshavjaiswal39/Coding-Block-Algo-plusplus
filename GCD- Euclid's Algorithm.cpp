#include<iostream>
using namespace std;

int find_GCD(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	b=find_GCD(b,a%b);
	return b;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<find_GCD(a,b);
}
