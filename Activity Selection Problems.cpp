#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b)
{
	return a.second<b.second;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b;
		pair<int ,int>arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			arr[i]=make_pair(a,b);
		}
		sort(arr,arr+n,compare);
		int count=1;
		int chosen=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i].first>=arr[chosen].second)
			{
				count++;
				chosen=i;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
