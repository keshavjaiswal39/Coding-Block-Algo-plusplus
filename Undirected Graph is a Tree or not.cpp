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
		
		bool is_tree()
		{
			bool *visited=new bool[V];
			int *parent=new int[V];
			
			queue<int> q;
			
			for(int i=0;i<V;i++)
			{
				visited[i]=false;
				parent[i]=i;
			}
			
			int src=0;
			
			q.push(src);
			visited[src]=true;
			
			// pop out one node and visit its neighbours
			while(!q.empty())
			{
				int node =q.front();
				q.pop();
				
				for(int nbr:l[node])
				{
					if(visited[nbr]==true and parent[node]!=nbr)
					{
						return false;
					}
					else if(!visited[nbr])
					{
						visited[nbr]=true;
						parent[nbr]=node;
						q.push(nbr);
					}
				}
			}
			return true;
			
		}
};


int main()
{
	Graph g(6);
	
	g.addEdges(0,1);
	g.addEdges(3,2);
	g.addEdges(1,2);
//	g.addEdges(0,3);
	
	if(g.is_tree())
	{
		cout<<"Is a Tree";
	}
	else
	{
		cout<<"Is not a Tree";
	}
	
	return 0;
}




