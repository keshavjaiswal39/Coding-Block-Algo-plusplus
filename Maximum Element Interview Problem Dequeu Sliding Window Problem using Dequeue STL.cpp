#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n;
	int a[10000];
	int k;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	
	// we have to process the first k element separately
	deque<int> Q(k);
	int i;
	
	for(i=0;i<k;i++)
	{
		while(!Q.empty() and a[i]>a[Q.back()])
		{
			Q.pop_back();
		}
		Q.push_back(i);   // we push the index of the larger element in the deque
	}
	
	// Process the remaining element
	for(;i<n;i++)
	{
		cout<<a[Q.front()]<<" ";
	
		// 1. Remove the elements which are not the part of the window (Contraction)
		while((!Q.empty() and (Q.front()<=i-k)))
		{
			Q.pop_front();
		}
		
		// 2. Remove the element which are not useful and are in window
		while(!Q.empty() and a[i]>=a[Q.back()])
		{
			Q.pop_back();
		}
		
		// 3. Add the new element (Expansion)
		Q.push_back(i);
	}
	
	cout<<a[Q.front()]<<endl;
	
	return 0;
}






