#include<bits/stdc++.h>
using namespace std;

int stringToInt(string str,int number)
{
	if(str.length()==0)
	{
		return number;
	}
	char ch=str[0];
	int digit=ch-'0';
	string ros=str.substr(1);
	int small_ans=stringToInt(ros,digit);

	return small_ans*10+digit;
}

int main()
{
	string str;
	cin>>str;
	int x=stringToInt(str,0);
	cout<<x<<endl;
}
