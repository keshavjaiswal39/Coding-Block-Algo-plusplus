#include<iostream>
#include<unordered_map>

using namespace std;

int longestSubarrayKSum(int arr[],int n,int k)
{
	unordered_map<int,int> m;
	
	int pre=0;
	int len=0;
	
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		// check if the sum was already present in the set
		if(pre==k)
		{
			// if any index value of pre sum is 0, len will be i+1
			len=max(len,i+1);
		}
		// we will have to check for the presum-k element, mtlb if presum is 6, so check if 6-k is present
		// in the map or not, if present, then the len will be i-m[pre-k]
		if(m.find(pre-k)!=m.end())
		{
			len=max(len,i-m[pre-k]);
		}
		else
		{
			// this will be the case when the number is comming for the first time
			m[pre]=i;
		}
	}
	return len;
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	cout<<longestSubarrayKSum(arr,n,k);
	
	
}
