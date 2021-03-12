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

node *buildTree(node *root)
{
	int d;
	cin>>d;
	
	root=new node(d);
	
	string x;
	cin>>x;
	
	if(x=="true")
	{
	    root->left=buildTree(root->left);
	}
	
	cin>>x;
	
	if(x=="true")
	{
    	root->right=buildTree(root->right);
	}
	
	return root;
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

void printKthLevel(node *root,int k)
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
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
	
	return;
}

void printKthLevel1(node *root,int k)
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
	printKthLevel1(root->right,k-1);
	printKthLevel1(root->left,k-1);
	
	return;
}

void zigzag(node*root)
{
    int h=height(root);
    for(int i=0;i<h;i++)
    {
        if(i%2==0)
        {
            printKthLevel(root,i);
    
        }
        else if(i%2!=0)
        {
          	printKthLevel1(root,i);
        }
    }
}

int main()
{
	node *root=NULL;
	root=buildTree(root);
	zigzag(root);
		
}






