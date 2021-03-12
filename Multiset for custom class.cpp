#include <iostream>
#include <set>
using namespace std;

class person_compare
{
    public:
	    bool operator()(pair<string,int> p1,pair<string,int> p2) // we are going to overlap round brackets
		{
	        return p1.second < p2.second;
	    }
};

int main() 
{
    pair<string,int> p1 = make_pair("B",100);
    pair<string,int> p2 = make_pair("A",40);
    pair<string,int> p3 = make_pair("C",120);
    pair<string,int> p4 = make_pair("D",10);

    //Multiset 
    
    multiset<pair<string,int> > m1;
    m1.insert(p1);
    m1.insert(p2);
    m1.insert(p3);
    m1.insert(p4);
    
    // this will print the element in ordered sequence based in the 1st pair
    for(auto p:m1)
	{
        cout<<p.first<<" - "<<p.second<<endl;
	}
	cout<<endl<<endl;

    // Pair - Name(string), Money(int)

	//this will print the element in ordered sequence based in the 2nd pair
	
    // Custom Data type
    multiset<pair<string,int>, person_compare > m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto p:m)
	{
        cout<<p.first<<" - "<<p.second<<endl;
	}
	cout<<endl<<endl;
	
    return 0;
}

