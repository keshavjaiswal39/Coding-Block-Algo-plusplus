#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key;
	cout<<"Enter the element which you want to check whether its present or not:"<<endl;
	cin>>key;
	bool present=binary_search(arr,arr+n,key);
	if(present)
	{
		cout<<"The element is present"<<endl;
	}
	else
	{
		cout<<"The element is not present"<<endl;
	}
}
