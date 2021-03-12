#include<iostream>
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

node *BuildBST(node *root,int data)
{
	if(root==NULL)
	{
		return new node(data);
	}
	
	if(data<=root->data)
	{
		root->left=BuildBST(root->left,data);
	}
	
	else
	{
	    root->right=BuildBST(root->right,data);
	}
	
	return root;
}

void buildtree(node *&root)
{
	int N;
	int data;
	
	cin>>N;
	
	while(N>0)
	{
		cin>>data;
	    root=BuildBST(root,data);
	    N--;
	}
}

void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void nodesInRange(node *root,int k1,int k2)
{
	if(root==NULL)
	{
	    return;
	}
	
	if(k1<root->data)
	{
	    nodesInRange(root->left,k1,k2);
	}
	
	if(k1<=root->data && k2>=root->data)
	{
	    cout<<root->data<<" ";
	}
	
	if(k2>root->data)
	{
	    nodesInRange(root->right,k1,k2);
	}
}

int main() 
{
	int t;
	cin>>t;
	
	int k1,k2;
	
	while(t>0)
	{
	    node *root=NULL;
	
	    buildtree(root);
	
	    cout<<"# Preorder : ";
	
	    preorder(root);
	
	    cin>>k1>>k2;
	
	    cout<<endl;
	
	    cout<<"# Nodes within range are : ";
	
	    nodesInRange(root,k1,k2);

		cout<<endl;
	
	    t--;
	}
	return 0;
}
