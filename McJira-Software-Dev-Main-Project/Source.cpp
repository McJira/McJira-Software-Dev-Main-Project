#include <iostream>
#include <string>
#include "Map.h"
#include "Enemy.h"
#include "Combat.h" // missing in Justine's kit
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
#include "InputValidation.h"
#include "Player.h"
#include "Dialog.h"
#include "Inventory.h"
using namespace std;

int main() {
    Map dungeonMap;
    string input;
    string playerInput;
    InputValidation inputValid;
    Player player_1;
    Dialog dialog;
    Inventory inventory;
    
    // Boolean to track if the sword has been picked up
    bool swordPickedUp = false;
    
    // Random implementation for Zen
    srand(static_cast<unsigned>(time(0)));
    int Zenrandint1 = rand() % 3;
    int Zenrandint2 = rand() % 3;
    
    // Adding item to the map
    Item sword(1, "sword", 3, dialog.GetSwordDescription(), 15);
    dungeonMap.GetRoom("zen").AddItem(sword, 3, 3);

    // Create and place the enemy Ian in Zen at random coordinates
    Enemy ian(25.0, 10.0, 0, 50, 5, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    Enemy ian2(25.0, 10.0, 20, 30, 30, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    bool added = dungeonMap.GetRoom("zen").AddEnemy(ian, Zenrandint1, Zenrandint2);  // Using GetRoom and AddEnemy with random coordinates

    if (added) {
        cout << "Ian has been added to Zen at position [" << Zenrandint1 << ", " << Zenrandint2 << "]." << endl;
    } else {
        cout << "Failed to add Ian to the room." << endl;
    }

    bool added2 = dungeonMap.GetRoom("hennessy hall").AddEnemy(ian2, 2, 2);  // Using GetRoom and AddEnemy with static coordinates

    if (added2) {
        cout << "Ian has been added to Hennessy Hall at position [2, 2]." << endl;
    } else {
        cout << "Failed to add Ian to the room." << endl;
    }

    // Display welcome message and initial map
    cout << dialog.GetIntroMessage();
    dungeonMap.DisplayFullMap();
    dungeonMap.DisplayCurrentRoomMap();

    while (true) {
        
        // Avoid displaying instructions multiple times
        Room& currentRoom = dungeonMap.GetRoom(dungeonMap.GetCurrentRoomName()); 
        if (!currentRoom.HasEnemy("IAN") && !currentRoom.HasItem()) {
            cout << dialog.GetInstructions();
        }
        
        player_1.RequestPlayerMove();

        if (player_1.GetMove() == "stats") {
            player_1.DisplayStats();
        } else if (player_1.GetMove() == "inv") {
            inventory.ShowInventory();
        } else if (player_1.GetMove() == "map") {
            dungeonMap.DisplayFullMap();
        } else if (player_1.GetMove() == "current") {
            dungeonMap.DisplayCurrentRoomMap();
        } else if (player_1.GetMove() == "w" || player_1.GetMove() == "a" || player_1.GetMove() == "s" || player_1.GetMove() == "d") {
            dungeonMap.MovePlayerInRoom(player_1.GetMove()[0]);
        } else {
            dungeonMap.MovePlayerToRoom(player_1.GetMove());
        }

        // Check if Ian is in the current room and alive
        if (currentRoom.HasEnemy("IAN")) {
            cout << "\nYou encounter Ian!" << endl;
            ian.displayEnemyInfo();

            //prompt only if Ian's health is above 0
            if (ian.getHealth() > 0) {
                string ianInput;
                cout << "Type IAN if you think you can take him." << endl;
                cin >> ianInput;

                if (ianInput == "IAN") {
                    Combat combat(player_1, ian);
                    combat.fight();

                    //If Ian is defeated, remove him from the room
                    if (ian.getHealth() <= 0) {
                        cout << "You have defeated Ian!" << endl;
                        currentRoom.RemoveEnemy(Zenrandint1, Zenrandint2);
                    }

                    //Check if the player is still alive
                    if (!player_1.isAlive()) {
                        cout << "You have died. GAME OVER!" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "Invalid input. Try again" << endl;
                }
            }
        }

        // Check if the current room has an item and if the sword hasn't been picked up
        if (!swordPickedUp && currentRoom.HasItem()) {
            cout << "An item is at your current location!" << endl;
            cout << "You found an item!!!" << endl;
            cout << "Enter yes to pick up Sword and no to continue: " << endl;
            player_1.RequestPlayerMove();

            if (player_1.GetMove() == "yes") {
                inventory.AddItemToInventory(sword);
                player_1.AddAttackPower(sword.GetItemDamage());
                currentRoom.RemoveItem(3, 3);  //remove the item from the map
                swordPickedUp = true;  //Set flag to prevent further prompts
            } else if (player_1.GetMove() == "no") {
                cout << dialog.GetInstructions();  //display instructions after replying no
            } else {
                cout << "Please answer yes or no!" << endl;  //prevent invalid input from breaking the game
            }
        }
    }

    return 0;
}