#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	int a=1;
	cout<<a<<endl;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=i;j++)
		{
			cout<<++a;
			if(i>2)
			{
			for(k=0;k<i-2;k++)
			{
				cout<<"0";
			}
			}
			cout<<a;
			break;
		}
		cout<<endl;
	}
}
