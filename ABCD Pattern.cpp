#include<iostream>
using namespace std;

void PrintPattern(int n)
{
	int i,j;
	for(i=5;i>=1;i--)
	{
		char alp='A';
		for(j=1;j<=i;j++)
		{
			cout<<alp;
			alp++;
		}
		cout<<endl;	
	}
}

int main() 
{
	int n;
	cin>>n;
	PrintPattern(n);
}
