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
void Inventory::InspectItemFromHotBar(string desiredItem)
{
	//bool to check if the item was found in the data structure or not
	bool itemFound = false;
	//for loop that looks for the specified item, by iterating through the inventory structure and returning when found
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i).GetItemName() == desiredItem)
		{
			itemFound = true;
			cout << inventory.at(i).GetItemDescription() << endl;
			cout << "Enter 'use' or 'remove' " << endl;
			playerCommand.RequestPlayerMove();
			if (playerCommand.GetMove() == "remove")
			{
				RemoveItemFromInventory(i);
			}
			if(playerCommand.GetMove() == "use")
			{
				cout << "This item has no use currently";
			}

			break;

		}
		else
		{
			continue;
		}


	}

	//checks if the item was not found
	if (!itemFound)
	{
		cout << "You do not have this item " << endl;
	}


	

}
void Inventory::InspectItemFromHotBar(string desiredItem, Enemy& enemy)
{

	//bool to check if the item was found in the data structure or not
	bool itemFound = false;
	//for loop that looks for the specified item, by iterating through the inventory structure and returning when found
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i).GetItemName() == desiredItem)
		{
			itemFound = true;
			cout << inventory.at(i).GetItemDescription() << endl;
			cout << "Enter 'use' or 'remove' " << endl;
			playerCommand.RequestPlayerMove();
			if (playerCommand.GetMove() == "remove")
			{
				RemoveItemFromInventory(i);
			}
			if (playerCommand.GetMove() == "use")
			{
				enemy.EnemyTakeDamage(inventory[i].GetItemDamage());
			}

			break;
		}
		else
		{
			continue;
		}
	}

	if (!itemFound)
	{
		cout << "You do not have this item " << endl;
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

void Inventory::RemoveItemFromInventory(int itemToBeRemoved){

	//checks if the data structure has any items left in it before removing more
	if (inventory.empty())
	{
		cout << "Nothing to drop, inventory is empty " << endl;
		return;

	}
	else
	{ 

		//prints the selected element in the vector
		cout << inventory[itemToBeRemoved].GetItemName() << " Removed from Inventory " << endl;
		//deletes the selected item from the vector, to find the "ItemToBeRemoved" index, refer to InspectItemFromInventory()
		inventory.erase(inventory.begin() + itemToBeRemoved);
	
		
	}


}

Inventory::Inventory(){


}
