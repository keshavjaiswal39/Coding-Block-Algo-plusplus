#include<bits/stdc++.h>
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

// Accepts the old root node and data and returns the new root node and data
node *insertInBST(node *root,int data)
{
	// base case
	if(root==NULL)
	{
		return new node(data);
	}
	
	// rec case- Insert in the subtree and update the pointers
	if(data<=root->data)
	{
		root->left=insertInBST(root->left,data);
	}
	else
	{
		root->right=insertInBST(root->right,data);
	}
	return root;
}

node *build()
{
	// Read a list of number till -1 and all these numbers will be inserted into BST
	int d;
	cin>>d;
	
	node *root=NULL;
	
	while(d!=-1)
	{
		root=insertInBST(root,d);
		cin>>d;
	}
	return root;	
}

// Print the bfs level by level
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

// Inorder Print
void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool isBST(node *root,int minV=INT_MIN,int maxV=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data>=minV and root->data<=maxV and isBST(root->left,minV,root->data) and isBST(root->right,root->data,maxV))
	{
		return true;
	}
	return false;
}

int main()
{
	node *root=build();
	inorder(root); // Inorder will always give a sorteed array in a Binary Search Tree
	cout<<endl;
	bfs(root);
	
	if(isBST(root))
	{
		cout<<" It is a BST ";
	}
	else
	{
		cout<<" It is not a BST ";
	}
	
	return 0;
}






