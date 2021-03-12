#include<iostream>
#include<vector>

using namespace std;

bool minHeap=false;  // we want to make maxHeap for minHeap it will be bool minHeap=true;

bool compare(int a,int b)
	{
		if(minHeap)
		{
			return a<b;
		}
		// else its a maxHeap
		else
		{
			return a>b;
		}
	}

void heapify(vector<int> &v,int idx,int size)   // index of the node that has to be heapify
	{
		int left=2*idx;
		int right=2*idx+1;
		
		int min_idx=idx;   // initially min_idx will point to root
		int last=size-1;
		
		if(left<=last and compare(v[left],v[idx]))
		{
			min_idx=left;
		}
		if(right<=last and compare(v[right],v[min_idx]))
		{
			min_idx=right;
		}
		if(min_idx!=idx)
		{
			swap(v[idx],v[min_idx]);
			// recursive call
			heapify(v,min_idx,size);
		}
	}

void buildHeap(vector<int> &v)
{
	for(int i=(v.size()-1)/2;i>=1;i--)
	{
		heapify(v,i,v.size());	
	}	
}

void print(vector<int> v) 
{
	for(int x=1;x<v.size();x++)
	{
		cout<<v[x]<<" ";
	}
	cout<<endl;
}

void heapsort(vector<int> &arr)
{
	buildHeap(arr);
	int n=arr.size();
	
	// remove n-1 elements from the heap
	while(n>1)
	{
		swap(arr[1],arr[n-1]);
		
		// remove that elements fromm the heap
		 
		n--; 
		// n is shrinking but actual size of vector remains same
		
		heapify(arr,1,n);
	}
	
}

int main()
{
	vector<int> v;
	v.push_back(-1);
	
	int n;
	cin>>n;
	
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	
	heapsort(v);
	print(v);
}
