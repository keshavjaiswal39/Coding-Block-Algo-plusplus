#include<iostream>
using namespace std;

int main() 
{
	int num,key,count=0,rem;
	cin>>num;
	cin>>key;
	while(num!=0)
	{
		rem=num%10;
		if(rem==key)
		{
			count++;
		}
		num/=10;
	}
	cout<<count;
	return 0;
}
