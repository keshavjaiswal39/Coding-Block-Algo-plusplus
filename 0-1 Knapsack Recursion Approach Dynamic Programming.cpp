#include<iostream>
using namespace std;

int knapsack(int size_item[],int value[],int weight,int n)
{
	// base condition
	if(n==0 || weight==0)   
	{
		return 0;
	}
	
	// recursive case
	// two option
	// either take a particular item or dont take it
	// will take the max among both
	
	if(size_item[n-1]<=weight)   // if value for the item which we are picking is less than the weight
	{
		// option 1- take that item
		int op1=value[n-1]+knapsack(size_item,value,weight-size_item[n-1],n-1);
		// option 2- dont take that item
		int op2=knapsack(size_item,value,weight,n-1);
		
		return max(op1,op2);
	}
	
	// if the weight is greater than the selected size then we dont take that element

	return knapsack(size_item,value,weight,n-1);

}

int main()
{
	int n;
	cin>>n;
	
	int weight;
	cin>>weight;
	
	int size_item[n];
	int value[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>size_item[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	
	cout<<knapsack(size_item,value,weight,n);
}
