#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[1000];
	cin.getline(s,100);
	int max;
	char str;
	int H[26]={0};
	if (strlen(s) == 0)
    {
        cout<<"";  
    }
	int i=0;
	int j=1;
	while(i<j && j<=strlen(s))
	{
		int count=1;
		while(s[i]==s[j])
		{
			count++;
			i++;
			j++;
		}
		cout<<s[i];
		cout<<count;
		i++;j++;
	}
}
