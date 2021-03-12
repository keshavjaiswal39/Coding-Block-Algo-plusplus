#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<j;
		}
		for(k=i+1;k<=n;k++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
}
