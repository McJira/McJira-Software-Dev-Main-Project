#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
#include "Enemy.h"
#include "Item.h"
#include "Inventory.h"

/*
* THIS FILE IS SOLEY FOR TESTING YOUR CODE
* 
* made to prevent further merge conflicts
* 
* When finished testing and getting ready to push DELETE ALL CODE IN THIS FILE! 
* DO NOT DELETE THIS COMMENT PLEASE
* 
* NOTE: All present classes are included in this file, if need add your new class header under the last header(currently line 9) 
* 
*/

int main()
{
	Player player;
	Enemy enemy;
	InputValidation validate;
	Item sword(1, "sword", 1, "The Sword of Vallone",30);
	Item book(2, "book", 2, "The book of wisdom",0);
	Item liflet(3, "liflet", 3, "The liflet",0);
	enemy.setHealth(100);
	cout << sword.GetItemDamage();

	Inventory inventory;

	inventory.AddItemToInventory(book);
	inventory.AddItemToInventory(liflet);

	cout << "Testing Inventory" << endl;
	cout << enemy.getHealth();

	while (true)
	{

		cout << "An enemy is infront of you" << endl;
		player.RequestPlayerMove();

		if (player.GetMove() == "inv")
		{
			inventory.ShowInventory();
		}
		if (player.GetMove() == "sword")
		{
			inventory.AddItemToInventory(sword);
		}
		if (player.GetMove() == "inspect")
		{
			cout << "Which item would you like to inspect " << endl;
			player.RequestPlayerMove();
			inventory.InspectItemFromHotBar(player.GetMove(),enemy);
			cout << enemy.getHealth();

		}


		enemy.getHealth();

		

	}
	


}