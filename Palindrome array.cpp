#include<iostream>
using namespace std;

bool isPalindrome(int A[],int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		if(A[i]!=A[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

int main() 
{
	int n;
	cin>>n;
	int A[1000];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	if(isPalindrome(A,n))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
	return 0;
}
