#include<iostream>
#include<algorithm>
using namespace std;

int make_change(int *coins,int n,int money)
{
	int ans=0;
	
//	>39 will give index of 50 and then we substract -1 then we get 20	
	// upper_bound(coins, coins + n, money) - 1  will give the address of the money which is just less then it in the coins
	// after getting the address we substract with coins as coins is the base address
	while(money>0)
	{
		int idx=upper_bound(coins, coins + n, money) - 1 - coins;
		cout<<coins[idx]<<" + ";
		money=money-coins[idx];
		ans++;
	}
	
	return ans;
}

int main()
{
	int money;
	cin>>money;
	
	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int t=sizeof(coins)/sizeof(int);
	
	cout<<endl;
	
	cout<<endl<<"Coin needed is: "<<make_change(coins,t,money);
	
	return 0;
}
