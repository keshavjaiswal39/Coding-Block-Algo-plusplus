#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, pair<int,int> > node;
// we can also have a class, we have used our custom pair

vector<int> mergeKSortedArrays(vector<vector<int> > arr)
{
	vector<int> result;
	priority_queue<node, vector<node>, greater<node> > pq;
	
	// Insert the 0th element of every array in the pq;
	for(int i=0;i<arr.size();i++)
	{
		pq.push({arr[i][0],{i,0}});    //i->array index, 0 is element index
	}
	
	// remove the element one by one from the min heap and add to the result vector
	while(!pq.empty())
	{
		node current=pq.top();
		pq.pop();
		
		int element =current.first;
		int x=current.second.first;  // row in which the element is present
		int y=current.second.second; // col in which the element is present
		
		result.push_back(element);
		
		// we need to push the next element of the current element x,y+1	
		
		if(y+1<arr[x].size())
		{
			pq.push({arr[x][y+1],{x,y+1}});
		}
	}
	return result;
}

int main()
{
	vector<vector<int> > arr{{2,6,12,15},
	{1,3,14,20},
	{3,5,8,10}};
	
	vector<int> output=mergeKSortedArrays(arr);
	for(auto x:output)
	{
		cout<<x<<" ";
	}
	
	return 0;
}
