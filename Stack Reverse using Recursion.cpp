#include<iostream>
#include<stack >
using namespace std;

void insertAtBottom(stack<int> &s,int x)
{
	// base case
	if(s.empty())
	{
		s.push(x);
		return;
	}
	// rec case
	int data=s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(data);
	
}

void reverseStackRecursion(stack<int> &s)
{
	// base case
	if(s.empty())
	{
		return;
	}
	// otherwise
	// pop out the top element and insert it at the bottom of reversed smaller stack
	int x=s.top();
	s.pop();
	reverseStackRecursion(s);
	insertAtBottom(s,x);
	
}

int main()
{
	stack<int> s;
	for(int i=1;i<=5;i++)
	{
		s.push(i);
	}
	reverseStackRecursion(s);
	// loop
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;	
}
