#include<iostream>
using namespace std;

bool Isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

void print_prime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(Isprime(i))
		{
			cout<<i<<" ";
		}
	}
}

int main()
{
	int n;
	cin>>n;
	print_prime(n);
}
