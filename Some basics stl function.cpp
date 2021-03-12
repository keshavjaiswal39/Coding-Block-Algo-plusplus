#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	cout<<"The max is: "<<max(arr[3],arr[5])<<endl;
	cout<<"The min is: "<<min(arr[3],arr[5])<<endl;
	swap(arr[0],arr[9]);
	swap(arr[2],arr[7]);
	swap(arr[4],arr[5]);
	
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+1);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+2);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+3);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+4);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+5);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+6);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+7);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+8);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+9);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	reverse(arr,arr+10);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}




