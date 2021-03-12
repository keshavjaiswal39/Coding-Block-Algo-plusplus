#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

class Student
{
	public:
		string firstname;
		string lastname;
		string rollno;
		
		Student(string f,string l,string no)
		{
			firstname=f;
			lastname=l;
			rollno=no;
		}
		
		// lets define the operator
		bool operator ==(const Student &s) const
		{
			rollno == s.rollno?true:false;
 		}
};

class HashFn
{
	public:
		size_t operator()(const Student &s) const
		{
			return s.firstname.length()+s.lastname.length();
		}
};


int main()
{
	unordered_map<Student,int,HashFn> student_map;
	
	Student s1("Prateek","Narang","010");
	Student s2("Rahul","Kumar","023");
	Student s3("Rahul","Kumar","030");
	Student s4("Prateek","Gupta","120");
	
	// Add student- marks to the hasmap
	student_map[s1]=100;
	student_map[s2]=120;
	student_map[s3]=11;
	student_map[s4]=45;
	
	// iterate over all elements
	for(auto s:student_map)
	{
		cout<<s.first.firstname<<" "<<s.first.lastname<<" -> "<<s.first.rollno<<" -> "<<s.second<<" marks"<<endl;
	}
	
	return 0;
}





