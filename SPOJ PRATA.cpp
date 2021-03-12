#include<iostream>
using namespace std;

int PrataMadeByEachCook(int rank,int mid)
{
	int count=0;
	int j=1;
	int prata=rank;
	while(prata<=mid)
	{
		count++;
		j++;
		prata+=rank*j;
	}
	return count;
}

bool isPossibleToCook(int cook[],int mid,int m,int n)
{
	int count=0;
	int a=0;
	for(int i=0;i<m;i++)
	{
		a=PrataMadeByEachCook(cook[i],mid);
		count+=a;
	}
	if(count>=n)
	{
		return true;
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int n;
		cin>>n;
		int s=0;
		int e=n*(n+1)/2;
		int m;
		cin>>m;
		int cook[m];
		for(int i=0;i<m;i++)
		{
			cin>>cook[i];
		}
		int mid,ans=-1;
		while(s<=e)
		{
			mid=(s+e)/2;
			if(isPossibleToCook(cook,mid,m,n))
			{
				ans=mid;
				e=mid-1;
			}
			else
			{
				s=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
