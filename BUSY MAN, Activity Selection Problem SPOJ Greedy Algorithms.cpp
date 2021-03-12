#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second<p2.second;
}

int main()
{
	int t,n,s,e;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		vector<pair<int,int> > v;
		 
		for(int i=0;i<n;i++)
		{
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}
		
		// Activity Selection Problem
		
		// Sort according to the finish time	
		sort(v.begin(),v.end(),compare);
		
		// start picking the activities
		int res=1;
		int fin=v[0].second;   // finish time of the first activity
		
		// iterate over the remaining activites
		for(int i=1;i<n;i++)
		{
			if(v[i].first>=fin)   // ith element's start has to be greater than or equal to the prev selected activity's end time
			{
				fin=v[i].second;
				res++;
			}
		}
		cout<<res<<endl;
		v.clear();	
	}
}
