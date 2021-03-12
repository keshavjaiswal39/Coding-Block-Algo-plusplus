#include<iostream>
using namespace std;

int Find_zeroes(int n)
{
	int ans=0;
	for(int D=5;n/D>=1;D=D*5)
	{
		ans+=n/D;
	}
	return ans;
}


int main()
{
	long long int num;
	cin>>num;
	cout<<"Number of trailing zeroes in the given factorial of the number is "<<Find_zeroes(num)<<endl;
	return 0;
}
