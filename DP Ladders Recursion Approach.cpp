#include<iostream>
using namespace std;

int ladders_topdown(int n,int k)
{
	// base case
	if(n==0)
	{
		return 1;
	}
	
	// rec case
	int ways=0;
	
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)
		{
			ways=ways+=ladders_topdown(n-i,k);
		}
	}
	return ways;
	
}

int main()
{
	int n,k;
	cin>>n>>k;
	
	cout<<ladders_topdown(n,k);

}

