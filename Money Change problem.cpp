#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
	return a<=b;
}

int main()
{
	int money;
	cin>>money;
	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(coins)/sizeof(int);
	while(money>0)
	{
		int lb=lower_bound(coins,coins+n,money,compare)-coins-1; //this gives the index of the coin which is to be taken
		int m=coins[lb];
		cout<<m<<" change"<<endl;
		money=money-m;
	}
	return 0;
}
