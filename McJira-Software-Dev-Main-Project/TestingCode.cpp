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


void instantiateGame(Player&, Inventory&, Map&, vector<Enemy*>&, vector<Item*>&);
void clearGameMemory(vector<Enemy*>&, vector<Item*>&);
int main()
{

    bool playAgain = true;


    while (playAgain)
    {

        Map dungeonMap;
        string input;
        string playerInput;
        InputValidation inputValid;
        Player player_1;
        Dialog dialog;
        Inventory inventory;
        vector<Enemy*>enemies;
        vector<Item*>items;
        instantiateGame(player_1, inventory, dungeonMap, enemies, items);








        // Display welcome message and initial map
        cout << dialog.GetIntroMessage();
        dungeonMap.DisplayFullMap();
        dungeonMap.DisplayCurrentRoomMap();

        while (true) {


            if (player_1.GetMove() == "quit")
            {
               
                    player_1.RequestPlayerMove();
                    if (player_1.GetMove() == "yes")
                    {

                        clearGameMemory(enemies, items);
                        break;
                    }
                    if (player_1.GetMove() == "no")
                    {
                        playAgain = false;
                        break; 
                    }
                
            }
            // Avoid displaying instructions multiple times
            Room& currentRoom = dungeonMap.GetRoom(dungeonMap.GetCurrentRoomName());
            if (!currentRoom.HasEnemy("IAN") && !currentRoom.HasItem()) {
                cout << dialog.GetInstructions();
            }

            player_1.RequestPlayerMove();

            if (player_1.GetMove() == "stats") {
                player_1.DisplayStats();
            }
            else if (player_1.GetMove() == "inv") {
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
            else if (player_1.GetMove() == "inspect") {
                cout << "Which item would you like to inspect " << endl;
                player_1.RequestPlayerMove();
                inventory.InspectItemFromHotBar(player_1.GetMove(), player_1);
            }
            else {
                dungeonMap.MovePlayerToRoom(player_1.GetMove());
            }

            if (currentRoom.HasItem()) {
                cout << "A " << currentRoom.GetItemAtPlayerPosition().GetItemName() << "is at your current location!" << endl;
                cout << "Enter yes to pick up " << currentRoom.GetItemAtPlayerPosition().GetItemName() << " and no to continue: " << endl;
                player_1.RequestPlayerMove();

                if (player_1.GetMove() == "yes") {
                    inventory.AddItemToInventory(currentRoom.GetItemAtPlayerPosition());
                    currentRoom.RemoveItem(currentRoom.GetPlayerPositionRow(), currentRoom.GetPlayerPositionColumn());  //remove the item from the map
                }
                else if (player_1.GetMove() == "no") {
                    cout << dialog.GetInstructions();  //display instructions after replying no
                }
                else {
                    cout << "Please answer yes or no!" << endl;  //prevent invalid input from breaking the game
                }
            }

        }

    }

    return 0;
}




void instantiateGame(Player& player, Inventory& inventory, Map& dungeon, vector<Enemy*>& enemy, vector<Item*>& item)
{

    srand(static_cast<unsigned>(time(0)));
    int Zenrandint1 = rand() % 3;
    int Zenrandint2 = rand() % 3;

    //overwrites object's current state with a fresh state
    player = Player();
    inventory = Inventory();
    dungeon = Map();
    //add new dynamic objects to a corresponding vector, THESE OBJECTS HAVE TO GET DESTROYED UPON RESTART
    item.push_back(new Item(1, "healing", 1, "A glass bottle filled with a shimmering red liquid ", 15));
    enemy.push_back(new Enemy(50.0, 10.0, 24, 26, 5, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE...."));
    dungeon.GetRoom("zen").AddEnemy(*enemy[0], 1, 1);
    dungeon.GetRoom("zen").AddItem(*item[0], 2, 2);



}

//Clear function to delete all dynamic objects
void clearGameMemory(vector<Enemy*>& enemys, vector<Item*>& items)
{

    //both of this loops interate trhough the vectors and delete the objects, freeing the dynamically allocated memory 
    for (Enemy* enemy : enemys)
    {
        delete enemy;
    }
    //both .clear(), remove any pointers with the vectors
    enemys.clear();
    for (Item* item : items)
    {
        delete item;
    }
    items.clear();
}