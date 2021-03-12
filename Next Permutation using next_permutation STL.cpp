#include<iostream>
#include<algorithm>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int A[1000];
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		next_permutation(A,A+n);
		for(int i=0;i<n;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
