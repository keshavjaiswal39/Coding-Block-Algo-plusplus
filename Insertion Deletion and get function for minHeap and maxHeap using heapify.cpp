#include<iostream>
#include<vector>

using namespace std;

class Heap
{
	bool minHeap;
	vector<int> v;
	
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
	
	void heapify(int idx)   // index of the node that has to be heapify
	{
		int left=2*idx;
		int right=2*idx+1;
		
		int min_idx=idx;   // initially min_idx will point to root
		int last=v.size()-1;
		
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
			heapify(min_idx);
		}
	}
	
	public:
		Heap(int default_size=10,bool type=true)
		{
			v.reserve(default_size);
			v.push_back(-1);  // 0th index get -1 as it is not useful in the heap
			minHeap=type;
		}
		
		void push(int d)
		{
			v.push_back(d);
			int idx=v.size()-1;
			int parent=idx/2;
			
			// keep pushing to the top till you reach a root node ot stop midway because current element is already greater than parent
			while(idx > 1 and compare(v[idx],v[parent])) 
			{
				swap(v[idx],v[parent]);
				idx=parent;
				parent=parent/2;
			}
		}
		
		int top()
		{
			return v[1];
		}
		
		void pop()
		{
			int last=v.size()-1;
			swap(v[1],v[last]);
			v.pop_back();  //  this deletes the last element
			
			heapify(1);
		}
		
		bool empty()
		{
			return v.size()==1;
		}
};



int main()
{
	// Heap h(10,false);   for the max Heap
	// Heap h(10,true);    for the min Heap
	
	int n;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		h.push(no);
	}
	
	// remove all the element from the heap one by one
	while(!h.empty())
	{
		cout<<h.top()<<" ";
		h.pop();
	}
	
	return 0;
}
