#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<string,vector<string> > phonebook;
	
	phonebook["Rahul"].push_back("9110");
	phonebook["Rahul"].push_back("9112");
	phonebook["Rahul"].push_back("9113");
	phonebook["Rahul"].push_back("9114");
	phonebook["Kajal"].push_back("8112");
	phonebook["Kajal"].push_back("8113");
	phonebook["Kajal"].push_back("8114");
	phonebook["Keshav"].push_back("7111");
	phonebook["Keshav"].push_back("7112");
	
	
	for(auto p:phonebook)
	{
		cout<<"Name : "<<p.first<<" -> ";
		for(string s:p.second)
		{
			cout<<s<<" , ";
		}
		cout<<endl;
	}
	
	string name;
	cin>>name;
	
	if(phonebook.count(name)==0)
	{
		cout<<" Absent"<<endl;
	}
	else
	{
		for(string s:phonebook[name])
		{
			cout<<s<<" , ";
		}
		cout<<endl;
	}
	
}





