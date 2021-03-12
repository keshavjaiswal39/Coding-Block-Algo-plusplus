#include<iostream> 
#include "HashTable.h"  // user defined header should be inside double quotes
#include<cstring>

using namespace std;

int main()
{
	HashTable<int> price_menu;
	price_menu.insert("Burger",120);
	price_menu.insert("Pepsi",20);
	price_menu.insert("BurgerPizza",150);
	price_menu.insert("Noodles",25);
	price_menu.insert("Coke",40);
	
	price_menu.print();
	cout<<endl;
	
	int *price=price_menu.search("Noodles"); // *price will point to the address returned by the search function
	if(price==NULL)
	{
		cout<<"Not Found";
	}
	else
	{
		cout<<"Found and the Price is "<<*price<<endl;
		// we have used *price because the search fn returns the adress and if we want thee value we want to 
		// say *price and if we want the adress we can just print just price
 	}	
 	
	
}



