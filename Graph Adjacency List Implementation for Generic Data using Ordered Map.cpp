#include<iostream>
#include<list>
#include<map>
#include<cstring>

using namespace std;

class Graph
{
	// Adjacency List
	map <string, list<pair<string,int> > > l;
	
	public:
		void addEdges(string x,string y,bool bidir,int wt)
		{
			l[x].push_back(make_pair(y,wt));
			
			if(bidir)
			{
				l[y].push_back(make_pair(x,wt));
			}
		}
		
		void printAdjList()
		{
			// Iterate over all the keys
			for(auto p:l)
			{
				string city=p.first;
				
				list<pair<string, int> > nbrs=p.second;
				
				cout<<city<<" -> ";
				for(auto nbr:nbrs)
				{
					string dest=nbr.first;
					int dist=nbr.second;
					
					cout<<dest<<" "<<dist<<", ";
				}
				cout<<endl;
			}
		}
	
};

int main()
{
	Graph g;
	g.addEdges("A","B",true,20);
	g.addEdges("B","D",true,40);
	g.addEdges("A","C",true,10);
	g.addEdges("C","D",true,40); 
	g.addEdges("A","D",false,50);
	
	
	g.printAdjList();
}





