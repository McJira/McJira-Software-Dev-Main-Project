#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
#include "Enemy.h"
#include "Item.h"
#include "Inventory.h"
#include "Combat.h"

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



//Function to instantiate all class instances and create pointers to dynamically allocated objects within the vectors
void instantiateGame(Player&, Inventory&, Map&, vector<Enemy*>&, vector<Item*>&);
//Function to delete the dynamically allocated objects within the vectors and free their memory
void clearGameMemory(vector<Enemy*>&, vector<Item*>&);
int main()
{
    srand(static_cast<unsigned>(time(0)));
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
            //returns remaning enemies
            cout << "Remaining enemies: " << Enemy::getRemainingEnemies();

            //This if statement checks for how many enemies are left in the map, for functionallity of getRemainingEnemies() refer to Enemy.cpp and Enemy.h
            if(Enemy::getRemainingEnemies() <= 0) {

                cout << "\n Congrtulations!!!\n You have defeated all the enemies, would you like to restart: \n";

                while (true) {

                    player_1.RequestPlayerMove();
                    if (player_1.GetMove() == "yes"){
                        //upon the request to restart this will clear up all dynamic memory
                        clearGameMemory(enemies, items);
                        break;
                    }
                    if (player_1.GetMove() == "no"){
                        playAgain = false;
                        break;
                    }
                    else{
                        cout << "Enter yes or no \n";
                    }

                }

                break;
               
                    
                
            }
            // Avoid displaying instructions multiple times
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

            // Check if Ian is in the current room and alive
            if (currentRoom.HasEnemy("IAN")) {
                cout << "\nYou encounter Ian!" << endl;
                enemies[0]->displayEnemyInfo();

                //prompt only if Ian's health is above 0
                if (enemies[0]->getHealth() > 0) {
                    cout << "Type IAN if you think you can take him." << endl;
                    player_1.RequestPlayerMove();

                    if (player_1.GetMove() == "ian") {
                        Combat combat(player_1, *enemies[0]);
                        combat.fight();

                        //If Ian is defeated, remove him from the room
                        if (enemies[0]->getHealth() <= 0) {
                            cout << "You have defeated Ian!" << endl;
                            currentRoom.RemoveEnemy(1, 1);
                            //destructs the enemy and decrements remaining enemies
                            enemies[0]->~Enemy();
                        }

                        //Check if the player is still alive
                        if (!player_1.isAlive()) {
                            cout << "You have died. GAME OVER!" << endl;
                            cout << "Would you like to restart: \n";
                            while (true) {
                                
                                player_1.RequestPlayerMove();

                                if (player_1.GetMove() == "yes") {
                                    //upon the request to restart this will clear up all dynamic memory
                                    clearGameMemory(enemies, items);
                                    break;
                                }
                                if (player_1.GetMove() == "no") {
                                    playAgain = false;
                                    break;
                                }
                                else {
                                    cout << "Enter yes or no \n";
                                }

                            }

                            break;

                        }
                    }
                    else {
                        cout << "Invalid input. Try again" << endl;
                    }
                }
            }

            // Check if the current room has an item and if the sword hasn't been picked up
            if (currentRoom.HasItem()) {
                cout << "A " << currentRoom.GetItemAtPlayerPosition().GetItemName() << " is at your current location!" << endl;
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
        if (!playAgain){
            break;
        }

    }

    return 0;
}




void instantiateGame(Player& player, Inventory& inventory, Map& dungeon, vector<Enemy*>& enemy, vector<Item*>& item)
{

    /*
    int Zenrandint1 = rand() % 3;
    int Zenrandint2 = rand() % 3;
    cout << Zenrandint1;
    cout << Zenrandint2;
    */

    //overwrites object's current state with a fresh state
    player = Player();
    inventory = Inventory();
    dungeon = Map();
    Enemy::enemiesRemaining = 0;

    //add new dynamic objects to a corresponding vector, THESE OBJECTS HAVE TO GET DESTROYED UPON RESTART
    item.push_back(new Item(1, "healing", 1, "A glass bottle filled with a shimmering red liquid ", 15));
    item.push_back(new Item(2, "sword", 1, "A Basic Sword", 100));
    enemy.push_back(new Enemy(50.0, 10.0, 24, 26, 5, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE...."));

    dungeon.GetRoom("zen").AddEnemy(*enemy[0], 1, 1);
    dungeon.GetRoom("zen").AddItem(*item[0], 2, 2);
    dungeon.GetRoom("zen").AddItem(*item[1], 3, 3);




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