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

node *buildTree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	{
		return NULL;
	}
	node *root=new node(d);
	
	root->left=buildTree();
	root->right=buildTree();
	return root;
	
}

node *buildTreeFromArray(int *a,int s,int e)
{
	// Base case
	if(s>e)
	{
		return NULL;
	}
	
	// Recursive case
	int mid=(s+e)/2;
	node *root=new node(a[mid]);
	root->left=buildTreeFromArray(a,s,mid-1);
	root->right=buildTreeFromArray(a,mid+1,e);
	
	return root;	
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
		
		int arr[10000];
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		node *root=buildTreeFromArray(arr,0,n-1);
		preOrder(root);
		
		cout<<endl;
	}
	
}






