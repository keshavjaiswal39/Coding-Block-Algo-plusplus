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

node *buildTree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	{
		return NULL;
	}
	node *root=new node(d);
	
	root->left=buildTree();
	root->right=buildTree();
	return root;
	
}
 
void printRightView(node *root,int level,int &max_level)
{
	if(root==NULL)
	{
		return;
	}
	
	if(max_level<level)
	// this means we have discovered the new level
	{
		cout<<root->data<<" ";
		max_level=level;
	}
	// otherwise traverse to right first
	printRightView(root->right,level+1,max_level);
	
	// and then traverse to left
	printRightView(root->left,level+1,max_level);
	
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
			cout<<f->data<<" ";
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
	return ;
	
}

int main()
{
	node *root=buildTree();
	
	// take input the tree
	bfs(root);
	cout<<endl;
	
	int max_level=-1;
	printRightView(root,0,max_level);
	
}






