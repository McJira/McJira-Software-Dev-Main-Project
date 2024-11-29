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
#include "Sounds.h"
using namespace std;

/*

USE THIS SECTION FOR NEEDED SPECIFICATIONS

ITEM ID's:

1. healing potion ID: 1
2. basic sword ID: 2
3. Add more when adding new items please, this will be used with the inventory

*/

//Function to instantiate all class instances and create pointers to dynamically allocated objects within the vectors
void instantiateGame(Player&, Inventory&, Map&, vector<Enemy*>&, vector<Item*>&);
//Function to delete the dynamically allocated objects within the vectors and free their memory
void clearGameMemory(vector<Enemy*>&, vector<Item*>&);

int main() {
    

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
            cout << Enemy::getRemainingEnemies();

            //This if statement checks for how many enemies are left in the map, for functionallity of getRemainingEnemies() refer to Enemy.cpp and Enemy.h
            if (Enemy::getRemainingEnemies() <= 0) {

                cout << "\n Congrtulations!!!\n You have defeated all the enemies, would you like to restart: \n";

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
                        cout << "Player enter yes or no \n";
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
                            enemies[0]->getEnemyOutro();//display ians outro
                            cout << "You have defeated Ian!" << endl;
                            currentRoom.RemoveEnemy(1, 1);
                            //destructs the enemy and decrements remaining enemies
                            enemies[0]->~Enemy();
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

            // Check if Robotic Staff is in the current room and alive
            if (currentRoom.HasEnemy("Robotic Staff")) {
                cout << "\nYou encounter Robotic Staff!" << endl;
                enemies[1]->displayEnemyInfo();

                //prompt only if Ian's health is above 0
                if (enemies[1]->getHealth() > 0) {
                    cout << "Type rob if you think you can take him." << endl;
                    player_1.RequestPlayerMove();

                    if (player_1.GetMove() == "rob") {
                        Combat combat2(player_1, *enemies[1]);
                        combat2.fight();

                        //If Robot staff is defeated, remove him from the room
                        if (enemies[1]->getHealth() <= 0) {
                            enemies[1]->getEnemyOutro();//display Robots outro
                            cout << "You have defeated Ian!" << endl;
                            currentRoom.RemoveEnemy(1, 1);
                            //destructs the enemy and decrements remaining enemies
                            enemies[1]->~Enemy();
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

            if (currentRoom.HasEnemy("Ian's Minion")) {
                cout << "\nYou encounter Ian's Minion" << endl;
                enemies[2]->displayEnemyInfo();

                //prompt only if Ian's health is above 0
                if (enemies[2]->getHealth() > 0) {
                    cout << "Type ianmin if you think you can take him." << endl;
                    player_1.RequestPlayerMove();

                    if (player_1.GetMove() == "ianmin") {
                        Combat combat3(player_1, *enemies[2]);
                        combat3.fight();

                        //If Robot staff is defeated, remove him from the room
                        if (enemies[2]->getHealth() <= 0) {
                            enemies[2]->getEnemyOutro();//display Robots outro
                            cout << "You have defeated Ian!" << endl;
                            currentRoom.RemoveEnemy(1, 1);
                            //destructs the enemy and decrements remaining enemies
                            enemies[2]->~Enemy();
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

            if (currentRoom.HasEnemy("Statue")) {
                cout << "\nYou encounter the Statue!" << endl;
                enemies[3]->displayEnemyInfo();

                // Only prompt the player if the Statue's health is above 0
                if (enemies[3]->getHealth() > 0) {
                    cout << "Type 'statue' if you think you can defeat it." << endl;
                    player_1.RequestPlayerMove();

                    if (player_1.GetMove() == "statue") {
                        Combat combat4(player_1, *enemies[3]);
                        combat4.fight();

                        // If the Statue is defeated, remove it from the room
                        if (enemies[3]->getHealth() <= 0) {
                            cout << enemies[3]->getEnemyOutro(); // Display Statue's outro
                            cout << "You have defeated the Statue! The path is now clear." << endl;
                            currentRoom.RemoveEnemy(0, 0); // Ensure the correct coordinates are used
                            // Destruct the enemy and decrement the remaining count
                            enemies[3]->~Enemy();
                        }

                        // Check if the player is still alive after combat
                        if (!player_1.isAlive()) {
                            cout << "You have been defeated by the Statue. GAME OVER!" << endl;
                            return 0;
                        }
                    }
                    else {
                        cout << "Invalid input. Try again." << endl;
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
        if (!playAgain) {
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
    enemy.push_back(new Enemy(25, 5.0, 10.0, 30, 10, "Robotic Staff", "Hey,get out of here", "You have Bested me!"));
    enemy.push_back(new Enemy(40, 10, 20, 30, 5, "Ian's Minion", "You encounter one of Ian's Minions! It growls and prepares to attack you.","The Minion collapses to the ground, defeated. You feel a small sense of victory."));
    enemy.push_back(new Enemy(60, 5, 22, 28, 5, "Statue", "The Statue stands tall, its stone eyes glowing red as it comes to life. This is the guardian of the Zen, and it won't let you pass without a fight.","The Statue crumbles into a pile of rubble, its red eyes fading. The path to the Zen is now clear."));


    dungeon.GetRoom("zen").AddEnemy(*enemy[0], 1, 1);//Ian
    dungeon.GetRoom("hennessy hall").AddEnemy(*enemy[1], 2, 3);//Robotic Staff
    dungeon.GetRoom("hennessy hall").AddEnemy(*enemy[2], 3, 3);//Ian's minion
    dungeon.GetRoom("zen").AddEnemy(*enemy[3], 2, 3); // Statue

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