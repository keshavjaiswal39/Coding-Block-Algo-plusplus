#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(i%2==0)
			{
				cout<<"1";
				for(k=0;k<i-2;k++)
				{
					cout<<"0";
				}
				cout<<"1";
				break;
			}
			else
			{
				cout<<"1";
			}
		}
		cout<<endl;
	}
}
