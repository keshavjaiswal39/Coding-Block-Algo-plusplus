#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		// constructor
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

/*
// Creation using Linked Class (Object Oriented Programming)
class LinkedList
{
	node *head;
	node *tail;
	
	public:
		LinkedList()
		{
			
		}
		void Insert(int d)
		{
			
		}
	// But we will not do insertion using class as in the interview we will
	// be asked to complete only one function.
};

*/

// Creation using Functions (Procedural programming)
// Passing a pointer by reference

int lenght(node *head);

void insertAtHead(node * &head,int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	
	node *n=new node(d);
	n->next=head;
	head=n;
}

void Display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<endl;
}

int lenght(node *head)
{
	int cnt=0;
	while(head!=NULL)
	{
		cnt++;
		head=head->next;
	}
	return cnt;
}

void insertAtTail(node * &head,int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(d);
	return ;
}

void insertInMiddle(node * &head,int d,int p)
{
	if(head==NULL or p==0)
	{
		insertAtHead(head,d);
	}
//	else if(p>length(head))
//	{
//		insertAtTail(head,d);
//	}
	else
	{
		// take p-1 jumps
		int jump=1;
		node *temp=head;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump++;
		}
		// create  a new node
		node *n=new node(d);
		n->next=temp->next;
		temp->next=n;
	}
}

void deleteHead(node * &head)
{
	if(head==NULL)
	{
		return;
	}
	node *temp=head->next;
	delete head;
	head=temp;
}

void deleteInMiddle(node * &head,int p)
{
	if(head==NULL or p==0)
	{
		deleteHead(head);
	}
	else
	{
		// take p-1 jumps
		int jump=1;
		node *temp=head;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump++;
		}
		node *n=temp->next;
		temp->next=n->next;
		delete n;
	}
}

void deleteTail(node * &head)
{
	if(head==NULL)
	{
		return;
	}
	node *prev=NULL;
	node *tail=head;
	while(tail->next!=NULL)
	{
		prev=tail;
		tail=tail->next;
	}
	delete tail;
	prev->next=NULL;
	return ;
}

int main()
{
	node *head=NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	Display(head);
	
	insertInMiddle(head,4,3);
	Display(head);
	
	insertInMiddle(head,6,2);
	Display(head);
	
	insertAtTail(head,7);
	Display(head);
	
	Display(head);
	
	deleteHead(head);
	Display(head);
	
	deleteInMiddle(head,3);
	Display(head);
	
	deleteTail(head);
	Display(head);
	
	return 0;
}




