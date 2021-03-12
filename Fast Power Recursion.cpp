#include<bits/stdc++.h>
using namespace std;

int power_recursion(int a,int n)
{
	if(n==0)
	{
		return 1;
	}
	int pow=a*power_recursion(a,n-1);
	return pow;
}

int power_recursion_optimal(int a,int n)
{
	if(n==0)
	{
		return 1;
	}
	int smaller_ans=power_recursion_optimal(a,n/2);
	smaller_ans*=smaller_ans;
	
	if(n&1)   // for odd
	{
		return smaller_ans*a;
	}
	return smaller_ans;
}

int main()
{
	int a,n;
	cin>>a>>n;
	cout<<power_recursion(a,n)<<endl;
	cout<<int power_recursion_optimal(a,n); 
}
