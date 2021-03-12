#include<iostream>
using namespace std;

int main() 
{
	long long int a=0,b=1,c;
	int i,j;
	int n;
	cin>>n;
	int m=n*(n+1)/2;
	if(n==1 || n>=1)
	cout<<a<<endl;
	c=a+b;
	if(n>=2)
	cout<<b<<"\t"<<c<<endl;
	a=b;
	b=c;
	for(i=3;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			c=a+b;
			a=b;
			b=c;
			cout<<c<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
