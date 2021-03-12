 #include<vector>
#include <iostream>
#include<map>
#include<bits/stdc++.h>
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

node* buildTreeLevelWise(){

	int d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

/*
void display(node *root)
{
    if(root==NULL)
      return;
      
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
    
}
*/


void vop(node *root,map<int,vector<int>> &m,int d)
{
    if(root==NULL)
     return;
     
    m[d].push_back(root->data);
    
    vop(root->left,m,d-1);
    vop(root->right,m,d+1);
}

void printvertical(node*root)
{
    map<int,vector<int> > m;
    int h=0;
    vop(root,m,h);
    for(auto it=m.begin();it!=m.end();it++)
	{
	   // cout<<it->first<<" ";
	    
	    for(int j=0;j<it->second.size();j++)
	      {
              cout<<it->second[j]<<" ";
          }
	      cout<<endl;
	}
}

int main() 
{   int n;
    cin>>n;
   // map<int, vector<int>> m;

	node *root = buildTreeLevelWise();
	
	printvertical(root);
	//display(root);
	
	
	
	return 0;
}

