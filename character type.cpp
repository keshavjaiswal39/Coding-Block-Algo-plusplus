#include<iostream>
using namespace std;

int main()
{
	char a;
	cin>>a;
	if(a>='A' && a<='Z')
	{
		cout<<"U";
	}
	else if(a>='a' && a<='z')
	{
		cout<<"L";
	}
	else
	{
		cout<<"I";
	}
}
