// Counting Set Bits Method 3 - using inbuilt function

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<__builtin_popcount(n)<<endl;
}

