#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph
{
	list<int> *l;
	int V;
	
	public:
		Graph(int V)
		{
			this->V=V;
			l=new list<int>[V];
		}
		
		void addEdges(int x,int y)
		{
			// directed graph
			l[x].push_back(y);
		}
		
		void topological_sort()
		{
			// indegree
			int *indegree=new int[V];
			
			// 0 indegree
			for(int i=0;i<V;i++)
			{
				indegree[i]=0;
			}
			
			// update the indegree by traversing edges x->y
			// indegree[y]++
			
			for(int i=0;i<V;i++)
			{
				for(auto y:l[i])
				{
					indegree[y]++;
				}
			}
			
			// bfs
			queue<int> q;
			
			// step 1. Find the node with the 0 indegree
			for(int i=0;i<V;i++)
			{
				if(indegree[i]==0)
				{
					q.push(i);
				}
			}
			
			// start removing the element from the queue
			while(!q.empty())
			{
				int node=q.front();
				cout<<node<<" ";
				q.pop();
				
				// Iterate over neighbours of that node and reduce their indegree by 1
				for(auto nbr:l[node])
				{
					indegree[nbr]--;
					if(indegree[nbr]==0)
					{
						q.push(nbr);
					}
				}	
			}
		}
};


int main()
{
	Graph g(6);
	
	g.addEdges(0,2);
	g.addEdges(1,2);
	g.addEdges(1,4);
	g.addEdges(2,3);
	g.addEdges(2,5);
	g.addEdges(1,4);
	g.addEdges(4,5);
	
	g.topological_sort();
}




