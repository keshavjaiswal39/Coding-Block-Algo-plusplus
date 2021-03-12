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

void insertAtTail(node *&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}

void Display(node *head)
{
	if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Display(head->next);
}

node *reverse(node *head,int k)
{
	int x=k;
	node *curr=head;
	node *prev=NULL;
	node *temp=NULL;
	
	while(curr!=NULL and x>0)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
		x--;
	}
	
	if(temp!=NULL)
	{
		head->next=reverse(temp,k);
	}
	
	return prev;
	
}


int main()
{
	int n;
	int arr[10005];
	cin>>n;
	int k;
	cin>>k;
	
	node *head=NULL;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		insertAtTail(head,arr[i]);
	}
	
	head=reverse(head,k);
	
	Display(head);
	
}


