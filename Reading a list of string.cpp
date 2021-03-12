#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char A[100][100];
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++)
	{
		cin.getline(A[i],100);
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
}
