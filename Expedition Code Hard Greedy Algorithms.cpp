#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p,pair<int,int> q)
{
	return p.first>q.first;
}
 
int main()
{
	int t,n,x,tx,d,f,D,F,prev=0;
	cin>>t;
	
	while(t--)
	{
		int flag=0,ans=0;
		
		vector<pair<int,int> > v;
		priority_queue<int> pq;
		
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>d>>f;
			v.push_back(make_pair(d,f));
		}
		
		// logic
		sort(v.begin(),v.end(),compare); 
		
		cin>>D>>F;
		
		// Update the distancec of the fuel station from the truck
		for(int i=0;i<n;i++)
		{
			v[i].first=D-v[i].first;
		}
		
		// prev denotes the prev city we have visited
		prev=0;
		x=0;   // current city
		
		while(x<n)
		{
			// if we have enough fuel to go to the next city
			if(F>=v[x].first-prev)
			{
				F=F-(v[x].first-prev);
				pq.push(v[x].second);
				prev=v[x].first;	
			}
			else
			{
				// check if we have some fueling station visited in the priority queue
				if(pq.empty())
				{
					flag=1;
					break;
				}
				
				// other wise we can regfuel the truck with the fuel stations with higher capacity
				F+=pq.top();
				
				// Remove that fuel station from the priority queue
				pq.pop();
				ans=ans+1;
				continue;
			}
			
			x++;
		}
		
		// actually travelled through n fuel stations
		// what is left you have, reach the town from the last fuel station
		
		if(flag==1)
		{
			cout<<-1<<endl;
			continue;
		}
		
		D=D-v[n-1].first;
				
		if(F>=D)
		{
			cout<<ans<<endl;
			continue;
		}
		
		// otherwise
		while(F<D)
		{
			if(pq.empty())
			{
				flag=1;
				break;
			}
			F+=pq.top();
			pq.pop();
			ans=ans+1;
		}
		
		if(flag==1)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<ans;
		
	}
		
		
		
		
}
	

