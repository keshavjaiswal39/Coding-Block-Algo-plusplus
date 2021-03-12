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

node *buildTreeFromTraversal(int *in,int *pre,int s,int e)
{
	static int i=0;
	
	// base case
	if(s>e)
	{
		return NULL;
	}
	// Recursive case
	node *root=new node(pre[i]);
	
	int index=-1;
	
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	
	i++;
	root->left=buildTreeFromTraversal(in,pre,s,index-1);
	root->right=buildTreeFromTraversal(in,pre,index+1,e);
	
	return root;
}

int size(node *root)
{
  	if(root==NULL)
  	{
    	return 0;
  	}
  	else
  	{
    	return (size(root->left)+1+size(root->right));
  	}
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

int largestBST(node *root)
{
    if(isBST(root,INT_MIN,INT_MAX))
  	{
    	return size(root);
  	}
  	else
  	{
    	return max(largestBST(root->left),largestBST(root->right));
  	}
}

int main()
{
	int in[1000];
	int pre[1000];
	
	int n;

	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	
	node *root=buildTreeFromTraversal(in,pre,0,n-1);
	int y=largestBST(root);
	cout<<y;
	
}







