#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string a,string b)
{
	string ab=a.append(b);
	string ba=b.append(a);
	return ab.compare(ba)>0?1:0;
}

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int n;
		cin>>n;
		string s[100];
		//char str[100];
		cin.get();
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
	
		sort(s,s+n,compare);
	
		for(int i=0;i<n;i++)
		{
			cout<<s[i];
		}
	}
	cout<<endl;
}

