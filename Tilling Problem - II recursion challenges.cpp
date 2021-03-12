 #include<bits/stdc++.h>
using namespace std;

int no_of_way(int n,int m)
{
	if(n<m)
	{
		return 1;
	}
	return no_of_way(n-1,m)+no_of_way(n-m,m);
}

int main()
{
int t;
cin>>t;
while(t--)
	{
		int n,m;
		cin>>n>>m;
		cout<<no_of_way(n,m)<<endl;
	}
}
