#include<iostream>
#include<set> // it will contain both set and multiset

using namespace std;

typedef multiset<int>::iterator It;

int main()
{
	int arr[]={10,20,30,20,30,30,10,30};
	multiset<int> m(arr,arr+6);
	
	// iterate over the multi set
	for(auto p:m)
	{
		cout<<p<<" ";
	}
	cout<<endl;
	
	// erase a particular element
	m.erase(20);
	
	// iterate over the multi set
	for(auto p:m)
	{
		cout<<p<<" ";
	}
	cout<<endl;
	
	// insert a particular element
	m.insert(80);
	
	// iterate over the multi set
	for(auto p:m)
	{
		cout<<p<<" ";
	}
	cout<<endl;
	
	// find out the count of an element
	cout<<m.count(10)<<endl;
	
	// find the element- using this we get to the first element if its a repeating element
	auto it=m.find(30);
	cout<<(*it)<<endl;
	
	// get all elements which are equal to 30
	// pair<multiset<int> ::iterator,multiset<int> ::iterator> m.equal_range(30);
	
	// or we can use typedef multiset<int>::iterator It  below using namespace std;
	// and our code looks like
	pair<It,It> range =m.equal_range(30);
	
	for(auto it=range.first;it!=range.second;it++)
	{
		cout<<(*it)<<" ";   // this will print all the 30
	}
	cout<<endl;
	
	for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++)
	{
		cout<<(*it)<<" ";
	}
	
	
}
