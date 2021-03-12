#include<iostream>
using namespace std;

int maxSumSubmatrix(int **arr,int n,int m)
{
//	COlumn wise addition 
	for(int i=n-1;i>=0;i--)
	{
		for(j=m-2;j>=0;j--)
		{
			arr[i][j]+=arr[i][j+1];
		}
	}
//	Row wise addition 
	for(int i=m-1;i>=0;i--)
	{
		for(j=n-2;j>=0;j--)
		{
			arr[j][i]+=arr[j+1][i];
		}
	}
	
	int result=INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			result=max(result,arr[i][j]); // finds the max value in the suffix sub matrix
		}
	}
	
	// main logic remaining , do it yourself
}

int main(int argc,char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int **arr=new int* [n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[m];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<sumOfSubmatrix(arr,n,m)<<endl;
}
