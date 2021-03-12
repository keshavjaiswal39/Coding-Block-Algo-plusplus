#include<iostream>
using namespace std;

bool isPrime(int n)
{
	int i;
	for(i=2;i<n-1;i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}

int main() 
{
	int n;
	cin>>n;
	if(isPrime(n))
	{
		cout<<"Prime";
	}
	else
	{
		cout<<"Not Prime";
	}
}
