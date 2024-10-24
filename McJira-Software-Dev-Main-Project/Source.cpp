#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
using namespace std;

int main() {
	string playerInput;
	InputValidation inputValid;

	Player player_1;
	Dialog dialog;
	Map dungeonMap;

	// Displays intro message
	cout << dialog.GetIntroMessage();
	// changed it to GetRoomDesc can be found in Map.h
	dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	while (true) {
		cout << "Enter either 'stats', 'm', or the direction you'd like to head next: " << endl;
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
			// needs to add sword to inventory and also update the amount of damage the player does now that they have a sword
		}
		else
		{
			player_1.PlayerMovement(playerInput);
			dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
	}

	return 0;

}

