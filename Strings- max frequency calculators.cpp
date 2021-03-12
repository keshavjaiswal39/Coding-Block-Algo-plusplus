#include<iostream>
using namespace std;

int main()
{
	char s[1000];
	cin.getline(s,100);
	int max;
	char str;
	int H[26]={0};
	for(int i=0;s[i]!='\0';i++)
	{
		H[s[i]%97]++;
	}
	max=0;
	for(int i=0;i<26;i++)
	{
		if(H[i]>max)
		{
			max=H[i];
			str=(char)(i+97);
		}
	}
	cout<<str;
}
