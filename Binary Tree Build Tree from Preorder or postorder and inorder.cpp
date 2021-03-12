#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};

node *buildTreeFromTraversal(int *in,int *pre,int s,int e)
{
	static int i=0;
	
	// base case
	if(s>e)
	{
		return NULL;
	}
	// Recursive case
	node *root=new node(pre[i]);
	
	int index=-1;
	
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	
	i++;
	root->left=buildTreeFromTraversal(in,pre,s,index-1);
	root->right=buildTreeFromTraversal(in,pre,index+1,e);
	
	return root;
}

void bfs(node *root)
{
	queue<node *> q;
	q.push(root);
	q.push(NULL);   // since queue is of node data type we can insert NULL
	
	while(!q.empty())
	{
		node *f=q.front();
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout<<f->data;
			q.pop();
			
			if(f->left)
			{
				q.push(f->left);
			}
			if(f->right)
			{
				q.push(f->right);
			}
		}
	}
	return;	
}

int main()
{
	int in[1000];
	int pre[1000];
	
	int n;
	int m;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>in[i];
	}
	
	node *root=buildTreeFromTraversal(in,pre,0,n-1);
	bfs(root);
	
}






