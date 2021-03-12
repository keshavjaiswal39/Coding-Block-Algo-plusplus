#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number)
{
	for(int x=0;x<n;x++)
	{
		if(mat[x][j]==number || mat[i][x]==number)
		{
			return false;
		}
	}
	
	int rn=sqrt(n);   // rn-root n
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	
	for(int x=sx;x<sx+rn;x++)
	{
		for(int y=sy;y<sy+rn;y++)
		{
			if(mat[x][y]==number)
			{
				return false;
			}
		}
	}
	return true;	
}

bool solveSudoku(int mat[][9],int i,int j,int n)
{
	// Base case
	if(i==n)
	{
		// Print the matrix-solution
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		
		return true;
	}
	
	// Case for the row end
	if(j==n)
	{
		return solveSudoku(mat,i+1,0,n);
	}
	
	// Skip the prefilled cell
	if(mat[i][j]!=0)
	{
		return solveSudoku(mat,i,j+1,n);
	}
	
	
	
	
	// Recursice case
	// fill the current cell with the possible options
	for(int number=1;number<=9;number++)
	{
		if(canPlace(mat,i,j,n,number))
		{
			// Assume 
			mat[i][j]=number;
			
			bool couldWeSolve=solveSudoku(mat,i,j+1,n);
			if(couldWeSolve==true)
			{
				return true;
			}
		}
	}
	// Backtrack here
	mat[i][j]=0;
	return false;
	
}



int main()
{
	int n;
	cin>>n;
	
	int mat[][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };
	
	solveSudoku(mat,0,0,9);

	return 0;
}

