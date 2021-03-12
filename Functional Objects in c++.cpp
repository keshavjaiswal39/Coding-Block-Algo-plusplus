#include<iostream>
#include<cstring>
using namespace std;

class Fun
{
	public:
		void operator()(string s)   
		{
			cout<<"Having Fun inside Operator() Fn with "<<s;
		}
		
	/*	void operator()()   
		{
			cout<<"Having Fun inside Operator() Fn with ";
		}    */
};

int main()
{
	Fun f;    // Constructor
//	f();      // overloaded () Operator = Function Call where f is an object
	
	f("C++");   // this looks like a function call
	// this is an functional object and we will be using this to make comparator for priority queue STL class
	
	return 0;
}






