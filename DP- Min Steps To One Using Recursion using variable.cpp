#include<iostream>
using namespace std;

int minStepToMake1(int n)
{
	// base case
	if(n==1)
	{
		return 0;
	}
	
	// recursive case
	int op1,op2,op3;
	
	if(n%2==0)
	{
		op1= minStepToMake1(n/2)+1;
	}
	else if(n%3==0)
	{
		op2= minStepToMake1(n/3)+1;
	}
	
	op3= minStepToMake1(n-1)+1;
	
	int ans=min(op1,min(op2,op3));
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	cout<<minStepToMake1(n);
}
