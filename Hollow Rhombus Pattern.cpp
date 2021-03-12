#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<i;j++)
		{
			cout<<" ";
		}
		if(i==n || i==1)
		{
			for(j=1;j<=n;j++)
			{
				cout<<"*";
			}
		}
		else
		{
			cout<<"*";
			for(j=1;j<=n-2;j++)
			{
				cout<<" ";
			}
			cout<<"*";
		}
		cout<<endl;
	}
}
