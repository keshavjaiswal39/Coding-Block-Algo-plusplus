#include<iostream>
#include<list>

using namespace std;

class Graph
{
	int V;
	// Array of the List
	list<int> *l;
	
	public:
		Graph(int V)
		{
			this->V=V;
			l=new list<int>[V];
		}
		
		void addEdges(int x,int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void printAdjList()
		{
			// Iterate over all the vertices
			for(int i=0;i<V;i++)
			{
				cout<<"Vertex "<<i<<" -> ";
				for(int nbr:l[i])
				{
					cout<<nbr<<", ";
				}
				cout<<endl;
			}
		}
};

int main()
{
	Graph g(4);
	g.addEdges(0,1);
	g.addEdges(0,2);
	g.addEdges(2,3);
	g.addEdges(1,2); 
	
	g.printAdjList();
}





