#include<iostream>
#include<cstring>
using namespace std;

void Remvoveduplicates(char A[])
{
	int len=strlen(A);
	if(len==0 || len==1)
	{
		return;
	}
	int p=0,q;
	for(q=1;q<len;q++)
	{
		if(A[q]!=A[p])
		{
			p++;
			A[p]=A[q];
		}
	}
	A[p+1]='\0';
}

int main()
{
	char A[100];
	cin.getline(A,100);
	Remvoveduplicates(A);
	cout<<A;
}
