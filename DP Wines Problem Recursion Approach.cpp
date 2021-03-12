#include<iostream>
using namespace std;

int maxProfitWine(int wines[],int i,int j,int cost)
{
	// base case
	if(i>j)   // means no bottles are left
	{
		return 0;
	}
	
	// recursive case
	
	// option 1: sell 1st bottle and recursively call for the right array from 2 to n-1
	int op1=wines[i]*cost+maxProfitWine(wines,i+1,j,cost+1);

	// option 1: sell last bottle and recursively call for the left array from 1 to (n-1)-1
	int op2=wines[j]*cost+maxProfitWine(wines,i,j-1,cost+1);
	
	return max(op1,op2);
}

int main()
{
	int wines[]={2,3,5,1,4};	

	int n=sizeof(wines)/sizeof(int);
	
	cout<<maxProfitWine(wines,0,n-1,1);
}
