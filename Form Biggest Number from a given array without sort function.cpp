#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

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
	
		int i=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[i].append(s[j])<s[j].append(s[i]))
				{
					swap(s[i],s[j]);
				}
			}
		}
	
		for(int i=0;i<n;i++)
		{
			cout<<s[i];
		}
	}
	cout<<endl;
}

