#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		// Constructor
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

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
	return;
}

void insertAtMiddle(node * &head,int d,int pos)
{
	if(head==NULL or pos==0)
	{
		insertAtHead(head,d);
	}
	else
	{
		// take p-1 jumps
		int jump=1;
		node *temp=head;
		while(jump<=pos-1)
		{
			temp=temp->next;
			jump++;
		}
		// create a new node
		node *n=new node(d);
		n->next=temp->next;
		temp->next=n;
	}
}

// Search Operation
// Linear Search
bool search(node *head,int key)
{
	node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

// Recursively
bool searchRecursive(node *head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	// rec case, check at head and remaining linked list
	if(head->data==key)
	{
		return true;
	}
	else
	{
		return searchRecursive(head->next,key);
	}
}


int main()
{
	node *head=NULL;
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	
	insertAtMiddle(head,5,4);
	insertAtMiddle(head,6,5);
	insertAtMiddle(head,7,6);
	
	insertAtTail(head,8);
	insertAtTail(head,9);
	insertAtTail(head,10);
	
	Display(head);
	
	int key;
	cout<<"Enter your key to search"<<endl;
	cin>>key;
	
	if(search(head,key))
	{
		cout<<"Key found";
	}
	else
	{
		cout<<"Key not found";
	}
	
	cout<<endl;
	
	int key1;
	cout<<"Enter your key to search"<<endl;
	cin>>key1;
	if(searchRecursive(head,key1))
	{
		cout<<"Key found";
	}
	else
	{
		cout<<"Key not found";
	}
	
}






