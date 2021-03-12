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

class Pair
{
	public:
		int height;
		int diameter;		
};   // instead we can also use pair stl class

Pair fastDiameter(node *root)
{
	Pair p;
	if(root==NULL)
	{
		p.diameter=p.height=0;
		return p;
	}
	// otherwise
	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);
	
	p.height=max(left.height,right.height)+1;
	p.diameter=max((left.height+right.height+1),max(left.diameter,right.diameter));

	return p;
	
}

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

void printKthLevel(node *root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
	
	return;
}

int height(node *root)
{
	if(root==NULL) 
	{
		return 0;
	}
	int ls=height(root->left);
	int rs=height(root->right);
	
	return max(ls,rs)+1;
}

void printAllLevels(node *root)
{
	int H=height(root);
	
	for(int i=1;i<=H;i++)
	{
		printKthLevel(root,i);
		cout<<endl;
	}
}

int countNodes(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int SumNodes(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return root->data + SumNodes(root->left) + SumNodes(root->right);
}

int main()
{
	node *root=buildTree();
	// printAllLevels(root);
	Pair p=fastDiameter(root);
	cout<<p.height<<endl;
	cout<<p.diameter;	
}






