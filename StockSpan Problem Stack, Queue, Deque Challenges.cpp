#include<iostream>
#include<stack>
using namespace std;

// Stock Span Problem

void stockSpan(int price[],int n,int span[])
{
	stack<int> s; // indices of the days
	s.push(0);
	
	span[0]=1;
	
	// Loop for rest of the days
	for(int i=1;i<=n-1;i++)
	{
		int currentPrice=price[i];
		// topmost element that is higher than the current price
		while(!s.empty() and price[s.top()]<=currentPrice)
		{
			s.pop();
		}
		
		if(!s.empty())
		{
			int prev_highest=s.top();
			span[i]=i-prev_highest;
		}
		else
		{
			span[i]=i+1;
		}
		// Push the element into the stack
		s.push(i);
	}
	
}

int main()
{
	int prices[10005];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>prices[i];
	}
	int span[100000]={0};
	
	stockSpan(prices,n,span);
	
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}
	cout<<"END";
}






