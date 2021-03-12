#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int balance(int max,int min)
{
    if(max==min)
    {
        return 0;
    }
    else if(max<min)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int get_meadian(priority_queue<int> &max,priority_queue<int,vector<int>,greater<int>> &min,int &m,int data)
{
    int level=balance(max.size(),min.size());
    switch(level)
    {
        case 0://same size
        if(data<=m)
        {
            max.push(data);
            m=max.top();
        }
        else
        {
            min.push(data);
            m=min.top();
        }
        break;
        case 1://max is greater
        if(data<=m)
        {
            min.push(max.top());
            max.pop();
            max.push(data);
        }
        else
        {
            min.push(data);
        }
        m=(min.top()+max.top())/2;
        break;
        case -1:
        if(data<=m)
        {
            max.push(data);
        }
        else
        {
            max.push(min.top());
            min.pop();
            min.push(data);
        }
        m=(min.top()+max.top())/2;
        break;
    }
    return m;
}
void print_median(int*a,int n)
{
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    int m=0;
    for(int i=0;i<n;i++)
    {
        m=get_meadian(max,min,m,a[i]);
        cout<<m<<" ";
    }
    return;
}
int main() 
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin>>n;
        int a[10000];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        print_median(a,n);
        cout<<endl;
    }
	return 0;
}
