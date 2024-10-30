#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
#include "Enemy.h"

using namespace std;

int main() {
	string playerInput;
	InputValidation inputValid;
	Player player_1;
	Dialog dialog;
	Map dungeonMap;
	Enemy ian(25.0, 10.0,"IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");

	//Variable for the test combat system that will be expanded upon in the future
	char attack;

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
			//check if IAN has already been fought to elimate instance repetition
			if (ian.getIsAlive())
			{
				//display the info of IAN and start a test combat system
				ian.displayEnemyInfo();
				cout << "Enter A to attack IAN" << endl;
				cin >> attack;

				//ignore any remaining characters in the stream
				cin.ignore();

				//accepts a simple attack input to simulate how the combat will be to go through the different outputs of the enemy
				if (attack == 'A' || attack == 'a')
				{
					cout << "You have successfully defeated IAN!" << endl;
					cout << ian.getEnemyName() << ": " << ian.getEnemyOutro() << endl;
					cin.clear();
					ian.setIsAlive(false);
				}
				else //input validation
				{
					cout << "Invalid input. No attack took place." << endl;
				}
			}
			else
			{
				cout << "You see IAN's remains on the ground.  You have already defeated him." << endl << endl;
			}
			

			//cout << dialog.GetIanDescription();
			// this triggers the final boss sequence. we might wanna make it to where if the user doesnt pick up vallones sword they instantly die if they interact with ian
		}
		else
		{
			player_1.PlayerMovement(playerInput);
			dungeonMap.GetRoomDescription(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
	}
	


	return 0;

}

