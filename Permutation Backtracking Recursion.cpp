#include<bits/stdc++.h>
using namespace std;

void permutation(char *in,int i)
{
	// Base case
	if(in[i]=='\0')
	{
		cout<<in<<", ";;
		return;
	}
	
	// Recursive case
	for(int j=i;in[j]!='\0';j++)
	{
		swap(in[i],in[j]);
		permutation(in,i+1);
		
		// Backtracking to restore the original array
		swap(in[i],in[j]);
	}
	
}

int main()
{
	char in[100];
	cin>>in;
	permutation(in,0);
	
	return 0;
}
