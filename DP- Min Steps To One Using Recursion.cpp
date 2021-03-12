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
	if(n%2==0)
	{
		return min(minStepToMake1(n/2),minStepToMake1(n-1))+1;
	}
	else if(n%3==0)
	{
		return min(minStepToMake1(n/3),minStepToMake1(n-1))+1;
	}
	else
	{
		return minStepToMake1(n-1)+1;
	}
}

int main()
{
	int n;
	cin>>n;
	
	cout<<minStepToMake1(n);
}
