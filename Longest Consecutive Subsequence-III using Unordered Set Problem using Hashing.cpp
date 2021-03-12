#include<iostream>
#include<unordered_set>

using namespace std;

int finLargestSeq(int a[],int n)
{
	unordered_set<int> s;
	
	for(int i=0;i<n;i++)
	{
		s.insert(a[i]);
	}
	
	int max_streak=1;
	
	// iterate over all alements
	// and target those element from which a streak can start
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i]-1)==s.end())   // means the number is not present
		{
			// a[i] is the starting point of a streak
			// we traverse the entire range that is contained in that streak
			int next_no=a[i]+1;
			int streak_len=1;
			
			while(s.find(next_no)!=s.end())   // means the number is prsent
			{
				next_no+=1;
				streak_len+=1;
			
			}
			max_streak=max(streak_len,max_streak);
		}
	}
	return max_streak;
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
