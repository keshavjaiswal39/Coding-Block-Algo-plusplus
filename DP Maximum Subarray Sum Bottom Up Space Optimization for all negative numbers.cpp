#include<iostream>
#include<limits>
using namespace std;

// Kadane's Algo

int maxSum(int a[],int n)
{
	int current_sum;
	
	if(a[0]>0)
	{
		current_sum=a[0];
	}
	else
	{
		current_sum=0;
	}
	
	int max_so_far=current_sum;
	
	for(int i=1;i<n;i++)
	{
		current_sum=current_sum+a[i];
		
		if(current_sum<0)
		{
			current_sum=0;
		}
		
		max_so_far=max(current_sum,max_so_far);
	}
	
	int max_element=INT_MIN;
	
	if(max_so_far==0) // it means all the element are negative so return the max from it
	{
		for(int i=0;i<n;i++)
		{
			
			max_element=max(a[i],max_element);
		}
		max_so_far=max_element;
	}
	
	return max_so_far;
}

// Special case -> Handle Yourself
// Array contains all -ve elements
// You need output the smallest -ve element!

int main()
{
	int arr[]={-3,-2,-5,-1,-6,-3,-2,-7,-5,-2};
	int n=sizeof(arr)/sizeof(int);
	
	cout<<maxSum(arr,n);
	return 0;
	
}
