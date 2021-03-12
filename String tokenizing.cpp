#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[100];
	char *ptr=strtok(s," ");
	cout<<ptr;
	while(ptr!=NULL)
	{
		ptr=strtok(NULL," ");
		cout<<ptr<<endl;
	}
	return 0;
}
