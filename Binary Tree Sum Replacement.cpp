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

int replaceSum(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	// if leaf node do nothing and just return
	if(root->left==NULL and root->right==NULL)
	{
		return root->data;
	}
	
	// recursive part
	int leftSum=replaceSum(root->left);
	int rightSum=replaceSum(root->right);
	
	int temp=root->data;
	root->data=leftSum+rightSum;
	
	return temp+root->data;
}

void bfs(node *root)
{
	queue<node *> q;
	q.push(root);
	
	while(!q.empty())
	{
		node *f=q.front();
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
	return ;
}

int main()
{
	node *root=buildTree();
	// printAllLevels(root);
	bfs(root);
	cout<<endl;
	replaceSum(root);
	bfs(root);
		
}






