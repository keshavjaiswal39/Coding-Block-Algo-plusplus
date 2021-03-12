/*  

Input:  

10

Output: 

1
1 1
1 1 1
1 0 0 1
1 1 1 1 1
1 0 0 0 0 1
1 1 1 1 1 1 1
1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1

*/


#include<iostream>
using namespace std;

int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(j=0;j<i;j++)
			{
				cout<<"1 ";
			}
		}
		else
		{
			cout<<"1 ";
			for(j=0;j<i-2;j++)
			{
				cout<<"0 ";
			}
			cout<<"1";
		}
		cout<<endl;
	}
}
