#include<iostream>
using namespace std;

void Wave_Array(int A[][10],int m,int n)
{
	int row,col;
	for(col=0;col<n;col++)
	{
		if(col%2==0)
		{
			for(row=0;row<m;row++)
			{
				cout<<A[row][col]<<", ";
			}
		}
		else
		{
			for(row=m-1;row>=0;row--)
			{
				cout<<A[row][col]<<", ";
			}
		}
	}
	cout<<"END";
}

int main()
{
	int i,j,m,n;
	cin>>m>>n;
	int A[10][10];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	Wave_Array(A,m,n);
}
