#include<iostream>
#include<algorithm>
using namespace std;

int StairCase(int A[][100],int m,int n,int key)
{
	int i,j,start_row=0,end_col=n-1;
	if(key==A[start_row][end_col])
	{
		return 1;
	}
	else
	{
		while(start_row<m && end_col>=0)
		{
			if(key>A[start_row][end_col])
			{
				start_row++;
			}
			else if(key<A[start_row][end_col])
			{
				end_col--;
			}
			else
			{	
				return 1;
			}
		}
		return 0;
	}
}

int main()
{
	int i,j,m,n,key;
	cin>>m>>n;
	int A[100][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	cin>>key;
	cout<<StairCase(A,m,n,key);
}
