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

void levelOrderBuild(node *&root)
{
	// cout << "Enter the root data"<<endl;
	int d;
	cin>>d;
	
	root=new node (d);
	queue<node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		node *n=q.front();
		q.pop();
	
		int c1,c2;
		// cout<<"Enter the children of"<<n->data<<endl;
		cin>>c1>>c2;
		if(c1!=-1)
		{
			n->left=new node(c1);
			q.push(n->left);
		}
		if(c2!=-1)
		{
			n->right=new node(c2);
			q.push(n->right);
		}
	}
}

void levelOrderPrint(node *root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node *n=q.front();
		if(n==NULL)
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
			cout<<n->data<<" ";
			q.pop();
			
			if(n->left)
			{	
				q.push(n->left);
			}	
			
			if(n->right)
			{
				q.push(n->right);
			}		
		}
	}  
	return;
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

istream& operator>>(istream&is,node * &root)
{
	levelOrderBuild(root);
	return is;
}

ostream& operator<<(ostream&os,node * &root)
{
	levelOrderPrint(root);
	return os;
}

int main()
{
	node *root=NULL;
	
	cin>>root;
	
	int max_level=-1;
	printRightView(root,0,max_level);
	
}



