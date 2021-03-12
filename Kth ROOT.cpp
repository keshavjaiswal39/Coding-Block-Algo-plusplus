#include <iostream>
#include<math.h>
using namespace std;

    
unsigned long long int kthRoot(unsigned long long int n, unsigned long long k)
{
    unsigned long long int s=0,e=n, mid,x;
    while(s<=e)
	{
        mid=(s+e)/2;
        if(pow(mid,k)==n)
		{
            x=mid;
            break;
        }
        if(pow(mid,k)<n)
		{
            s=mid+1;
            x=mid;
        }
		else
		{
            e=mid-1;
        }
    }
    return x;
}


int main() 
{
    int t;
    cin>>t;
    while(t--)
	{    
    	unsigned long long int k;
    	unsigned long long int no;
    	cin>>no>>k;
    	int ans=kthRoot(no,k);
    	cout<<ans<<endl;
    }
    return 0;
}


