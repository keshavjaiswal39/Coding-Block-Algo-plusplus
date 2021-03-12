#include<iostream>
#include<climits>
using namespace std;

void NewMatrix(int A[1000],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=A[i]*(-1);
	}
}

int findMax(int A[1000],int n)
{
	int i;
	int max=INT_MIN;
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
		{
			max=A[i];
		}
	}
	return max;
}

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{	
		int n,a[1000],i;
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		// finding the kadane of the array
		
		int cs1=0;
		int kadane_1=0;

		for(i=0;i<n;i++)
		{
			cs1+=a[i];
			if(cs1<0)
			{
				cs1=0;
			}
			kadane_1=max(cs1,kadane_1);
		}
		
		if(kadane_1==0)
			kadane_1=findMax(a,n);
//		cout<<kadane_1<<endl;
		
		//initial sum of the array
		int init_sum=0;
		for(i=0;i<n;i++)
		{
			init_sum+=a[i];
		}
//		cout<<init_sum<<endl;
		
		//invert the matrix by multiplying -1
		NewMatrix(a,n);
		
		// finding the kadane of the inverted array
		
		int cs2=0;
		int kadane_2=0;

		for(i=0;i<n;i++)
		{
			cs2+=a[i];
			if(cs2<0)
			{
				cs2=0;
			}
			kadane_2=max(cs2,kadane_2);
		}
		
		if(kadane_2==0)
			kadane_2=findMax(a,n);
//		cout<<kadane_2<<endl;
		
		int current_sum=0;
		current_sum=init_sum+kadane_2;
//		cout<<current_sum<<endl;
		
		if((current_sum>kadane_1) && (current_sum!=0))
		{
			cout<<current_sum<<endl;
		}
		else
		{
			cout<<kadane_1<<endl;
		}
	}
}
