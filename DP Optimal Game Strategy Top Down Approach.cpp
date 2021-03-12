#include<iostream>
using namespace std;

int MaxMargin(int arr[],int i,int j)
{
	int dp[100][100]={0};
	// base case
	if(i>j)
	{
		return 0;
	}
	
	// recursive case
	// look out case
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	
	int sum=0;
	int op1=arr[i]+min(MaxMargin(arr,i+2,j),MaxMargin(arr,i+1,j-1));
	int op2=arr[j]+min(MaxMargin(arr,i,j-2),MaxMargin(arr,i+1,j-1));
	
	return dp[i][j]=max(op1,op2);
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<MaxMargin(a,0,n-1);
	
}
