#include<iostream>
using namespace std;

int main()
{
	char a;
	cin>>a;
	if(a>=65 && a<=90)
	{
		cout<<"UPPERCASE";
	}
	else if(a>=97 && a<=122)
	{
		cout<<"lowercase";
	}
	else
	{
		cout<<"Invalid";
	}
}
