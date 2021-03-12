#include<iostream>
using namespace std;

int main()
{
	int i,j,k;
	int n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<j<<"\t";
		}
		for(k=1;k<=2*n-1-2*i;k++)
		{
			cout<<" "<<"\t";
		}
		if(i==n)
		{
			for(j=i-1;j>=1;j--)
			{
				cout<<j<<"\t";
			}
		}
		else
		{
			for(j=i;j>=1;j--)
			{
				cout<<j<<"\t";
			}
		}
		cout<<endl;
	}
}
