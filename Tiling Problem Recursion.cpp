 #include<bits/stdc++.h>
using namespace std;

int no_of_way(int n)
{
	if(n<=3)
	{
		return 1;
	}
	return no_of_way(n-1)+no_of_way(n-4);
}

int main()
{
	int n;
	cin>>n;
	cout<<"No of Ways we can arrange the brick is: "<<no_of_way(n);
}
