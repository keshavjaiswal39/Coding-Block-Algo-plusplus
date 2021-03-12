#include<iostream>
using namespace std;
void add(int a[],int b[],int n,int m)
{
	int i=n-1;
	int j=m-1;
	int carry=0;
	int ans[n];int k=n-1;
	int ad;
	while(j>=0)
	{
		ad=a[i]+b[j]+carry;
		ans[k]=ad%10;
		carry=ad/10;
		i--;j--;k--;
	}
	//2nd array less than 1st
	while(i>=0)
	{
		ad=a[i]+carry;
		ans[k]=ad%10;
		carry=ad/10;
		i--;k--;
	}
	if(carry)
	cout<<carry<<", ";
	for(int x=0;x<n;x++)
	cout<<ans[x]<<", ";
	cout<<"END";
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
	cin>>b[i];
	if(n>=m)
	add(a,b,n,m);
	else
	add(b,a,m,n);
	return 0;
}
