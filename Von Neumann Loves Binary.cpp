#include<iostream>
using namespace std;

int main() 
{
	int i,j,t,n;
	cin>>t;
	for(j=0;j<t;j++)
	{
		int sum=0,rem,base=1;
		cin>>n;
		while(n>0)
		{
			rem=n%10;
			sum+=rem*base;
			base*=2;
			n/=10;
		}
		cout<<sum<<endl;
	}
	return 0;
}
