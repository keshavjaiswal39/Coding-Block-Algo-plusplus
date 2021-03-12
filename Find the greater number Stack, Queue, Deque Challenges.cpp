#include<iostream>
#include<stack>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	int a[10000];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	stack <int> s;
	s.push(a[0]);
	
	int i;
	for(i=1;i<n;i++)
	{
		if(!s.empty() && s.top()<a[i])
		{
			cout<<a[i]<<" ";
			s.pop();
		}
		else
		{
			cout<<"-1 ";
			s.pop();
		}
		s.push(a[i]);
	}
	
	if(s.top()<a[0])
	{
		cout<<a[0];
	}
	else
	{
		cout<<"-1";
	}
	s.pop();
}
