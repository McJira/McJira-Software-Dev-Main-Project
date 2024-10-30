#pragma once

#include "Inventory.h"

void Inventory::AddItemToInventory(Item& itemToBeAdded){

	//checks if the amount of items allowed in the hotbar has been exceeded
	if (inventory.size() > hotBarSize - 1)
	{
		//Function to push to backpack
		cout << "Hot bar full, Item added to backpack " << endl;
	}	
	else
	{
		cout << endl << itemToBeAdded.GetItemName() << " Added To Inventory " << endl;
		inventory.push_back(itemToBeAdded);
	}

}

void Inventory::ShowInventory(){

	//checks if the vector is empty
	if (inventory.empty())
	{
		cout << "Your inventory is empty " << endl;
	}
	//iterates through the items within the inventory structure and displays them to the player
	else
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i+1 << ": " << inventory[i].GetItemName() << "   ";
		}

		cout << endl;
	}
	

}

void Inventory::RemoveItemFromInventory(){

	//checks if the data structure has any items left in it before removing more
	if (inventory.empty())
	{
		cout << "Nothing to drop, inventory is empty " << endl;
		return;

	}
	else
	{ 
		//prints the front element in the vector
		cout << endl << inventory.front().GetItemName() << " Removed from Inventory " << endl;
		//pops back the front element in the vector
		inventory.pop_back();
	}


}

Inventory::Inventory(){


}
