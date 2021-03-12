#include<bits/stdc++.h>
#include<unordered_map>
#include<cstring>

using namespace std;

int main()
{
	unordered_map<string,int> um;
	
	// Insert
	um.insert(make_pair("Mango",100));   // map takes data in a pair 
	
	// or
	pair<string,int> p;
	p.first="Apple";
	p.second=120;
	
	// or
	um.insert(p);
	
	// or
	um["Banana"]=20;
	
	// Search
	string key;
	cin>>key;
	
	unordered_map<string,int>::iterator it=um.find(key);
	//auto it=m.find(key);
	// or
	// unordered_map<string,int>::iterator it=m.find(key);
	
	if(it!=um.end())   // means the key is present in the map
	{
		cout<<"Value of key "<<key<<" is "<<um[key]<<endl;
	}
	else
	{
		cout<<"Key is not in the map"<<endl;
	}
	
	// another way to find a particular key
	// unordered_map has a speacial property that it stores unique keys only once
	
	// if we do
	um["Banana"]=40;
	// this will update the key Banana with the value 40
	cout<<"New value of key "<<key<<" is "<<um["Banana"]<<endl;
	
	// Erase
	um.erase(key);
	cout<<"After deleting the key"<<endl;
	
	if(um.count(key))   
	{
		cout<<"Value of key "<<key<<" is "<<um[key]<<endl;
	}
	else
	{
		cout<<"Key is not in the map"<<endl;
	}
	
	// the only difference between find and count is that, find fn will return an iterator and count will return the count of the particular key
	
	um["Litchi"]=90;
	um["Pineapple"]=75;
	
	// Iterate over all the key value pairs
	for(unordered_map<string,int>::iterator it=um.begin();it!=um.end();it++)
	{
		cout<<it->first<<" -> "<<it->second<<endl;
	}	
	
	cout<<endl<<endl;
	
	// for each loop
	for(auto p:um)
	{
		cout<<p.first<<" : "<<p.second<<endl;
	}
	
}





