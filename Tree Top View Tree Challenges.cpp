#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Here I am making one additional field in node called height
//which will store left and right ht of tree to the left ht becomes negative
//form the root and right height becomes positive
 
class node
{
  public:
	int data ;
    node *left, *right;
    int level;
    
	node(int d)
	{
        data = d;
        left = right = NULL;
        level = 0;
    }
};
 
node *build()
{
    int d;
    cin>>d;
    
    node* root = NULL;
    
	if(d != -1)
	{
        root = new node(d);
        
		queue<node*> q;
        
		q.push(root);
        
		while(!q.empty())
		{    
			node *f = q.front();
            q.pop();
            
			int d1, d2;
            cin>>d1>>d2;
            
			if(d1 != -1)
			{
                f->left = new node(d1);
                f->left->level = f->level - 1;
                q.push(f->left);
            }
            
			if(d2 != -1)
			{
                f->right = new node(d2);
                f->right->level = f->level + 1;
                q.push(f->right);
            }
        }
    }
    return root;
}
 
int height(node* root)
{
    if(root == NULL)
	{
        return 0;
    }
    
	int l = height(root->left);
    int r = height(root->right);
    
	return max(l, r) + 1;
}
 
void topView(node* root, unordered_map<int, int> &m)
{
    if(root == NULL || m[root->level] != -1 )
    {
    	return;
	}
    
	m[root->level] = root->data;
    
	topView(root-> left, m);
    topView(root-> right, m);
}
 
int main()
{
    node *root = build();
    
	// creating unordered map storing tree information
    unordered_map <int, int> m;
    
	int limit = height(root);
    
	for(int i = -limit; i <= limit ; i++)
   	{
   		m[i] = -1;
	}
    
	topView(root, m);
    
	for(int i = -limit;i<=limit;i++)
	{
        if(m[i]!=-1)
        {
        	cout<<m[i]<<" ";
		}
    }
    return 0;
}
