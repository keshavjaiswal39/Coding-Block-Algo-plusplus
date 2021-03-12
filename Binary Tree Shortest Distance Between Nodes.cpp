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

node *lca(node *root,int a,int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(root->data==a or root->data==b)
	{
		return root;
	}
	
	// search in the left and right sub tree
	node *leftans=lca(root->left,a,b);
	node *rightans=lca(root->right,a,b);
	
	if(leftans!=NULL and rightans!=NULL)
	{
		return root;
	}
	
	if(leftans!=NULL)
	{
		return leftans;
	}
	
	return rightans;	
}

// finding the level of the given node from the root node or any given node
int search(node *root,int key, int level)
{
	if(root==NULL)
	{
		return -1;
	}
	
	if(root->data==key)
	{
		return level;
	}
	
	int left=search(root->left,key,level+1);
	
	if(left!=-1)
	{
		return left;
	}
	
	return search(root->right,key,level+1);
}

// function to find the distance between two nodes
int findDistance(node *root,int a,int b)
{
	node *lca_node=lca(root,a,b);
	
	int l1=search(lca_node,a,0);
	int l2=search(lca_node,b,0);
	
	return l1+l2;
}
 
int main()
{
	node *root=NULL;
	
	// take input the tree
	cin>>root;   // 1 2 3 4 5 -1 -1 6 7 8 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1 : we are taking level wise
	
	node *target=root->left->left;
	
	// print the tree
	cout<<root<<endl;
	
	int a,b;
	cin>>a>>b;
	
	cout<<findDistance(root,a,b);
	
	return 0;
}






