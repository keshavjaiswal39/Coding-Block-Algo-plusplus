 #include<iostream>
#include<vector>
using namespace std;

vector<int> prime_sieve(int *p,int n)
{
	p[2]=1;
	p[1]=p[0]=0;
	
	// first mark all odd number as prime
	for(int i=3;i<n;i+=2)
	{
		p[i]=1;    // marking all the odd numbers as 1
	}
	// sieve
	 
	for(int i=3;i<n;i+=2)
	{
		// if the current number is not marked (it is prime)
		if(p[i]==1)
		{
			for(int j=i*i;j<=n;j=j+i)
			{
				p[j]=0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);
	
	for(int i=3;i<=n;i+=2)
	{
		if(p[i]==1)
		{
			primes.push_back(i);
		}
	}
	return primes;
}


int no_of_divisors(int n,vector<int> &primes)
{

	int i=0;
	int p=primes[0];
	int ans=1;
	while(p*p<=n)
	{
		if(n%p==0)
		{
			int cnt=0;
			while(n%p==0)
			{
				cnt++;
				n=n/p;
			}
			ans=ans*(cnt+1);
		}
		i++;
		p=primes[i];
	} 
	
	if(n!=1)
	{
		ans=ans*2;
	}
	return ans;
}

int main()
{
	int n=1000;
	int p[n]={0};
	vector<int> primes = prime_sieve(p,1000);
	int num;
	cin>>num;
	int divisors=no_of_divisors(num,primes);
	cout<<divisors;
}
