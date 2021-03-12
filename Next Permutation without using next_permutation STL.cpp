#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void reverse(int A[],int i,int j)
{
	while(i<j)
	{
		swap(&A[i],&A[j]);
		i++;
		j--;
	}
}

int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n;
		cin>>n;
		int A[100];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		// Now we will traverse from back and take two variable i and j where i will be n-2 as we need to compare ith and i+1th element
		// and j will be n-1 as we have to compare it with the selected ith element
		
		int i=n-2;
		int j=n-1;
		
		// 1st step , traverse from last and find out the breaking point i.e if the element decreases after a point
		// for e.g: 1 2 5 4 3 , the breaking point is 2 as from 3 the number keeps on increasing and a[i]>a[i+1] but at 2 it gets decreased
		// i.e a[1]<a[2] , so the breaking point will be index 1.
		
		while(A[i]>A[i+1] && i>=0)
		{
			i--;
		}
		
		if(i<0)
		{
			// this means the the number is in decreasing order and the next permutation will be the reverse of that array.
			// for e.g we have 5 4 3 2 1, here we dont get any break point so atlast we get i=-1.
			// So in this case we will reverse the string from starting position to the end position.
			
			// we can directly use the reverse stl, reverse(arr,arr+n), but here we are gonna make out own function.
			
			reverse(A,i+1,n-1);
		}
		
		else
		{
			// Here we will find for the element which is greater that the a[i] but we will traverse the array from the last.
			// for e.g 1 2 5 4 3, here the break point was 2 so from j=n-1, we will find the element which is greater than 2, and we get 3.
			
			while(A[j]<=A[i])
			{
				j--;
			}
			
			// Now we will swap the a[i] and a[j], we can simply use the swap stl function but here we are gonna use our own function.
			
			swap(&A[i],&A[j]);
			
			// Now we will reverse the element from the index that we got in the first. For e.g. In the 1nd step we go 2 and its
			// index was 1 as given in this array 1 2 5 4 3, and after swapping element of 1st(element=2) and 2nd(element=3) 
			// operation we get: 1 3 5 4 2 so we will reverse from index i+1 and our new array will be: 1 3 2 4 5
		
			reverse(A,i+1,n-1);
		}
		
		// Now we are done, we have got our result.
		// lets just print our array
		
		for(i=0;i<n;i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;	
	}
	return 0;
}
