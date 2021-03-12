#include<iostream>
#include<stack >
using namespace std;

void transfer(stack<int> &s1,stack<int> &s2,int n)
{
	for(int i=0;i<n;i++)
	{
		s2.push(s1.top());
		s1.pop();
	}
}

void reverseStack(stack<int> &s1)
{
	stack<int> s2; // Helper Stack
	int n=s1.size();
	for(int i=0;i<n;i++)
	{
		// pick the element at top and insert it at the bottom
		int x=s1.top();
		s1.pop();
		
		// transfer n-i-1 element from stack s1 into s2
		transfer(s1,s2,n-i-1);
		
		// Insert the element x in s1
		s1.push(x);
		
		// transfer n-i-1 element from stack s2 to s2 back
		transfer(s2,s1,n-i-1);
	}
}

int main()
{
	stack<int> s;
	for(int i=1;i<=5;i++)
	{
		s.push(i);
	}
	reverseStack(s);
	// loop
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;	
}
