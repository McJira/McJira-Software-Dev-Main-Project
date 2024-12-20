#ifndef INVENTORY_H
#define INVENTORY_H


#include <iostream>
#include <vector>
#include "Item.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Inventory {

private:

	//Data structure to store Items: This case it is a Vector of items, which are objects from the Item class

	Player playerCommand;
	vector<Item>inventory; //A good Idea to change this to a List.
	int hotBarSize = 5;


public:


	//function to add an item to the inventory;
	void AddItemToInventory(Item);
	//function to inspect/select a specified item, Player obj is required for cases where player wants to use an Item such as a healing potion
	void InspectItemFromHotBar(string, Player&);
	//overloaded function to use an item on an enemy
	void InspectItemFromHotBar(string, Enemy&);
	//function to show hotbar inventory
	void ShowInventory();
	//function to remove item from inventory
	void RemoveItemFromInventory(int);
	//Funtion to return the use of an Item
	int getItemUseFromInventory(int) const;
	
	

	//Constructor
	Inventory();

};

#endif // !INVENTORY_H
