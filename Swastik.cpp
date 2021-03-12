#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	
	for(i=1;i<=(n/2);i++)
	{
		cout<<"*";
		for(j=1;j<=(n/2)-1;j++)
		{
			cout<<" ";
		}
		if(i==1)
		{
			for(j=1;j<=(n/2);j++)
			{
				cout<<"*";
			}
		}
		cout<<"*";
		cout<<endl;
	}
	
	for(i=1;i<=n;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		
	for(i=1;i<=(n/2);i++)
	{
		
		for(j=1;j<=(n/2);j++)
		{
			if(i==n/2)
			{
				for(j=1;j<=(n/2);j++)
				{
					cout<<"*";
				}
			}
			else
			{
				cout<<" ";
			}
		}
		
		for(j=1;j<=(n/2);j++)
		{
			cout<<"*";
		for(j=1;j<=(n/2)-1;j++)
		{
			cout<<" ";
		}
		cout<<"*";
		}
		
		
		cout<<endl;
	}
}
