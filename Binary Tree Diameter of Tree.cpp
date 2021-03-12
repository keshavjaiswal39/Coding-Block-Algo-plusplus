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

int diameter(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	
	int op1=h1+h2+1;
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	
	int dia=max(op1,max(op2,op3));
	
	return dia;
	
}

int main()
{
	node *root=buildTree();
	// printAllLevels(root);
	cout<<diameter(root)<<endl;
		
}






