#include<iostream>
using namespace std;

int main() 
{
	int f,c,n,a;
	cin>>f;
	cin>>n;
	cin>>a;
	while(f<=n)
	{
		c=(5*(f-32))/9;
		cout<<f<<" "<<c<<endl;
		f+=a;
	}
}
