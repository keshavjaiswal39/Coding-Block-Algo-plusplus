#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 100100
#define ll long long int
 
using namespace std;

map<int, int>last; //stores the last position of every integer that occurred in the array.
int a[nn];

bool compare(int a,int b) //sorting by last position
{
    return last[a]<last[b];
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<int>v;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

        if(last.find(a[i])==last.end())
            v.pb(a[i]);

        last[a[i]]=i;
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}



/*
method 2


#include <iostream>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int>m;
bool mycompare(int a , int b)
{ 
    //cout << "Comparing " << a << " and " << b << endl;
  return m[a] < m[b];

}
int main() {
    int n;
    cin >> n;
    int a[n];
     
    for( int i = 0 ; i  < n ;i++)
    {
        cin >> a[i];
       
    }
    vector<int>ans;
    int val = 0;
    for( int i = 0 ; i  < n ; i++)
    {
        if( m.count(a[i]) ) 
        {
            m[a[i]] = ++val;
            
        }
        else
        {
            m[a[i]] = ++val;
           
            ans.push_back(a[i]); // inserting the unique element into the vector
        }
    }
  
    sort(ans.begin() , ans.end() , mycompare );
    for( int i = 0  ;  i  < ans.size() ; i++)
    {
        cout << ans[i] << endl;
    }
 
   return 0;
}

*/

/* method 3


#include <iostream>
#include<map>
#define ll long long int
using namespace std;
int main() {
    map<ll,ll> mp;
    map<ll,ll> ans;
    ll n;
    cin>>n;
    ll arr[n];
    ll val=0;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.count(arr[i]))
        {
            mp[arr[i]]=val++;
        }
        else
        mp[arr[i]]=val++;
    }

    for(auto it =mp.begin();it!=mp.end();it++)
    {
        ans[it->second]=it->first;
    }
    for(auto it =ans.begin();it!=ans.end();it++)
    {
        cout<<it->second<<endl;
    }


}


*/
