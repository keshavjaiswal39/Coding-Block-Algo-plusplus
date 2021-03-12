#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

class Person
{
public:
	string name;
 	int age;

	Person()     // person constructor
	{ 
		
	}
	Person(string n,int a)
	{
		name=n;
		age=a;
	}
	
};

class PersonCompare
{
	public:
		bool operator()(Person A,Person B)
		{
			return A.age<B.age;    // we can change the condition based on the requirement like: return A.age>B.age ot return A.name>B.name and so on
		}
};


int main()
{
	int n;
	cin>>n;
	
	priority_queue<Person, vector<Person>, PersonCompare > pq;    
	// here PersonCompare is not a function, its a class so lets make it as priority queue accepts class not a function
	
	for(int i=0;i<n;i++)
	{
		string name;
		int age;
		
		cin>>name>>age;
		Person p(name,age);
		
		pq.push(p);    // class of name and age is passed in the priority queue
	}
	
	int k;
	cin>>k;
	
	for(int i=0;i<k;i++)
	{
		Person p=pq.top();
		cout<<p.name<<" -- "<<p.age<<endl;
		pq.pop();
	}
	
	return 0;
}






