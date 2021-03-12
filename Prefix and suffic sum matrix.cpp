#include<iostream>
using namespace std;

void prefixSumMatrix(int a[][100], int m, int n)
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
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void suffixSumMatrix(int a[][100], int m, int n)
{
	int i,j;
	for(i=m-1;i>=0;i--)      // First we find the cummulative sum row wise
	{
		for(j=n-2;j>=0;j--)
		{
			a[i][j]+=a[i][j+1];
		}
	}
	
	for(i=m-2;i>=0;i--)      // First we find the cummulative sum row wise
	{
		for(j=n-1;j>=0;j--)
		{
			a[i][j]+=a[i+1][j];
		}
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
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
	suffixSumMatrix(a,m,n);
}
