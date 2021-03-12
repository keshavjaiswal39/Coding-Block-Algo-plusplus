#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,n,key,a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>key;
	i=0;
	j=n-1;
	sort(a,a+n);
	while(i<j)
	{
		if(a[i]+a[j]==key)
		{
			cout<<a[i]<<" and "<<a[j]<<endl;
			i++;
			j--;
		}
		else if(a[i]+a[j]>key)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}
