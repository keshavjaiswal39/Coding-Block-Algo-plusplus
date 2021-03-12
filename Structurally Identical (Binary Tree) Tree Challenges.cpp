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

bool areTreesStructurallyIdentical(Node *root1, Node *root2) 
{
	if(root1==NULL and root2==NULL) 	
	{
    	return true;
	}
	
	if(root1!=NULL and root2!=NULL) 	
	{
    	int leftAns = areTreesStructurallyIdentical(root1->left, root2->left);
    	int rightAns = areTreesStructurallyIdentical(root1->right, root2->right);
    	
		return leftAns and rightAns;
	}
	
	return false;
}


Node* createTree(Node* root)
{
	int d;
	cin>>d;
	
	root=new Node(d);
	
	string x;
	cin>>x;
	
	if(x=="true")
	{
	    root->left=createTree(root->left);
	}
	
	cin>>x;
	
	if(x=="true")
	{
    	root->right=createTree(root->right);
	}
	
	return root;
}

void preOrder(Node *root)
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
 	Node *root1=NULL;
	Node *root2=NULL;
 
 	root1=createTree(root1);
 	root2=createTree(root2);
 	
	if(areTreesStructurallyIdentical(root1,root2))
	{
     	cout<<"true"<<endl;
 	}
	else	
	{
    	cout<<"false"<<endl;
 	}
}
