#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare(string a,string b)
{
	if(a.find(b))
	{	
		return a<b;
	}
	else  if(b.find(a))
	{
		return a>b;
	}
	else return a<b;
}

int main()
{
	int n;
	cin>>n;
	string s[1000];
	cin.get();
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}
	sort(s,s+n,compare);  // If we want to sort according to the requirements.
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
}


/*
void sort(string a [],int n,bool compare)
{
	for(int itr=1;itr<n;itr++)
	{
		for(int i=0;i<=n-itr-1;i++)
		{
			if(a[i]>a[i+1])
			{
 				swap(a[i],a[i+1]);	
			}
		}
 	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
*/
