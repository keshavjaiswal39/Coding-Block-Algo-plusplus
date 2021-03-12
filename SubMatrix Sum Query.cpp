#include<iostream>
using namespace std;

void prefixSumMatrix(int a[][100], int m, int n)   // this function will modify my original array to new array which is prefix sum
{
	int i,j;
	for(i=0;i<m;i++)      // First we find the cummulative sum row wise
	{
		for(j=1;j<n;j++)
		{
			a[i][j]+=a[i][j-1];
		}
	}
	
	for(i=1;i<m;i++)      // Then we find the cummulative sum column wise
	{
		for(j=0;j<n;j++)
		{
			a[i][j]+=a[i-1][j];
		}
	}
}

void SumSubArrayMatrix(int a[][100],int m,int n,int tli,int tlj,int bri,int brj)
{
	int li,lj,bi,bj;
	int sum=0;
	for(li=tli;li<=bri;li++)
	{
		for(lj=tlj;lj<=brj;lj++)
		{
			for(bi=li;bi<=bri;bi++)
			{
				for(bj=lj;bj<=brj;bj++)
				{
					if(li-1<0)
					{
						a[li-1][bj]=0;
					}
					if(lj-1<0)
					{
						a[bi][lj-1]=0;
					}
					if(li-1<0 && lj-1<0)
					{
						a[li-1][lj-1]=0;
					}
					sum+=(a[bi][bj]-a[li-1][bj]-a[bi][lj-1])+a[li-1][lj-1];
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
	prefixSumMatrix(a,m,n);
	int tli,tlj,bri,brj;
	cout<<"index from which we want the subarray sum: "<<endl;
	cin>>tli>>tlj;
	cout<<"index to which we want the subarray sum: "<<endl;
	cin>>bri>>brj;
	SumSubArrayMatrix(a,m,n,tli,tlj,bri,brj);
}


	
