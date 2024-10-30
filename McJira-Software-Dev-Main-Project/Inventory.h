#ifndef INVENTORY_H
#define INVENTORY_H


#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class Inventory {

private:

	//Data structure to store Items: This case it is a Vector of items, which are objects from the Item class

	vector<Item>inventory;
	int hotBarSize = 5;


public:


	//function to add an item to the inventory;
	void AddItemToInventory(Item&);
	//function to show hotbar inventory
	void ShowInventory();
	//function to remove item from inventory
	void RemoveItemFromInventory();
	

	//Constructor
	Inventory();

};

#endif // !INVENTORY_H
