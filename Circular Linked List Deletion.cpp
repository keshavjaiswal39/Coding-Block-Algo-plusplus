#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		//constructor
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

void insert(node * &head,int data)
{
	node *n=new node(data);
	node *temp=head;
	
	n->next=head;

	if(temp!=NULL)
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=n;
	}
	else
	{
		n->next=n;
	}
	
	head=n;
}

void Display(node *head)
{
	node *temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

// Deletion in circular linked list
node* get_node(node * &head,int data)
{
	node *temp=head;
	// for all the nodes expcept the last node
	while(temp->next!=head)
	{
		if(temp->data==data)
		{
			return temp;
		}
		temp=temp->next;
	}
	// out of the loop and checked all the node except the last node
	if(temp->data==data)
	{
		return temp;
	}
	return NULL;
}

void deleteNode(node * &head,int data)
{
	node *del=get_node(head,data);
	if(del==NULL)
	{
		return;
	}
	// Otherwise
	if(head==del)
	{
		head=head->next;
	}
	
	node *temp=head;
	// stop one step behind the node to be deleted
	while(temp->next!=del)
	{
		temp=temp->next;
	}
	temp->next=del->next;
	delete del;
}

int main()
{
	node *head=NULL;
	insert(head,10);
	insert(head,20);
	insert(head,30);
	insert(head,40);
	insert(head,50);
	insert(head,60);
	
	Display(head);
	cout<<endl;
	
	deleteNode(head,40);
	Display(head);
	
}


