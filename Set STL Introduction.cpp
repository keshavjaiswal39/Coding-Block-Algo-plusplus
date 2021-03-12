#include<iostream>
#include<set>
using namespace std;


int main()
{
	int arr[]={10,20,11,9,8,11,10};
	int n=sizeof(arr)/sizeof(int);
	
	set<int> s;
	
	// Insert the element of the array in the set
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);   // insert operation in set
	}
	
	// print all the element
	for(set<int> :: iterator it=s.begin();it!=s.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
		
	// delete the elment 
	s.erase(10);
	
	for(set<int> :: iterator it=s.begin();it!=s.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
	
	// or
	auto it=s.find(11);
	s.erase(it);
	
	for(set<int> :: iterator it=s.begin();it!=s.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
	 
	
}
