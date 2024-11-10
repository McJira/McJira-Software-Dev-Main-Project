#include <iostream>
#include <string>
#include "Map.h"
#include "Enemy.h"

using namespace std;

int main() {
    Map dungeonMap;
    string input;

    // Create and place the enemy "Ian" in "Room 1" at coordinates (1,1)
    Enemy ian(25.0, 10.0, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    Enemy ian2(25.0, 10.0, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    bool added = dungeonMap.GetRoom("Room 1").AddEnemy(ian, 1, 1);  // Assuming GetRoom and AddEnemy are implemented

    if (added) {
        cout << "Ian has been added to Room 1 at position [1,1]." << endl;
    }
    else {
        cout << "Failed to add Ian to the room." << endl;
    }
    bool added2 = dungeonMap.GetRoom("Room 2").AddEnemy(ian2, 2, 2);  // Assuming GetRoom and AddEnemy are implemented

    if (added2) {
        cout << "Ian has been added to Room 1 at position [1,1]." << endl;
    }
    else {
        cout << "Failed to add Ian to the room." << endl;
    }

    // Display welcome message and initial map

    dungeonMap.DisplayFullMap();
    dungeonMap.DisplayCurrentRoomMap();

    while (true) {
        cout << "\nCommands:" << endl;
        cout << "'n'/'s'/'e'/'w' to move within the room" << endl;
        cout << "Room name (e.g., 'Room 2') to move to a connected room" << endl;
        cout << "'map' to display the full map, 'current' to display the current room map" << endl;

        cout << "\nEnter your command: ";
        getline(cin, input);

        if (input == "map") {
            dungeonMap.DisplayFullMap();
        }
        else if (input == "current") {
            dungeonMap.DisplayCurrentRoomMap();
        }
        else if (input == "n" || input == "s" || input == "e" || input == "w") {
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
