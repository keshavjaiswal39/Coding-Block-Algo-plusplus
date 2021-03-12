#include<iostream>
using namespace std;

int main()
{
	int i,j,k,l,a;
	int n;
	cin>>n;
	for(i=n;i>=0;i--)
	{
		for(j=n;j>=i;j--)
		{
			cout<<j<<" ";
		}
		for(k=1;k<=2*i-1;k++)
		{
			cout<<"  ";
		}
		if(i==0)
		{
			for(l=j+2;l<=n;l++)
			{
				cout<<l<<" ";
			}
		}
		else
		{
			for(l=j+1;l<=n;l++)
			{
				cout<<l<<" ";
			}
		}
		cout<<endl;
	}
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		{
			cout<<j<<" ";
			a=j;
		}
		for(k=1;k<=2*i-1;k++)
		{
			cout<<"  ";
		}
		if(i==n)
		{
			for(j=a;j<=n;j++)
			{
				cout<<j<<" ";
			}
		}
		else
		{
			for(j=a;j<=n;j++)
			{
				cout<<j<<" ";
			}
		}
		cout<<endl;
	}
	
}
