#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
	int arr[10005];
	int n,i,val,diff;
	
	while(1)
	{
		// Take input current test case
		int max_load=0,load=0;
		cin>>n;
		
		// Stop taking input if N=-1;
		if(n==-1)
		{
			break;
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			load+=arr[i];
		}
		
		if(load%n!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		
		// find the load that is to be divided equally
		load=load/n;
		
		diff=0;
		// greddy step
		for(int i=0;i<n;i++)
		{
			// find the difference between the final load to be assigned and current load
			diff+=(arr[i]-load);
			int ans=max(diff,-diff);
			max_load=max(max_load,ans);
		}
		cout<<max_load<<endl;
	}
	return 0;
}



