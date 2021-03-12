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

node *deleteInBST(node *root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(data<root->data)
	{
		root->left=deleteInBST(root->left,data);
		return root;
	}
	else if(data==root->data)
	{
		// Found the node to delete
		// we have 3 cases
		// 1. Node with 0 children -leaf node
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			return NULL;
		}
		
		// 2. Node with 1 child
		if(root->left!=NULL and root->right==NULL)   // means if it has child in left side
	 	{
			node *temp=root->left;
			delete root;
			return temp;
		} 
		if(root->left==NULL and root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		
		// 3. Node with 2 children
		// in this case we will do replacement with the inorder successor or predessor
		
		node *replace=root->right; // this is with the inorder successor from right sub tree
	
		// we say replace pointer to have the address of the right child of the node that has to be deleted
		// and now we just traverse to left of the replace pointer
		
		while(replace->left!=NULL)
		{
			replace=replace->left;
		}
		
		root->data=replace->data;  // we replace the data of the node that has to be deleted with the data of the inorder successor
		
		// now the inorder successor has to be deleted and it can also have 3 cases
		// the successor can have 0 children, 1 child(in thee left or right) so again 
		// we repeat same for this node
		 
		root->right=deleteInBST(root->right,replace->data);
		
		return root;
	}
	else
	{
		root->right=deleteInBST(root->right,data);
		return root;
	}
}

void preOrder(node *root)
{
	if(root==NULL)
	{
    	return;
 	}
 	
 	cout<<root->data<<" ";
 	preOrder(root->left);
 	preOrder(root->right);
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		node *root=NULL;
	
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			root=insertInBST(root,x);
		}
		
		int m;
		cin>>m;
	
		for(int i=0;i<m;i++)
		{
			int key;
			cin>>key;			
			root=deleteInBST(root,key);
		}
		
		preOrder(root);
		
		cout<<endl;
	}
	
	return 0;
}






