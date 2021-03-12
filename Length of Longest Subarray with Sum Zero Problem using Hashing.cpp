#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int longestLenghtSubarraySum0(int arr[],int n)
{
	unordered_map<int,int> m;
	
	int pre=0;
	int len=0;
	
	for(int i=0;i<n;i++)
	{
		pre+=arr[i];
		// check if the sum was already present in the set
		if(pre==0)
		{
			// if any index value of pre sum is 0, len will be i+1
			len=max(len,i+1);
		}
		// if the element is already present in the map, we find the find the len between 
		// both elements and store the man lenght in the len
		if(m.find(pre)!=m.end())
		{
			len=max(len,i-m[pre]);
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
	cout<<longestLenghtSubarraySum0(arr,n);
	
	
}



