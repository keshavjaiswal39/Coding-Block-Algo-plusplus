#include<iostream>
#include<climits>
#include<string>

using namespace std;

string find_window(string s,string pat)
{
	int SL=s.length();
	int PL=pat.length();
	
	// 1. corner case
	if(PL>SL)
	{
		return "None";
	}
	
	// 2. Freq maps
	int FS[256]={0};
	int FP[256]={0};
	
	for(int i=0;i<PL;i++)
	{
		char ch=pat[i];
		FP[ch]++;
	}
	
	int count=0;
	int start=0; // left pointer for shrinking
	int min_len=INT_MAX;
	int start_idx=-1;
	
	// Sliding Window (Expansion and Contraction + Update the min length of the window
	
	for(int i=0;i<SL;i++)
	{
		char ch=s[i];
		FS[ch]++;     // Freq map for the string forming the window
		
		// Maintain the count of characters matched
		if(FP[ch]!=0 and FS[ch] <= FP[ch])
		{
			count++;
		}
		
		// if all the character match
		if(count==PL)
		{
			// we can now start shrinking the window
			char temp=s[start];   // temp will be the starting char of the window
			
			// loop to remove all unwanted characters
			while(FP[temp]==0 or FS[temp]>FP[temp])
			{
				// means either temp is not present in the pattern or
				// frequency of temp is greater in the string than the frequency patter
				// we can reduce its freqeunct in the string and we can move the start pointer
				
				FS[temp]--;
				start++;
				// now temp is the next character
				temp=s[start];
			}
		
			// window size
			int window_len=i-start+1;
			
			if(window_len<min_len)
			{
				min_len=window_len;
				start_idx=start;  // so that we can find the starting character of that window
			}
		}
	}	
	if(start_idx==-1)
	{
		return "Node";
	}
	string ans=s.substr(start_idx,min_len);  // starting index and the total character we want to take from the starting char
	return ans;
}

int main()
{
	
	string s="hellloeaeo world";
	string p="eelo";
	
	cout<<find_window(s,p)<<endl;
	
	return 0;
}
