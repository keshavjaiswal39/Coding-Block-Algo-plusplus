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

class HBPair   // Pair of height and balanced case(true or false)
{
	public:
		int height;
		bool balance;
};

node* createTree(node* root)
{
	int d;
	cin>>d;
	
	root=new node(d);
	
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

HBPair isHeightBalanced(node *root)
{
	HBPair p;
	
	if(root==NULL)
	{
		p.height=0;
		p.balance=true;
		return p; 
	}
	
	// Recursive case
	HBPair left=isHeightBalanced(root->left);
	HBPair right=isHeightBalanced(root->right);
	
	p.height=max(left.height,right.height)+1;
	
	if(abs(left.height-right.height)<=1 and left.balance and right.balance)
	{
		p.balance=true;
	}
	else
	{
		p.balance=false;
	}
	return p;
}

int main()
{
	node *root=createTree(root);
	
	HBPair p=isHeightBalanced(root);
	
	if(p.balance)    // or if(isHeightBalanced(root).balance)
	{
		cout<<"Tree is Balanced";
	}
	else
	{
		cout<<"Tree is not Balanced";
	}
	return 0;
}






