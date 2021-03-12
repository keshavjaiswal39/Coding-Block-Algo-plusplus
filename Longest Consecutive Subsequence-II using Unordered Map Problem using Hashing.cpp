#include<iostream>
#include<unordered_map>

using namespace std;

int finLargestSeq(int arr[],int n)
{
	unordered_map<int,int> m; // number, streak len
	
	for(int i=0;i<n;i++)
	{
		int no=arr[i];
		
		// case 1- if left part and right part are not present
		if(m.count(no-1)==0 and m.count(no+1)==0)  
		{
			m[no]=1;
		}
		// case 2- if left part and right part both are present
		else if(m.count(no-1) and m.count(no+1))
		{
			// 1 2 3 4    6 7 8 9. [5]
			int len1=m[no-1]; // len 1 will be streak len of 4
			int len2=m[no+1]; // len 2 will be streak len of 6
			
			int streak=len1+len2+1; // total len will be len1+len2+1
			m[no-len1]=streak; // update the streak len of 1 as new streak len
			m[no+len2]=streak; // update the streak len of 9 as new streak len
		}
		// case 3- if left part is present and right part is not present
		else if(m.count(no-1) and !m.count(no+1))
		{
			int len=m[no-1]; // 1 2 3   7 8 9. [4]
			// len will be streak len of previous element(3)
			m[no-len]=len+1;  // update the streak len of 1 as len+1
			m[no]=len+1;  // update the streak len of 4 as len+1
		}
		// case 3- if left part is not present and right part is present
		else 
		{
			int len=m[no+1]; // 1 2 3   7 8 9. [6]
			// len will be streak len of after element(7)
			m[no+1]=len+1;  // update the streak len of 9 as len+1
			m[no]=len;  // update the streak len of 6 as len
		}	
	}
	
	int largest=0;
	
	for(auto p:m)   // iterate in the map and find the largest streak
	{
		largest=max(largest,p.second);
	}
	
	return largest;
	
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<finLargestSeq(arr,n);
	
	
	
}
