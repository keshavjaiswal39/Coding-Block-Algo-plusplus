#include<bits/stdc++.h>
using namespace std;

void dnf_Sort(int a[],int n)
{
	int lo=0;
	int mid=0;
	int hi=n-1;
	
	while(mid<=hi)
	{
		if(a[mid]==0)
		{
			swap(a[mid],a[lo]);
			mid++;
			lo++;
		}
		if(a[mid]==1)
		{
			mid++;
		}
		if(a[mid]==2)
		{
			swap(a[mid],a[hi]);
			hi--;
		}
	}
}

int main()
{
	int a[]={2,1,1,1,1,0,0,1,1,1,1,0,0,2,0};
	int n=sizeof(a)/sizeof(int);
	dnf_Sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
