#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph
{
	map<T,list<T> > l;
	map<T,T> parents;
	
	public:
		void addEdges(int x,int y)
		{
			l[x].push_back(y);
		}
		
		void bfs(T src,T dest)
		{
			map<T,int> dist;
			queue<T> q;
			
			// All other nodes will have int_max
			for(auto node_pair:l)
			{
				T node = node_pair.first;
				dist[node]=INT_MAX;
			}
			
			q.push(src);
			dist[src]=0;
			parents[src]=src;
			
		
			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				
				//cout<<node<<" ";
				
				for(int nbr:l[node])
				{
					if(dist[nbr]==INT_MAX)
					{
						q.push(nbr);
						// mark that nbr as visited
						dist[nbr]=dist[node]+1;
						parents[nbr]=node;
						
					}
				}	
			}
			// Print the dist to dest node
			
			T temp=dest;
			while(temp!=src)
			{
				cout<<temp<<" <-- ";
				temp=parents[temp];
			}
			cout<<src<<endl;
			
			
			cout<< dist[dest];
		}

};


int main()
{
	// Input
	
	int board[50]={0};
	
	// Snake // Ladders
	
	board[2]=13;   // +ve value means its a ladder which is in 13 step from 2 i.e we reach 15    
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;  // -ve means its a snake which will take us from 17 to 17-13 (4)
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;
	
	// Add all edges to the Graph
	
	Graph<int> g;
	
	for(int i=0;i<=36;i++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int j=i+dice;
			j+=board[j];
			
			if(j<=36)
			{
				g.addEdges(i,j);
			}
		}
	} 
	
	g.addEdges(36,36);

	g.bfs(0,36);
	
	return 0;
}
