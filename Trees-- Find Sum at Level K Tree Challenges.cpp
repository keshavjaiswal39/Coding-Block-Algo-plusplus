#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
 	int data;
 	Node *left;
 	Node *right;
 	
	 Node(int d)
	{
	    data=d;
	    left=NULL;
	    right=NULL;
 	}
};

Node* createTree(Node* root)
{
	int d;
	cin>>d;
	int x;
	cin>>x;
	
	root=new Node(d);
	
	if(x==0)
	{
		return root;
	}
	
	if(x==1)
	{
	    root->left=createTree(root->left);
	    return root;
	}
	
	else
	{
		root->left=createTree(root->left);
    	root->right=createTree(root->right);
    	return root;
	}
}

int printAtLevelK(Node *root,int k)
{
	static int sum=0;
	
	if(root==NULL)
	{
		return sum;
	}
	if(k==0)
	{
		return sum+root->data;
	}	
	
	sum=printAtLevelK(root->left,k-1);
	sum=printAtLevelK(root->right,k-1);
	
	return sum;
}

int main()
{
 	Node *root=NULL;
 
 	root=createTree(root);
 	
 	int k;
	cin>>k;
	
 	cout<<printAtLevelK(root,k);
	
}
