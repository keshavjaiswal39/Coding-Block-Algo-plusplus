#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int j=0;j<n;j++)
	{
		int num;
		cin>>num;
		int count=0;
		while(num>0)
		{
			int last_bit=(num&1);
			if(last_bit)
			{
				count++;
			}
			num=num>>1;
		}
		cout<<count<<endl;
	}
}
