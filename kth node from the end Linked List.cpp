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

void Display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<endl;
}

//There are two ways:

//1st way
void take_input_1(node * &head)
{
	
}

// 2nd way
node* take_input_2()
{
	int d;
	cin>>d;   // in case of inputing from the file this line gets erased
	
	node *head=NULL;
	
	while(d!=-1)  // while(cin>>d) ---> This will enable us to take input until we reach the end of file or the user enters the data
	{
		insertAtHead(head,d);
//		insertAtTail(head,d);
		cin>>d;
	}
	return head;
}

/*
void operator<<(ostream &os,node *head)
{
	Display(head);
}
*/ 

// to do the cascading of the operators
ostream& operator<<(ostream &os,node *head)
{
	Display(head);
	return os; // cout
}

istream& operator>>(istream &is,node *&head) // here the reference is given to change the head
{
	head=take_input_2();
	return is; // cin
}

node *kthpoint(node *head,int k)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	node *slow=head;
	node *fast=head;
	
	while(--k)
	{
		fast=fast->next;
	}
	
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

int main()
{
//	node *head=take_input_2();
//	node *head2=take_input_2();
	node *head;
	cin>>head;
	cout<<head;
	int k;
	cin>>k;
	node *kth=kthpoint(head,k);
	cout<<kth->data;
	// this will take the input and print it in the reverse order,
	// so whatever sequence we need to input the data, we can change
	// the logic according to that
	
	
	
}




