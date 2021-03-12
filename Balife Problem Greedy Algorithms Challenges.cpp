#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
	int arr[100005];
	int flag=0;
	long long int n,i,val,diff;
	
	// Take input current test case
	long long int max_load=0,load=0;
	cin>>n;
	
	// Stop taking input if N=-1;
	
	for(long long int i=0;i<n;i++)
	{
		cin>>arr[i];
		load+=arr[i];
	}
	
	if(load%n!=0)
	{
		flag=1;
	}
	
	// find the load that is to be divided equally
	load=load/n;
	
	diff=0;
	
	// greddy step
	for(long long int i=0;i<n;i++)
	{
		// find the difference between the final load to be assigned and current load
		diff+=(arr[i]-load);
		long long int ans=max(diff,-diff);
		max_load=max(max_load,ans);
	}
	
	if(flag==0)
	{
		cout<<max_load<<endl;
	}
	
	else
	{
		cout<<"-1"<<endl;
	}
	
	return 0;
}



