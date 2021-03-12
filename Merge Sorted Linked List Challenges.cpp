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
		cout<<head->data<<"  ";
		head=head->next;
	}
	cout<<endl;
}

node *merge(node *a,node *b)
{
	// base case
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}  
	
	// take a head pointer
	node *c;
	if(a->data < b->data)
	{
		c=a;
		c->next=merge(a->next,b);
	}
	else
	{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		int arr[100005];

		cin>>m;
		node *head1=NULL;
		
		for(int i=0;i<m;i++)
		{
			cin>>arr[i];
			insertAtTail(head1,arr[i]);
		}

		cin>>n;
		node *head2=NULL;

		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			insertAtTail(head2,arr[i]);
		}
	
		node *newHead=merge(head1,head2);
		Display(newHead);
		
	}	
}


