#include <iostream>
#include <string>
#include "Map.h"
#include "Enemy.h"
#include <cstdlib>  //for rand and srand
#include <ctime>    //for time
#include "InputValidation.h"
#include "Player.h"
#include "Dialog.h"
using namespace std;

int main() {
    Map dungeonMap;
    string input;
    string playerInput;
    InputValidation inputValid;
    Player player_1;
    Dialog dialog;
    //random implmentation for Zen
    srand(static_cast<unsigned>(time(0)));
    int Zenrandint1 = rand() % 3;
    int Zenrandint2 = rand() % 3;
    //create and place the enemy Ian in Zen at random coordinates
    Enemy ian(25.0, 10.0, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    Enemy ian2(25.0, 10.0, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    bool added = dungeonMap.GetRoom("Zen").AddEnemy(ian, Zenrandint1, Zenrandint2);  //using GetRoom and AddEnemy with random ints

    if (added) {
        cout << "Ian has been added to Zen at position [1,1]." << endl;
    }
    else {
        cout << "Failed to add Ian to the room." << endl;
    }
    bool added2 = dungeonMap.GetRoom("Hennessy Hall").AddEnemy(ian2, 2, 2);  //using GetRoom and AddEnemy with static ints.

    if (added2) {
        cout << "Ian has been added to Zen at position [1,1]." << endl;
    }
    else {
        cout << "Failed to add Ian to the room." << endl;
    }

    //display welcome message and initial map
    cout << dialog.GetIntroMessage();
    dungeonMap.DisplayFullMap();
    dungeonMap.DisplayCurrentRoomMap();

    while (true) {
        cout << "\nCommands:" << endl;
        cout << "'w' to move north" << endl;
        cout << "'a' to move west" << endl;
        cout << "'s' to move south" << endl;
        cout << "'d' to move east" << endl;
        cout << "Enter room name (e.g., 'Hennessy Hall' or shorthand 'HH') to move to a connected room" << endl;
        cout << "'map' to display the full map, 'current' to display the current room map" << endl;

        cout << "\nEnter your command: ";
        getline(cin, input);

        if (input == "map") {
            dungeonMap.DisplayFullMap();
        }
        else if (input == "current") {
            dungeonMap.DisplayCurrentRoomMap();
        }
        else if (input == "w" || input == "a" || input == "s" || input == "d") {
            dungeonMap.MovePlayerInRoom(input[0]);
        }
        else {
            dungeonMap.MovePlayerToRoom(input);
        }

        // Check if Ian is in the current room and display his info
        Room& currentRoom = dungeonMap.GetRoom(dungeonMap.GetCurrentRoomName());
        if (currentRoom.HasEnemy("IAN")) {
            cout << "\nYou encounter Ian!" << endl;
            ian.displayEnemyInfo();
        }
    }

    return 0;
}
