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
	cout<<"Which element you want to find out?"<<endl;
	int key;
	cin>>key;
	auto *it= find(arr,arr+n,key);
	int index=it-arr;
	cout<<"Element found at index "<<index;
	return 0;
}
