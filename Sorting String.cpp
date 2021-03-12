#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string a,string b)
{
	if(a.length()==b.length())
	{
		return a<b;
	}
	return a.length()<b.length();
}

int main()
{
	int n;
	cin>>n;
	string s[100];
	cin.get();
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}
//	sort(s,s+n);   If we want to sort it lexographically.
	sort(s,s+n,compare);  // If we want to sort according to the requirements.
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
}

