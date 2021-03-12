#include<iostream>
using namespace std;

int main() 
{
	int i,j=1,n1,n2;
	cin>>n1>>n2;
	for(i=0;i<n1;i++)
	{
		int sum=0;
		sum=3*j+2;
		if((sum)%n2!=0)
		{
			cout<<sum<<endl;
		}
		else
		{
			n1++;
		}
		j++;
	}
}
