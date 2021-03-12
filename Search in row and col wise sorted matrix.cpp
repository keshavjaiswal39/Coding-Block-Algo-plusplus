#include<iostream>
#include<algorithm>
using namespace std;

void StairCase(int A[][100],int m,int n,int key)
{
	int i,j,start_row=0,end_col=n-1;
	if(key==A[start_row][end_col])
	{
		cout<<"\nFound at "<<start_row<<" "<<end_col;
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
				cout<<"\nFound at "<<start_row<<" "<<end_col;
				break;
			}
		}
		cout<<"\nNot Found";
	}
}

int main()
{
	int i,j,m,n,key;
	cin>>m>>n>>key;
	int A[100][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	StairCase(A,m,n,key);
}
