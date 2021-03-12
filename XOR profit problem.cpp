#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y;
	cin>>x>>y;
	int ans_xor;
	int max=0;
	for(int i=x;i<=y;i++)
	{
		for(int j=i;j<=y;j++)
		{
			ans_xor=i^j;
			if(ans_xor>=max)
			{
				max=ans_xor;
			}
		}
	}
	cout<<max;
}
