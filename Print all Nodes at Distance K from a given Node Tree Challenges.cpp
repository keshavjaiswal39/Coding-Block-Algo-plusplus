#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

vector<int> vec;

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
	return;	
}

void printAtLevelK(node *root,int k,vector<int> &vec)
{
	if(root==NULL)
	{
		return;
	}
	if(k==0)
	{
		vec.push_back(root->data);  // we are pushiing the elements in the vector to get the sorted answer
		return;
	}	
	printAtLevelK(root->left,k-1,vec);
	printAtLevelK(root->right,k-1,vec);
	
	return;
}

int printAtDistanceK(node *root,int target,int k)
{
	// base case
	if(root==NULL)
	{
		return -1;
	}
	
	// reach the target node
	if(root->data==target)
	{
		printAtLevelK(root,k,vec);
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
			vec.push_back(root->data);
		}
		else
		{
			printAtLevelK(root->right,k-2-DL,vec);
		}
		return 1+DL;
	}
	
	int DR=printAtDistanceK(root->right,target,k);
	
	if(DR!=-1)
	{
		if(DR+1==k)
		{
			vec.push_back(root->data);
		}
		else
		{
			printAtLevelK(root->left,k-2-DR,vec);
		}
		return 1+DR;
	}
	
	// Node was not present in left and right subtree of given target node
	return -1;
} 

int main()
{
	int in[1000];
	int pre[1000];
	
	int n;
	int m;
	
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
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int target;
		cin>>target;
		
		int k;
		cin>>k;
		
		printAtDistanceK(root,target,k);
		
		sort(vec.begin(),vec.end()); // When the value are stored in the vector, we want the sorted result
		
		if(vec.size()==0)
		{
			cout<<0;
		}
		else
		{
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i]<<" ";
			}
		}
		cout<<endl;
		vec.clear();
	}
	
}






