#include<iostream>
using namespace std;

int main() 
{
	int num;
	cin>>num;
	int rem,fact=1,bin=0;;
	while(num!=0)
	{
		rem=num%10;
		bin+=rem*fact;
		fact*=2;
		num/=10;
	}
	cout<<bin;
	return 0;
}
