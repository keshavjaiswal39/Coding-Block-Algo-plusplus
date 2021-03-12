#include<iostream>
#include<cstring>
using namespace std;

void readLine(char A[],int maxLength)
{
	int i=0;
	char ch=cin.get();
	while(ch!='\n')
	{
		A[i]=ch;
		i++;
		if(i==maxLength-1)
		{
			break;
		}
		ch=cin.get();
	}
	A[i]='\0';
}

void readLineDelim(char A[],int maxLength,char delim)
{
	int i=0;
	char ch=cin.get();
	while(ch!=delim)
	{
		A[i]=ch;
		i++;
		if(i==maxLength-1)
		{
			break;
		}
		ch=cin.get();
	}
	A[i]='\0';
}

int main()
{
	char A[100];
	readLine(A,100);
	cout<<A<<endl<<endl;
	char delim;	
	cin>>delim;
	readLineDelim(A,100,delim);
	cout<<A<<endl;
	
	cin.getline(A,1000,'.');      // we will mostly use this method
	cout<<A<<endl;
}
