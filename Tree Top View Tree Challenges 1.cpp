#include<bits/stdc++.h>
using namespace std;

//Declared a Node for each tree
class Node
{
    public:
        int data;
        int index;
        Node* left;
        Node* right;
        
        Node(int d)
		{
            data=d;
            left=NULL;
            right=NULL;
        }
};

//Function to print top view of a tree
void topview(Node* root)
{
    if(root==NULL)
	{
        return;
    }
    /*A queue is initialised to print the tree level wise in order to 
      print the top node at first.As the node at top level is vistied
      at first.
    */
    queue<Node*>q;
    
    map<int,int>m;
    
    int index=0;
    
    /*Initialise each node a index. So that the top most horizontal node
    	is printed first*/
  
    root->index=0;
    
    q.push(root);
    
    while(q.size())
	{
        index=root->index;
        
        // m.count returns "is there the index element present already"?
        // mtlb har bar har element ka index ko map mein check karegi ki present hai ki nai, 
		// agar hai iska mtlb ki uce index ke value pe already koi dusra element print hochuka hai
		// agar nai hai mtlb map mein uce index ka value hi nai hai.
		// map mein insertion pehle left child ka hga fir right child ka hga
		if(m.count(index)==0)     
		{
            m[index]=root->data;
        }
        
        //We initalise the left of root index as index-1
        if(root->left)
		{
            root->left->index=index-1;
            q.push(root->left);
        }
        
        //We initalise the right of root index as index+1
        if(root->right)
		{
            root->right->index=index+1;
            q.push(root->right);
        }
        
        //Pop the top most node and explore the next node
        q.pop();
        
        //Initialise the current node as root
        root=q.front();
    }
    
    for(auto i:m) 
    { 
        cout<<i.second<<" "; 
    } 
}

Node* createTree(Node* root)
{
    int d;
    cin>>d;

    root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
    	Node*f = q.front();
	    q.pop();
	    int c1,c2;
	    cin>>c1>>c2;

	    if(c1!=-1){
		    f->left = new Node(c1);
		    q.push(f->left);
	    }
    	if(c2!=-1){
	    	f->right = new Node(c2);
		    q.push(f->right);
	    }
    }
 return root;
}
 
int main()
{
    Node *root=NULL;
    root=createTree(root);
    topview(root);
    cout<<endl;
}



