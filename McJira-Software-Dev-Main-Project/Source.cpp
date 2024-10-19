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

	dialog.GetIntroMessage();
	dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	while (true) {
		cin >> playerInput;
		inputValid.ToLowerCase(playerInput);
		if (playerInput == "m")
		{
			dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
		else
		{
			player_1.PlayerMovement(playerInput);
		}
	}


}

