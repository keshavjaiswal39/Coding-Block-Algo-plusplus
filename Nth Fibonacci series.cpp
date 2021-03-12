#include<iostream>
using namespace std;

int nth_fibonacci(int n)
{
	int a=0,b=1;
	int i,c;
	for(i=0;i<n-2;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	cout<<nth_fibonacci(n);
}
