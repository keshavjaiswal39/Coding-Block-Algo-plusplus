#include<iostream>
#include<algorithm>
using namespace std;

void Rotate_Image(int A[][100],int m)
{
	int i,j,start_col,end_col;
	for(i=0;i<m;i++)
	{
		start_col=0;
		end_col=m-1;
		while(start_col<end_col)
		{
			swap(A[i][start_col],A[i][end_col]);
			start_col++;
			end_col--;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i<j)
			{
				swap(A[i][j],A[j][i]);
			}
		}
	}
	
}


int main()
{
	int i,j,m;
	cin>>m;
	int A[100][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>A[i][j];
		}
	}
	Rotate_Image(A,m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
