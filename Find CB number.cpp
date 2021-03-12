#include<iostream>
#include<string>
using namespace std;

long stoint(string s)
{
	long i=0;
	long j=0;
	while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');  // As ascii value of 0 to 9 is 48 to 57. so when we substract ascii value of 0 from any other number string(0 to 9), we get int value from 0 to 9.
        j++;
    }
    return i;
}

bool is_CB_number(string s)
{
	long long num = stoint(s);  // this converts the string to integer and then it is stored in a variable num which is of long long type. we could also have used stoll() or stoi(), but to know the basics I have mentioned my own function
    
	if (num == 0 || num == 1)   // 0 and 1 are not a CB number
	{
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    // all the above numbers are CB
    
    for(int i=0;i<10;i++)
    {
    	if(num==arr[i])
    	{
    		return true;
		}
	}
	// any number divisible by the above number will not be a CB number
	for(int i=0;i<10;i++)
    {
    	if(num%arr[i]==0)
    	{
    		return false;
		}
	}
	return true;
}

bool is_Valid(bool visited[],int start, int end)
{
	for(int i=start;i<end;i++)
	{
		if(visited[i])
		{
			return false; 
		}
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	long count=0;
	bool * visited = new bool[n];   // we need a array which will contain true or false 
	for(int i=0;i<n;i++)
	{
		visited[i]=false;  // this will make all the value of the array as false
	}
	for(int i=1;i<=s.length();i++)  // i starts from 1 not 0 becuase here i is gonna give us the length of the substring we want each time
	{
		for(int j=0;j<=s.length()-i;j++) // j starts from 0 as this will help us to get the sub string from position j
		{
			int end=i+j;   
			// end is sum of i and j becuse each time this will give us the value till which we want our substring to be. 
			string sub = s.substr(j,i); // Here we will be fnding substring of length i.
			if(is_CB_number(sub) && is_Valid(visited,j,end))
			{
				count++;
				for(int k=j;k<end;k++)
				{
					visited[k]=true;
				}
			}
		}
	}	
	cout<<count<<endl;
}
