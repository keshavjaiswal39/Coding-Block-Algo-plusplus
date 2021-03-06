#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(char *in,char *out,int i,int j)
{
	// base case
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	
	// rec case
	// include the current character
	
	out[j]=in[i];
	generate_subsequence(in,out,i+1,j+1);
	
	// exclude the current character
	
	generate_subsequence(in,out,i+1,j);
}

int main()
{
	char input[]="abc";
	char output[10];
	generate_subsequence(input,output,0,0);
}
