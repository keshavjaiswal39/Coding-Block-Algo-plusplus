#include<bits/stdc++.h>
using namespace std;

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=(res*a)%c;	
		}	
		a=(a*a)%c;
		b=b>>1;
	}
	return res;
}

int main()
{
	long long int a,b,c;
	cin>>a>>b>>c;
	cout<<modular_exponentiation(a,b,c)<<endl;
}
