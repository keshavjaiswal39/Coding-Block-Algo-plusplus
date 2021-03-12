#include<iostream>
using namespace std;

bool canGiveScholarship(long long int n,long long int m,long long int x,long long int y,long long int mid)
{
	if(mid*x<=m+(n-mid)*y)
	{
		return true;
	} 
	return false;
}

int main() 
{
	long long int n,m,x,y;
	cin>>n>>m>>x>>y;
	long long int s=0;
	long long int e=n;
	long long int ans=0;
	while(s<=e)
	{
		long long int mid=(s+e)/2;
		bool scholarshipmilega=canGiveScholarship(n,m,x,y,mid);
		if(scholarshipmilega)
		{
			s=mid+1;
			ans=mid;
		}
		else
		{
			e=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
