#include <iostream>
#include <string>
#include "Map.h"
#include "Enemy.h"
#include "Combat.h"
#include <cstdlib>  //for rand and srand
#include <ctime>    //for time
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
    //random implmentation for Zen
    srand(static_cast<unsigned>(time(0)));
    int Zenrandint1 = rand() % 3;
    int Zenrandint2 = rand() % 3;
    //Adding item to the map
    Item sword(1, "sword", 3, dialog.GetSwordDescription(), 15);
    dungeonMap.GetRoom("zen").AddItem(sword, 3, 3);

    //create and place the enemy Ian in Zen at random coordinates
    Enemy ian(25.0, 10.0, 0, 50, 5, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    Enemy ian2(25.0, 10.0, 20, 30, 30, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE....");
    bool added = dungeonMap.GetRoom("zen").AddEnemy(ian, Zenrandint1, Zenrandint2);  //using GetRoom and AddEnemy with random ints

    if (added) {
        cout << "Ian has been added to Zen at position [1,1]." << endl;
    }
    else {
        cout << "Failed to add Ian to the room." << endl;
    }

    bool added2 = dungeonMap.GetRoom("hennessy hall").AddEnemy(ian2, 2, 2);  //using GetRoom and AddEnemy with static ints.

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
        
        // I added this line to the code so that the user doesnt get multiple instructions at once
        // and so the instructions dont loop while youre doing combat
        Room& currentRoom = dungeonMap.GetRoom(dungeonMap.GetCurrentRoomName()); 
        if (!currentRoom.HasEnemy("IAN") && !currentRoom.HasItem())
        {
            cout << dialog.GetInstructions();
        }
        player_1.RequestPlayerMove();

        if (player_1.GetMove() == "stats")
        {
            player_1.DisplayStats();
        }
        else if (player_1.GetMove() == "inv")
        {
            inventory.ShowInventory();
        }
        else if (player_1.GetMove() == "map") {
            dungeonMap.DisplayFullMap();
        }
        else if (player_1.GetMove() == "current") {
            dungeonMap.DisplayCurrentRoomMap();
        }
        else if (player_1.GetMove() == "w" || player_1.GetMove() == "a" || player_1.GetMove() == "s" || player_1.GetMove() == "d") {
            dungeonMap.MovePlayerInRoom(player_1.GetMove()[0]);
        }
        else {
            dungeonMap.MovePlayerToRoom(player_1.GetMove());
        }

        // Check if Ian is in the current room and display his info 
        // Room& currentRoom = dungeonMap.GetRoom(dungeonMap.GetCurrentRoomName()); - moved this line of code higher up
        if (currentRoom.HasEnemy("IAN")) {
            cout << "\nYou encounter Ian!" << endl;
            ian.displayEnemyInfo();

            string ianInput;
            //prompt the player to fight IAN
            cout << "Type IAN if you think you can take him." << endl;
            cin >> ianInput;

            if (ianInput == "IAN")
            {
                Combat combat(player_1, ian);
                combat.fight();                                                             //Need to add a remove enemy function to get rid of enemy after it is defeated

                //Check if the player is still alive and if the game should keep going
                if (!player_1.isAlive())
                {
                    cout << "You have died. GAME OVER!" << endl;
                    return 0; //ENDS GAME
                }

            }
            else
            {
                cout << "Invalid input. Try again" << endl;
            }


        }
        if (currentRoom.HasItem())
        {
            while (true) {
                cout << "You found an item!!! " << endl;
                cout << "Enter yes to pick up Sword and no to continue: " << endl;
                player_1.RequestPlayerMove();

                if (player_1.GetMove() == "yes")
                {
                    inventory.AddItemToInventory(sword);
                    player_1.AddAttackPower(sword.GetItemDamage());
                    break;
                }
                if (player_1.GetMove() == "no")
                {
                    cout << dialog.GetInstructions(); // added this back in so that the user gets instructions after replying yes or no
                    break;
                }
                else
                {
                    cout << "Please answer yes or no!" << endl; // so user doesnt break the game
                }

            }
        }
        
    }

    return 0;
}
