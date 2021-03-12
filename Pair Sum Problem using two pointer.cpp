#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,n,key,a[i];
	cout<<"Enter the number of element you want: "<<endl;
	cin>>n;
	cout<<"Enter the elements: "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the key the the elements sum pair has to be: "<<endl;
	cin>>key;
	i=0;
	j=n-1;
	sort(a,a+n);
	while(i<j)
	{
		if(a[i]+a[j]==key)
		{
			cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
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
