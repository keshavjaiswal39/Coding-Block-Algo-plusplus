#include<bits/stdc++.h>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	map<string,int> m;
	
	// Insert
	m.insert(make_pair("Mango",100));   // map takes data in a pair 
	
	// or
	pair<string,int> p;
	p.first="Apple";
	p.second=120;
	
	// or
	m.insert(p);
	
	// or
	m["Banana"]=20;
	
	// Search
	string key;
	cin>>key;
	
	map<string,int>::iterator it=m.find(key);
	//auto it=m.find(key);
	// or
	// map<string,int>::iterator it=m.find(key);
	
	if(it!=m.end())   // means the key is present in the map
	{
		cout<<"Value of key "<<key<<" is "<<m[key]<<endl;
	}
	else
	{
		cout<<"Key is not in the map"<<endl;
	}
	
	// another way to find a particular key
	// map has a speacial property that it stores unique keys only once
	
	// if we do
	m["Banana"]=40;
	// this will update the key Banana with the value 40
	cout<<"New value of key "<<key<<" is "<<m["Banana"]<<endl;
	
	// Erase
	m.erase(key);
	cout<<"After deleting the key"<<endl;
	
	// we can use a function called count to check if the key is present in the map or not
	// this is an alternative to the find function
	if(m.count(key))   // this will return o or 1, 0 if not there, 1 if its there as map stores only unique key
	{
		cout<<"Value of key "<<key<<" is "<<m[key]<<endl;
	}
	else
	{
		cout<<"Key is not in the map"<<endl;
	}
	
	// the only difference between find and count is that, find fn will return an iterator and count will return the count of the particular key
	
	m["Litchi"]=90;
	m["Pineapple"]=75;
	
	// Iterate over all the key value pairs
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" -> "<<it->second<<endl;
	}	
	
	cout<<endl<<endl;
	
	// for each loop
	for(auto p:m)
	{
		cout<<p.first<<" : "<<p.second<<endl;
	}
	
}




