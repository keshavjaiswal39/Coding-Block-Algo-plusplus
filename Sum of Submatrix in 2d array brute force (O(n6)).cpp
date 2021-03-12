#include<iostream>
using namespace std;

SumSubArrayMatrix(int a[][100],int m,int n)
{
	int li,lj,bi,bj;
	int sum=0;
	for(li=0;li<m;li++)
	{
		for(lj=0;lj<n;lj++)
		{
			for(bi=li;bi<m;bi++)
			{
				for(bj=lj;bj<n;bj++)
				{
					for(int i=li;i<=bi;i++)
					{
						for(int j=lj;j<=bj;j++)
						{
							sum+=a[i][j];
						}
					}
				}
			}
		}
	}
	cout<<"Sum of all the sub matrices is: "<<sum<<endl;
}

int main()
{
	int m,n,a[100][100];
	cin>>m>>n;
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	SumSubArrayMatrix(a,m,n);
}
