#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char A[100],largest[100];
	int largest_len=0;
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++)
	{
		cin.getline(A,100);
		int len=0;
		len=strlen(A);
		if(len>largest_len)
		{
			largest_len=len;
			strcpy(largest,A);
		}
	}
		cout<<largest<<largest_len;
}
