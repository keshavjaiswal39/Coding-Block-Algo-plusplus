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
		
		void bfs(T src)
		{
			map<T,int> visited;
			queue<T> q;
			
			q.push(src);
			visited[src]=true;
			
			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				
				cout<<node<<" ";
				
				for(int nbr:l[node])
				{
					if(!visited[nbr])
					{
						q.push(nbr);
						// mark that nbr as visited
						visited[nbr]=true;
						
					}
				}	
			}
		}

};

int main()
{
	Graph<int> g;
	g.addEdges(0,1);
	g.addEdges(1,2);
	g.addEdges(2,3);
	g.addEdges(3,4);
	g.addEdges(4,5);
	
	g.bfs(1);
	
	return 0;
}







