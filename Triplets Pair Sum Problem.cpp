#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,k,n,key,a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>key;
	i=0;
	j=1;
	k=n-1;
	
	sort(a,a+n);
	
	while(a[i]+a[j]+a[j+1]<=key)
	{
		while(j<k)
		{
			if(a[i]+a[j]+a[k]==key)
			{
				cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
				j++;
				k--;
			}
			else if(a[i]+a[j]+a[k]>key)
			{
				k--;
			}
			else
			{
				j++;
			}
		}
		i++;
		j=i+1;
		k=n-1;
	}
}
