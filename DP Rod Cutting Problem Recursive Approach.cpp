#include<iostream>
using namespace std;

int max_profit(int price[],int n)
{
	// base case
	if(n<=0)
	{
		return 0;
	}
	
	// rec case
	int ans=INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		int cut=i+1;   // if i=0, we are making a cut of length 1
		int current_ans=price[i]+max_profit(price,n-cut);
		ans=max(ans,current_ans);
	}
	return ans;
}

int main()
{
	int price[]={1,5,8,9,10,17,17,20};
	int n=sizeof(price)/sizeof(int);
	
	cout<<max_profit(price,n);
	
}
