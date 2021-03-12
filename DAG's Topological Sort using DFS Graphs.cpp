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
		void addEdges(T x,T y)
		{
			l[x].push_back(y);
		}
		
		void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering)
		{
			// Recursive function that will traverse the graph
			
			
			visited[src]=true;
			// go to all the neighbours of that node that is not visisted
			
			for(T nbr:l[src])
			{
				if(!visited[nbr])
				{
					dfs_helper(nbr,visited,ordering);
				}
			}
			
			// at this point
			ordering.push_front(src);
			
			return;
			
		}
		
		void dfs()
		{
			map<T,bool> visited;
			list<T> ordering;
			
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
					dfs_helper(node,visited,ordering);
					
				}
			}
			
			// finally print the list
			for(auto node:ordering)
			cout<<node<<endl;
		}
};
 

int main()
{
	Graph<string> g;
	
	g.addEdges("Python","DataProcessing");
	g.addEdges("Python","PyTorch");
	g.addEdges("Python","ML");
	g.addEdges("DataProcessing","ML");
	g.addEdges("PyTorch","DL");
	g.addEdges("ML","DL");
	g.addEdges("DL","FaceRecogn");
	g.addEdges("DataSet","FaceRecogn");
	
	g.dfs();
		
}




