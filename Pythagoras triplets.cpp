#include<iostream>
using namespace std;

int main() 
{
	int n,a,b;
	cin>>n;
	a=n+1;
	b=n+2;

	if((a*a)+(n*n)==(b*b))
	{
		cout<<a<<" "<<b<<endl;
	}

	else
	{
		return -1;
	}
}
