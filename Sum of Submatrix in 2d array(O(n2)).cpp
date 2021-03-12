#include<iostream>
using namespace std;

int SumSubArrayMatrix(int a[][100],int m,int n)
{
	int tl,br,i,j;
	int sum=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			tl=(i+1)*(j+1);  // contribution of elements in the top left
			br=(m-i)*(n-j);  // contribution of elements in the bottom right
			sum+=a[i][j]*(tl*br);
		}
	}
	return sum;
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
	cout<<"Sum of all the sub matrices is: "<<SumSubArrayMatrix(a,m,n);
}

