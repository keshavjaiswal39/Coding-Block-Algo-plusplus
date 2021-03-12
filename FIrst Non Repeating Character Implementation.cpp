#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<char> q;
	int freq[27]={0};
	
	// take a running stream until a '.' as input
	char ch;
	cin>>ch;
	
	while(ch!='.')
	{
		// Our logic will go here
		// Insert in the queue and update the frequency table
		q.push(ch);
		freq[ch-'a']++;
		
		// Query part
		while(!q.empty())
		{
			int index=q.front()-'a';
			if(freq[index]>1)
			{
				q.pop();
			}
			else
			{
				cout<<q.front()<<endl;
				break;
			}
		}
		
		// q is empty
		if(q.empty())
		{
			cout<<"-1"<<endl;
		}	
	
		cin>>ch;
	}
	
	return 0;
}



