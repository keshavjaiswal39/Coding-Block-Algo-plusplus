#include<bits/stdc++.h>
using namespace std;

void prime_sieve(bool *p)
{
	// first mark all odd number as prime
	for(unsigned long long int i=3;i<=1000005;i+=2)
	{
		p[i]=1;    // marking all the odd numbers as 1
	}
	// sieve 
	for(unsigned long long int i=3;i<=1000005;i+=2)
	{
		// if the current number is not marked (it is prime)
		if(p[i]==1)
		{
			for(unsigned long long int j=i*i;j<=1000005;j=j+i)
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
	unsigned long long int n;
	cin>>n;
	bool p[1000005]={0};   // as we need a greater size array we take bool instead of int or long long int
	prime_sieve(p);
	unsigned long long int j=0;
	unsigned long long int new_arr[500000];
	for(unsigned long long int i=0;i<=1000005;i++)
	{
		if(p[i]==1)
		{
			new_arr[j++]=i;
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<new_arr[i]<<" ";
	// }
	cout<<new_arr[n-1];
}
