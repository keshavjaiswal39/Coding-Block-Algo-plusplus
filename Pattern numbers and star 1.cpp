#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n,a=1;
	cin>>n;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			cout<<j<<" ";
		}
		if(i<=n-1 && i>=1)
		{
			for(k=1;k<=a;k++)
			{
				cout<<"* ";
			}
			a+=2;
		}
		
		cout<<endl;
	}
}
