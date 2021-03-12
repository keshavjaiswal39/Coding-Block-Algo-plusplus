#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Student
{
public:
	int marks;
	string name;
};

// Bucket Sort to sort the array of elements
void bucket_Sort(Student s[],int n)
{
	// assuming marks to be in the range 0-100
	vector<Student> v[101];
	
	// O(N) time
	for(int i=0;i<n;i++)
	{
		int m=s[i].marks;
		v[m].push_back(s[i]);
	}
	
	// Iterate over the vector and print the statement
	
	for(int i=100;i>=0;i--)
	{
		for(vector<Student>::iterator it=v[i].begin();it!=v[i].end();it++)
		{
			cout<<(*it).marks<<" "<<(*it).name<<endl;
		}
	}
	
}



int main()
{
	Student s[100005];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].marks>>s[i].name;
	}
	bucket_Sort(s,n);
}
