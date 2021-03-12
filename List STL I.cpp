#include<iostream>
#include<list>
using namespace std;


int main()
{
	list<int> l;
	
	list<int> l1{1,2,3,4,5,6};
	
	// list of different data type
	list<string> l2{"apple","guava","mango","banana"};
	l2.push_back("pineapple");
	
	// sort
	l2.sort();
	
	// reverse the ordering
	l2.reverse();
	
	// pop front
	cout<<l2.front()<<endl;
	l2.pop_front();
	
	// add to the front of the list
	l2.push_front("kiwi");
	
	// pop back
	cout<<l2.back()<<endl;
	l2.pop_back();
	
	// iterator over the list and print the data
	for(auto it=l2.begin();it!=l2.end();it++)
	{
		cout<<(*it)<<" --> ";
	}
	cout<<endl;
	
	for(string s:l2)
	{
		cout<<s<<" --> ";
	}
	
	// Some more function in the list
	l2.push_back("orange");
	l2.push_back("lemon");
	
	cout<<endl;
	
	for(string s:l2)
	{
		cout<<s<<" --> ";
	}
	
	// remove a fruit
	string f;
	cin>>f;
	l2.remove(f);
	
	cout<<endl;
	
	for(string s:l2)
	{
		cout<<s<<" --> ";
	}
	
	// erase one or more elements from the list
	
	auto it=l2.begin();
	it++;
	it++;
	
	l2.erase(it);
	
	cout<<endl;
	
	for(string s:l2)
	{
		cout<<s<<" --> ";
	}
	
	// we can insert elements in the list
	it=l2.begin();
	it++;
	l2.insert(it,"fruit juice");
	
	cout<<endl;
	 
	for(string s:l2)
	{
		cout<<s<<" --> ";
	}
	
}







