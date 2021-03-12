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
	cout<<"Enter the element for which you want to lower bound and the upper bound:"<<endl;
	cin>>key;
	auto *lb=lower_bound(arr,arr+n,key);
	cout<<lb<<endl;
	cout<<"the index is: "<<(lb-arr)<<endl;
	auto *ub=upper_bound(arr,arr+n,key);
	cout<<ub<<endl;
	cout<<"the index is: "<<(ub-arr)<<endl;
	
	cout<<"The frequency of the given element is: "<<(ub-lb)<<endl;
}
