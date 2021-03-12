#include<iostream>
#include<cstring>

using namespace std;

// Implement a HashMap
// Separate Chaining Technique

template<typename T>

class Node
{
	public:
		string key;
		T value;
		Node<T> *next;
		
		Node(string key,T val)
		{
			this->key=key;
			value=val;
			next=NULL;
		}
		
		~Node()   // this will recursively delete the node and then the table
		{
			if(next!=NULL)
			{
				delete next;
			}
		}
};

template<typename T>

class HashTable
{
	Node<T> **table;   // pointer to the array of pointer
	int current_size;
	int table_size;
	
	int hashFn(string key)
	{
		int idx=0;
		int p=1;
		for(int j=0;j<key.length();j++)
		{
			idx=idx+(key[j]*p)%table_size;
			idx=idx%table_size;
			p=(p*27)%table_size;
		}
		return idx;
	}
	
	void rehash()
	{
		Node<T> **oldTable=table;
		int oldTableSize=table_size;
		table_size=2*table_size; // we can also add it with the next prime number using next prime function
		table=new Node<T>*[table_size];
		
		for(int i=0;i<table_size;i++)
		{
			table[i]==NULL;
		}
		current_size=0;
		
		// shift the elements from old table to new table
		for(int i=0;i<oldTableSize;i++)
		{
			Node<T>*temp=oldTable[i];
			while(temp!=NULL)
			{
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			
			if(oldTable[i]!=NULL)
			{
				delete oldTable[i];
			}
		}
		delete[] oldTable;
	}
	
	public:
		HashTable(int ts=7)
		{
			table_size=ts;
			table=new Node<T>*[table_size];
			current_size=0;
			
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;
			}
		}
		
		void insert(string key,T value)
		{
			int idx=hashFn(key); 
			// now we need the hash function give us the key, so we need to make a hash function
			// and this we will make inside the private function as we dont want it to be further modified
			
			Node<T> *n=new Node<T>(key,value);
			// Insert at the head of the Linked list with id=idx
			n->next=table[idx];
			table[idx]=n;
			current_size++;
			
			// rehasing... we will add later
			float load_factor=current_size/(1.0*table_size);
			if(load_factor>0.7)
			{
				rehash();
				// we want the rehash function to be made in the private fucntion
				//  so that no one mess up with our private data and functions
			}
			
		}
		
		T* search(string key)  // T* to return the index the
		{
			int idx=hashFn(key);
			Node<T> *temp=table[idx];
			while(temp!=NULL)
			{
				if(temp->key==key)
				{
					// as we have the return type as T*, we return the adress of the box instead of returning the box
					return &temp->value;
				}
				temp=temp->next;
			}
			return NULL;
		}
		
		// Easy access using [] operator
		T& operator[](string key)
		{
			T* f=search(key);
			if(f==NULL)
			{
				// Insert key, value(garbage) in the hashmap
				T garbage;
				insert(key,garbage);
				f=search(key);
			}
			return *f;
		}
		
		void erase(string key)
		{
			
		}
		
		// this fn is not a part of the class and we want it to be outside the class but
		// we just want to see how thing happens inside the class so we made this fn
		void print()  
		{
			for(int i=0;i<table_size;i++)
			{
				cout<<"Bucket "<<i<<" -> ";
				Node<T> *temp=table[i];
				while(temp!=NULL)
				{
					cout<<temp->key<<" -> ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
};

int main()
{
	HashTable<int> price_menu;
	price_menu["Burger"]=60;
	price_menu["Pepsi"]=20;
	price_menu["BurgerPizza"]=150;
	price_menu["Noodles"]=25;
	price_menu["Coke"]=40;
	
	price_menu.print();
	cout<<endl;
	
	// update
	price_menu["Coke"]+=10;
	
	// search
	cout<<price_menu["Coke"]<<endl;	
	
}




