#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char A[])
{
	int i=0;
	int j=(strlen(A))-1;
	while(i<j)
	{
		if(A[i]==A[j])
		{
			i++;
			j--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char A[100];
	cin.getline(A,100);  
	if(isPalindrome(A))
	{
		cout<<"Palindromic string";
	}
	else
	{
		cout<<"Not a Palindromic string";
	}
}
