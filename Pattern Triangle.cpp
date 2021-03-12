#include<iostream>
using namespace std;

int main()
{
	int n,a;
	cin>>n;
	int i,j,k,l;
	for(i=1;i<=n;i++)
	{
		for(k=i;k<n;k++)
		{
			cout<<" "<<"\t";
		}
		for(j=i;j<2*i;j++)
		{
			cout<<j<<"\t";
			a=j;
		}
		for(l=1;l<i;l++)
		{
			cout<<--a<<"\t";
		}
		cout<<endl;
	}
}
