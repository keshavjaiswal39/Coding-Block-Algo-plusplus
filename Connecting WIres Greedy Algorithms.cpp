#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	
	int w[1000],b[1000];
	
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	sort(w,w+m);
	sort(b,b+n);
	
	int total_wire=0;
	
	for(int i=0;i<max(m,n);i++)
	{
		total_wire+=b[i]-w[i];
	}
	
	cout<<total_wire;
}
