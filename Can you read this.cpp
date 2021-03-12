#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n;
	n=s.length();
	int i=0;
	cout<<s[i];
	for(i=1;i<=n-1;i++)
	{
		if(s[i]>=97 && s[i]<=122)
		{
			cout<<s[i];
		}
		if(s[i]>=65 && s[i]<=90)
		{
			cout<<endl;
			cout<<s[i];
		}
	}
}



or

/*
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin,s);
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(isupper(s[i]))
			cout<<endl<<s[i];
		if(islower(s[i]))
			cout<<s[i];
	}
	
	return 0;
}
*/
