#include<iostream>
#include<limits>
using namespace std;


int main()
{
	int arr[1000];
	
	int n;
	cin>>n;
	
	arr[0]=1;
	int carry=0;
	int count=1;
	
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<count;j++)
		{
			int prod=arr[j]*i+carry;
			arr[j]=prod%10;
			carry=prod/10;
		}
		
		while(carry)
		{
			arr[count]=carry%10;
			count++;
			carry/=10;
		}
	}
	
	for(int i=count-1;i>=0;i--)
	{
		cout<<arr[i];
	}
	
}
