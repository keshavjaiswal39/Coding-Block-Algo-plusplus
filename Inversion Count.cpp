#include<bits/stdc++.h>
using namespace std;


int merge(int *a,int s,int e)
{
	int mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	
	int temp[10005];
	int count=0;
	while(i<=mid && j<=e)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			count+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
	{
		temp[k++]=a[j++];
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=temp[i];
	}
	return count;
}


int inversion_count(int *arr,int s,int e)
{
	if(s>=e)
	{
		return 0;
	}
	int mid=(s+e)/2;
	int x=inversion_count(arr,s,mid);
	int y=inversion_count(arr,mid+1,e);
	int z=merge(arr,s,e);  // cross inversion
	return x+y+z;
}


int main()
{
	int n;
	int a[10005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<inversion_count(a,0,n-1)<<endl;
	return 0;	
}
