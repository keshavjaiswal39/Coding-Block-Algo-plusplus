#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int a,b;
		cin>>a>>b;
		int count=0;
		while(a<=b)
		{
			int temp=a;
			while(temp>0)
			{
				int last_bits=(temp&1);
				if(last_bits)
				{
					count++;
				}
				temp=temp>>1;
			}
			a++;
		}
		cout<<count<<endl;
	}
	return 0;
}
