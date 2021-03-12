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

/*
node *append(node *head,long long int n,long long int k)
{
	int x=n-k;
	node *curr=head;
	node *prev=NULL;
	
	while(x--)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	node *newhead=curr;
	
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=head;

	return newhead;
	
}
*/

node *appendK(node *head, int k)
{
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for (int i = 0; i < k && fast->next != NULL; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}



int main()
{
	long long int n;
	int arr[100005];
	cin>>n;
	
	node *head=NULL;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		insertAtTail(head,arr[i]);
	}
	
	long long int k;
	cin >> k;
    k = k % n;
    if (k == 0)
    {
        Display(head);
    }
    else
    {
        head = appendK(head, k);
        Display(head);
    }
	
}


