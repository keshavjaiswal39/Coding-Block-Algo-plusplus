#include<iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	int num;
	int i;
	for(i=0;i<t;i++)
	{
		cin>>num;
		int sum1=0,sum2=0;
		int rem=0;
		while(num!=0)
		{
			rem=num%10;
			num/=10;
			if(rem%2==0)
		{
			sum1+=rem;
		}
		else
		{
			sum2+=rem;
		}
		}
		if(sum1%4==0 || sum2%3==0)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
		
	}
}
