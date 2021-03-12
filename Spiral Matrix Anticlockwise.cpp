#include<iostream>
using namespace std;

void Spiral_print(int A[][10],int m,int n)
{
	int i;
	int start_row=0;
	int start_col=0;
	int end_row=m-1;
	int end_col=n-1;
	
	while(start_row<=end_row && start_col<=end_col)
	{
		for(i=start_row;i<=end_row;i++)
			cout<<A[i][start_col]<<", ";
		start_col++;
		
		for(i=start_col;i<=end_col;i++)
			cout<<A[end_row][i]<<", ";
		end_row--;
		
		if(start_row<=end_row)
		for(i=end_row;i>=start_row;i--)
			cout<<A[i][end_col]<<", ";
		end_col--;
		
		if(start_col<=end_col)
		for(i=end_col;i>=start_col;i--)
			cout<<A[start_row][i]<<", ";
		start_row++;
	}
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
	Spiral_print(A,m,n);
	cout<<"END";
}
