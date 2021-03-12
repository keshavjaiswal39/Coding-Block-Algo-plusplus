#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph
{
	map<T,list<T> > l;
	
	public:
		void addEdges(int x,int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void dfs_helper(T src,map<T,bool> &visited)
		{
			// Recursive function that will traverse the graph
			cout<<src<<" ";
			visited[src]=true;
			
			// go to all the neighbours of that node that is not visisted
			for(T nbr:l[src])
			{
				if(!visited[nbr])
				{
					dfs_helper(nbr,visited);
				}
			}
		}
		
		void dfs()
		{
			map<T,bool> visited;
			// mark all the nodes as not visited in the beginning
			for(auto p:l)
			{
				T node=p.first;
				visited[node]=false;
			}
			
			int cnt=0;
				
			// Iterate over all the vertices and init a dfs call
			for(auto p:l)
			{
				T node =p.first;
				
				if(!visited[node])
				{
					cout<<" Components "<<cnt<<" --> ";
					dfs_helper(node,visited);
					cnt++;
					cout<<endl;
				}
			}
		}
};


int main()
{
	Graph<int> g;
	
	g.addEdges(0,1);
	g.addEdges(0,3);
	g.addEdges(1,2);
	g.addEdges(2,3);
	g.addEdges(0,3);
	g.addEdges(0,4);
	
	g.addEdges(5,6);
	g.addEdges(6,7);

	g.addEdges(8,8);
		
	g.dfs();

	return 0;	
}




