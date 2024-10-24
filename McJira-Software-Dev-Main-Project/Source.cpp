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
	// Tests if DisplayRoomSideDescription works, for more info on the function, view Dialog.h
	cout << dialog.DisplayRoomSideDescription(0,"n");

	dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	while (true) {
		cout << "Enter 'Stats' to view player stats: ";
		getline(cin, playerInput); // changed this to getline because it makes more sense
		inputValid.ToLowerCase(playerInput);

		if (playerInput == "m")
		{
			dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}

		else if (playerInput == "stats")
		{

			player_1.DisplayStats();

		}
		else
		{
			player_1.PlayerMovement(playerInput);
			dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
	}

	return 0;

}

