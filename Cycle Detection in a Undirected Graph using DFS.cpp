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
		
		void addEdges(int x,int y,bool directed=true)
		{
			l[x].push_back(y);
			
			if(!directed)
			{
				l[y].push_back(x);
			}
		}
		
		bool cycle_helper(int node,bool *visited,int parent)
		{
			visited[node]=true;
			
			for(auto nbr:l[node])
			{
				// two cases
				if(!visited[nbr])
				{
					// go and recursively visit the neighbour
					bool cycle_mila=cycle_helper(nbr,visited,node);
					
					if(cycle_mila)
					{
						return true;
					}
					else
					{
						return false;
					}
					
				}
				
				else if(nbr!=parent)
				{
					return true;
				}
			}
			
			
		}
		
		bool contains_cycle()
		{
			// check for the cycle in an undirected graph
			bool *visited=new bool[V];
		
			for(int i=0;i<V;i++)
			{
				visited[i]=false;
			}
			
			cycle_helper(0,visited,-1);
			
		}
};



int main()
{
	Graph g(7);
	
	g.addEdges(0,1);	
	g.addEdges(1,2);
	g.addEdges(2,3);
	g.addEdges(3,4);
	//g.addEdges(4,0);

	
	if(g.contains_cycle())
	{
		cout<<"Contains a Cycle";
	}
	else
	{
		cout<<"Does not contain a Cycle";
	}
	
	 
}




