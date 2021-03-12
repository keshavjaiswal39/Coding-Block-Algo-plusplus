#include<iostream>
using namespace std;

void Magical_park(char A[][100],int m, int n, int k,int s)
{
	int i,j;
	bool success=true;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			char ch=A[i][j];
			if(s<k)
			{
				success=false;
				break;
			}
			if(ch=='.')
			{
				s-=2;
			}
			else if(ch=='*')
			{
				s+=5;
			}
			else
			{
				break;
			}
			if(j!=n-1)
			{
				s--;
			}
		}
	}
	if(success)
	{
		cout<<"Yes"<<endl;
		cout<<s;
	}
	else
	{
		cout<<"No"<<endl;
	}
}


int main()
{
	int i,j,m,n,k,s;
	cin>>m>>n>>k>>s;
	char A[100][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	Magical_park(A,m,n,k,s);
	return 0;
}
