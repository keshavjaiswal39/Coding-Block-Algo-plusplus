#include<bits/stdc++.h>
using namespace std;

void prime_sieve(int *p)
{
	// first mark all odd number as prime
	for(int i=3;i<1000;i+=2)
	{
		p[i]=1;    // marking all the odd numbers as 1
	}
	// sieve 
	for(int i=3;i<1000;i+=2)
	{
		// if the current number is not marked (it is prime)
		if(p[i]==1)
		{
			for(int j=i*i;j<=1000;j=j+i)
			{
				p[j]=0;
			}
		}
	}
		// Special cases
		p[2]=1;
		p[1]=p[0]=0;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int p[1000]={0};
	prime_sieve(p);
	int count=0;
	for(int i=a;i<=b;i++)
	{
		if(p[i]==1)
		{
			count++;
		}
	}
	cout<<count;
}
