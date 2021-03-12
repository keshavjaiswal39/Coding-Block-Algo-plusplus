#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int arr[100005];
		unordered_map<int,bool> m;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			m[arr[i]]=true;
		}
		
		int s;
		cin>>s;
		
		for(int i=0;i<s;i++)
		{
			int x;
			cin>>x;
			
			if(m[x]==true)
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		
	}
}
