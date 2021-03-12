#include<iostream>
using namespace std;

bool isSafe(int board[][10],int row,int col,int n)
{
	// you can check for the col
	for(int i=0;i<row;i++)
	{
		if(board[i][col]==1)
		{
			return false;
		}
	}
	
	// you can check for the left diagonal
	int x=row;
	int y=col;
	
	while(x>=0 and y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x--;
		y--;
	}
	
	// you can check for the right diagonal
	x=row;
	y=col;
	
	while(x>=0 and y<n)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x--;
		y++;
	}
	
	// The position is now safe to place queen
	
	return true;
}

bool solveNQueen(int board[][10],int i,int n)
{
	// base case
	if(i==n)
	{
		// you have successfully placed all the queens in n rows(0......n-1)
		// Print the board
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
				{
					cout<<"Q ";
				}
				else
				{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		return true;
	}
	
	// recursive case
	// try to place the queen in the current row and call on the remaining part which will be solve by the recursion
	for(int j=0;j<n;j++)
	{
		// I have to check if i,j th position is safe to place the queen or not
		if(isSafe(board,i,j,n))
		{
			//place the queen - Assuming i,j is the right position
			board[i][j]=1;
			
			bool nextQueenRakhPaye=solveNQueen(board,i+1,n);
			if(nextQueenRakhPaye)
			{
				return true;
			}
			// Means i,j is not the right position - Assumption is wrong
			board[i][j]=0;   // BackTrack
		}
	}
	// You have tried for all the position in the current row but could not place a queen
	return false;

}

int main()
{
	int n;
	cin>>n;
	
	int board[10][10]={0};
	solveNQueen(board,0,n);
	
	
	
	return 0;
}
