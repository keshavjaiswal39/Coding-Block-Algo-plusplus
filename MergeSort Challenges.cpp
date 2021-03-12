#include <iostream>
using namespace std;
#define ll int

void merge(ll a[],ll s,ll e)
{
    ll mid=(s+e)/2;
    ll i=s;
    ll j=mid+1;
    ll k=s;

    ll temp[1000000];

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
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
}
void mergesort(int a[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    ll mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,e);
}
int main() {
    ll a[1000000];
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

