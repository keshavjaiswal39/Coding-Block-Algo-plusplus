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

class LinkedList   // this is pair of head and tail pointer
{
	public:
		node *head;
		node *tail;
};

LinkedList flatten(node *root)
{
	LinkedList l;
	
	// we take a non empty tree
	if(root==NULL)
	{
		l.head=l.tail=NULL;
		return l;
	}
	
	// leaf node
	if(root->left==NULL and root->right==NULL)
	{
		l.head=l.tail=root;
		return l;
	}
	
	// left is not NULL
	if(root->left!=NULL and root->right==NULL)
	{
		LinkedList leftLL=flatten(root->left);
		leftLL.tail->right=root;
		
		l.head=leftLL.head;
		l.tail=root;
		
		return l;
	}
	
	// right is not NULL
	if(root->left==NULL and root->right!=NULL)
	{
		LinkedList rightLL=flatten(root->right);
		root->right=rightLL.head;
		
		l.head=root;
		l.tail=rightLL.tail;
		
		return l;
	}
	
	// Both sides are not NULL
	LinkedList leftLL=flatten(root->left);
	LinkedList rightLL=flatten(root->right);
	
	leftLL.tail->right=root;
	root->right=rightLL.head;
	
	// In tree we have either left or right pointer but in linked list we have next pointer
	// so instead of leftLL.tail->next we write leftLL.tail->right coz to go to next node in postorder
	// we have right pointer as a next pointer
	
	l.head=leftLL.head;
	l.tail=rightLL.tail;
	
	return l;
	
}

int main()
{
	node *root=build();
	inorder(root); // Inorder will always give a sorteed array in a Binary Search Tree
	cout<<endl;
	bfs(root);
	
	LinkedList l=flatten(root);
	node *temp=l.head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<" --> ";
		temp=temp->right;
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;

	return 0;
}






