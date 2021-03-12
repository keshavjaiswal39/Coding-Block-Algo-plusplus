#include<bits/stdc++.h>
#include<set>

using namespace std;

int main()
{
	set<pair<int,int> > s;
	s.insert(make_pair(10,1));
	s.insert(make_pair(10,5));
	s.insert(make_pair(20,1));
	s.insert(make_pair(20,100));
	s.insert(make_pair(5,1));
	s.insert(make_pair(5,3));
	s.insert(make_pair(5,3));	
	
	// erase (5,3) and replace it with (5,4)
	s.erase(make_pair(5,3));
	s.insert(make_pair(5,4));
	
	for(auto p:s)
	{
		cout<<p.first<<" and "<<p.second<<endl;
	}
	
	cout<<endl;
	cout<<endl;
	
	auto it1=s.upper_bound(make_pair(20,1));
	cout<<" Upper bound for both pair is : "<<it1->first<<" and "<<it1->second<<endl;
	
	auto it2=s.lower_bound(make_pair(20,1));
	cout<<" Lower bound for both pair is : "<<it2->first<<" and "<<it2->second<<endl;

	auto it3=s.upper_bound(make_pair(10,INT_MAX));
	cout<<" Upper bound for left data in the pair is : "<<it3->first<<" and "<<it3->second<<endl;

	auto it4=s.lower_bound(make_pair(10,INT_MAX));
	cout<<" Lower bound for left data in the pair is : "<<it4->first<<" and "<<it4->second<<endl;

	return 0;
}

