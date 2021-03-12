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

void printAtLevelK(node *root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}	
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	
	return;
}

int printAtDistanceK(node *root,node *target,int k)
{
	// base case
	if(root==NULL)
	{
		return -1;
	}
	
	// reach the target node
	if(root==target)
	{
		printAtLevelK(target,k);
		return 0;
	} 
	
	// next step- ancestor node
	int DL=printAtDistanceK(root->left,target,k);
	
	if(DL!=-1)
	{
		// Again there are two cases
		// Print ancestor itself or go to the right subtree
		
		if(DL+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			printAtLevelK(root->right,k-2-DL);
		}
		return 1+DL;
	}
	
	int DR=printAtDistanceK(root->right,target,k);
	
	if(DR!=-1)
	{
		if(DR+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			printAtLevelK(root->left,k-2-DR);
		}
		return 1+DR;
	}
	
	// Node was not present in left and right subtree of given target node
	return -1;
} 


 
int main()
{
	node *root=NULL;
	
	// take input the tree
	cin>>root;   // 1 2 3 4 5 -1 -1 6 7 8 9 -1 -1 10 11 -1 -1 -1 -1 -1 -1 -1 -1 : we are taking level wise
	
	node *target=root->left->left;
	
	// print the tree
	cout<<root<<endl;
	
	int k;
	cin>>k;
	
	printAtDistanceK(root,target,k);
	
	return 0;
}






