#include<iostream>
#include<string>
#include<vector>

using namespace std;

int lcs(string s1,string s2,int i,int j,vector<vector<int> > &dp)
{
	// base case
	// if the length of the character is 0
	if(i==s1.length() or j==s2.length())
	{
		return 0;
	}
	
	// check if the state is already computed
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	
	// recursive case
	if(s1[i]==s2[j])
	{
		return dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
	}
	
	//move i to next part and compare it with the 2nd string
	int op1=lcs(s1,s2,i+1,j,dp);
	// move j to next part and compare it with the 1st string
	int op2=lcs(s1,s2,i,j+1,dp);
	
	return dp[i][j]=max(op1,op2);
}

int main()
{
	string s1="ABCD";
	string s2="ABEDG";
	
	int n1=s1.length();
	int n2=s2.length();
	
	vector<vector<int> > dp(n1,vector<int>(n2,-1));   // n1 X n2
	
	cout<<lcs(s1,s2,0,0,dp)<<endl<<endl;
	
	// for having a look at the dp array
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
