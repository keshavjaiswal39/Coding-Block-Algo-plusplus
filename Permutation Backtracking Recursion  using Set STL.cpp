#include<bits/stdc++.h>
#include<set>
#include<string>
using namespace std;

void permutation(char *in,int i,set<string> &s)
{
	// Base case
	if(in[i]=='\0')
	{
		//cout<<in<<", ";
		string t(in);  // string t and initialize string from array a[] that is the current output
		s.insert(t);  // Push the string in the set s.
		return;
	}
	
	// Recursive case
	for(int j=i;in[j]!='\0';j++)
	{
		swap(in[i],in[j]);
		permutation(in,i+1,s);
		
		// Backtracking to restore the original array
		swap(in[i],in[j]);
	}
	 
}

int main()
{
	char in[100];
	cin>>in;
	set<string> s;
	
	permutation(in,0,s);
	
	for(auto str:s)
	{
		cout<<str<<", ";
	}
	
	return 0;
}
