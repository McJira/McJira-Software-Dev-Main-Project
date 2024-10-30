#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
#include "Item.h"
#include "Inventory.h"
using namespace std;

int main() {
	string playerInput;
	InputValidation inputValid;

	//Added a default sword to test how inventory class works
	Item sword(1,"Sword",1,"a");
	Inventory inventory;
	Player player_1;
	Dialog dialog;
	Map dungeonMap;

	// Displays intro message
	cout << dialog.GetIntroMessage();
	// changed it to GetRoomDesc can be found in Map.h
	dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	while (true) {
		cout << "Enter either 'stats', 'm', 'inv' or the direction you'd like to head next: " << endl;
		getline(cin, playerInput); // changed this to getline because it makes more sense
		inputValid.ToLowerCase(playerInput);

		if (playerInput == "m")
		{
			dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
			dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

		}

		else if (playerInput == "stats")
		{

			player_1.DisplayStats();

		}
		else if (playerInput == "key")
		{
			cout << dialog.GetKeyDescription();
			// here we have to make it so that when you grab the key it goes into your inventory
		}
		else if (playerInput == "ian")
		{
			cout << dialog.GetIanDescription();
			// this triggers the final boss sequence. we might wanna make it to where if the user doesnt pick up vallones sword they instantly die if they interact with ian
		}
		else if (playerInput == "sword")
		{
			cout << dialog.GetSwordDescription();
			inventory.AddItemToInventory(sword);
			// needs to add sword to inventory and also update the amount of damage the player does now that they have a sword
		}
		else if (playerInput == "remove")
		{
			inventory.RemoveItemFromInventory();
		}
		else if (playerInput == "inv" || playerInput == "inventory")
		{
			inventory.ShowInventory();
			//displays the current inventory
		}
		else
		{
			player_1.PlayerMovement(playerInput);
			dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
	}
	


	return 0;

}

