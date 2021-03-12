#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	for(j=1;j<=n;j++)
	{	
		if(j==1 || j==n)
		{
			for(i=1;i<=n;i++)
			{
				cout<<"*"<<"\t";
			}
			cout<<endl;
		}
		
		else if(j>=2 && j<(n+1)/2)
		{
			for(i=(n+1)/2;i>=j;i--)
			{
				cout<<"*"<<"\t";
				
			}
			for(i=1;i<=2*(j-2)+1;i++)
			{
				cout<<" "<<"\t";	
			}
			for(i=(n+1)/2;i>=j;i--)
			{
				cout<<"*"<<"\t";
			}	
			cout<<endl;
		}
	
		else if(j==(n+1)/2)
		{
			cout<<"*"<<"\t";
			for(i=1;i<=n-2;i++)
			{
				cout<<" "<<"\t";
			}
			cout<<"*"<<"\t";
			cout<<endl;
		}	
		
		else if(j>(n+1)/2 && j<n)
		{
			for(i=1;i<=j/2;i++)
			{
				cout<<"*"<<"\t";
			}
			for(i=1;i<=n-(j/2)*2;i++)
			{
				cout<<" "<<"\t";
			}
			for(i=1;i<=j/2;i++)
			{
				cout<<"*"<<"\t";
			}
			cout<<endl;
		}
	}
}

