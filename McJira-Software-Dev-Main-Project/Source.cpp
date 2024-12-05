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
#include "Instances.h"
using namespace std;

/*

USE THIS SECTION FOR NEEDED SPECIFICATIONS

ITEM ID's:

1. healing potion ID: 1
2. all strength potion ID: 2
3. Add more when adding new items please, this will be used with the inventory


WHEN ADDING AN ENEMY UPDATE THAT ENEMY ID TO THE NUMBER AFTER THE LAST ENEMY ID
UPDATE THIS DOCUMENT ACCORDINGLY PLEASE

Enemy ID's: 

1. IAN ID: 0
2. Robotic Staff: 1
3. IANS minion: 2
4. Statue: 3

*/

//Function to instantiate all class instances and create pointers to dynamically allocated objects within the vectors
void instantiateGame(Player&, Inventory&, Map&, vector<Enemy*>&, vector<Item*>&, vector<Instance*>&);
//Function to delete the dynamically allocated objects within the vectors and free their memory
void clearGameMemory(vector<Enemy*>&, vector<Item*>&, vector<Instance*>&);

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
        vector<Instance*>instances;
        instantiateGame(player_1, inventory, dungeonMap, enemies, items, instances);

        // Display welcome message and initial map
        cout << dialog.GetIntroMessage();
        dungeonMap.DisplayFullMap();
        dungeonMap.DisplayCurrentRoomMap();
        while (true) {

            //This if statement checks for how many enemies are left in the map, for functionallity of getRemainingEnemies() refer to Enemy.cpp and Enemy.h
            if (Enemy::getRemainingEnemies() <= 0) {

                cout << "\n Congrtulations!!!\n You have defeated all the enemies, would you like to restart: \n";

                while (true) {

                    player_1.RequestPlayerMove();
                    if (player_1.GetMove() == "yes") {
                        //upon the request to restart this will clear up all dynamic memory
                        clearGameMemory(enemies, items, instances);
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
            else if (player_1.GetMove() == "inv" || player_1.GetMove() == "inventory") { // in case user types in inventory instead
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
            else if (player_1.GetMove() == "remaining") {
                cout << "Enemies remaining: " << Enemy::getRemainingEnemies() << endl;
            }
            else {
                dungeonMap.MovePlayerToRoom(player_1.GetMove());
            }

            // Check if there is an Enemy in the player's current position
            if (currentRoom.isEnemyAtPlayerPosition()) {
                cout << "\nYou encounter " << currentRoom.GetEnemyAtPlayerPosition()->getEnemyName();
                enemies[currentRoom.GetEnemyAtPlayerPosition()->getEnemyID()]->displayEnemyInfo();

                //prompt only if Ian's health is above 0
                if (enemies[currentRoom.GetEnemyAtPlayerPosition()->getEnemyID()]->getHealth() > 0) {
                    cout << "Type " << currentRoom.GetEnemyAtPlayerPosition()->getEnemyName() << " if you think you can take them out\n";
                    player_1.RequestPlayerMove();

                    if (player_1.GetMove() == inputValid.convertInCodeNameToLowerCase(currentRoom.GetEnemyAtPlayerPosition()->getEnemyName())) {
                        Combat combat(player_1, *enemies[currentRoom.GetEnemyAtPlayerPosition()->getEnemyID()]);
                        combat.fight();

                        //If Ian is defeated, remove him from the room
                        if (enemies[currentRoom.GetEnemyAtPlayerPosition()->getEnemyID()]->getHealth() <= 0) {
                            enemies[currentRoom.GetEnemyAtPlayerPosition()->getEnemyID()]->getEnemyOutro();//display ians outro
                            currentRoom.RemoveEnemy();
                            //destructs the enemy and decrements remaining enemies
                            Enemy::enemiesRemaining--;
                        }

                        //Check if the player is still alive
                        if (!player_1.isAlive()) {
                            cout << "You have died. GAME OVER!" << endl;
                            cout << "Would you like to restart: " << endl;
                            while (true) {

                                player_1.RequestPlayerMove();
                                if (player_1.GetMove() == "yes") {
                                    //upon the request to restart this will clear up all dynamic memory
                                    clearGameMemory(enemies, items, instances);
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

            // checks if current room has an instance
            if (currentRoom.HasInstance())
            {
                cout << "You see " << currentRoom.GetInstanceAtPlayerPosition().GetInstanceName() << ". Type yes to talk with them, or no to continue!" << endl;
                player_1.RequestPlayerMove();

                if (player_1.GetMove() == "yes") {
                    cout << currentRoom.GetInstanceAtPlayerPosition().GetInstanceDescription();
                    currentRoom.RemoveInstance(currentRoom.GetPlayerPositionRow(), currentRoom.GetPlayerPositionColumn());  //remove the item from the map
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


void instantiateGame(Player& player, Inventory& inventory, Map& dungeon, vector<Enemy*>& enemy, vector<Item*>& item, vector<Instance*>& instances)
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
    item.push_back(new Item(2, "strength", 1, "A glass bottle filled with a dull grey liquid", 10));
    item.push_back(new Item(2, "strengthplus", 1, "A bottle filled with a black shimmering liquid", 20));
    item.push_back(new Item(2, "strengthsuper", 1, "A bottle labeled super strength with an, almost alive looking, liquid moving within", 30));
    enemy.push_back(new Enemy(50.0, 10.0, 24, 26, 5, 0, "IAN", "I am IAN! You really think you can defeat me? Give it your best shot!", "no... NOO... THIS CAN'T BE...."));
    enemy.push_back(new Enemy(25, 5.0, 10.0, 30, 10, 1, "Robotic Staff", "Hey,get out of here", "You have Bested me!"));
    enemy.push_back(new Enemy(40, 10, 20, 30, 5, 2, "Ian's Minion", "You encounter one of Ian's Minions! It growls and prepares to attack you.","The Minion collapses to the ground, defeated. You feel a small sense of victory."));
    enemy.push_back(new Enemy(60, 5, 22, 28, 5, 3,"Statue", "The Statue stands tall, its stone eyes glowing red as it comes to life. This is the guardian of the Zen, and it won't let you pass without a fight.","The Statue crumbles into a pile of rubble, its red eyes fading. The path to the Zen is now clear."));
    //enemy.push_back(new Enemy(30, 5, 15, 30, 5, 7, "Knorr Bot", "The Knorr Bot rolls into the room, chalk in hand, ready to test your understanding of quantum mechanics. 'Are you prepared to face the forces of physics? I am, quite literally, a force to be reckoned with!", "With a mechanical whine, the Knorr Bot collapses into a heap of wires and broken chalk. 'Even a perfect theory can break under pressure...'"));

    //boss enemies
    enemy.push_back(new Enemy(100, 15, 22, 28, 5, 4, "Ian The Devil", "You enter the Rec Center gym at FDU, the lights flicker and a sinister presence fills the air. Ian the Devil steps forward from the shadows, his voice echoing: 'So, you've dared to challenge me in my domain—your final workout begins now!", "With a final roar, Ian the Devil collapses onto the gym floor, his power fading away. As the Rec Center gym grows quiet, his voice lingers: 'You may have defeated me, but the strength of the darkness will haunt this place forever."));
    enemy.push_back(new Enemy(120, 20, 24, 26, 10, 5, "Alva Dean Bot", "The Alva Dean Bot stands atop the Dreyfuss auditorium stage, holding a gavel in one hand and a stack of papers in the other. 'You've come to challenge my authority? Your time at this university ends now!", "The Dean of Doom drops his gavel, sighing as he fades into the shadows. 'Your degree may survive, but will your spirit endure"));
    enemy.push_back(new Enemy(150, 25, 24, 26, 10, 6, "The Devil of Dickinson", "The lights in Hennessy Hall dim as an ominous laugh echoes. The Devil of Dickinson emerges from a fiery portal, his glowing eyes fixed on you. 'So, you've made it this far... But this is where your journey ends!", "With a final roar, the Devil of Dickinson collapses into the ground, his fiery form fading into smoke. 'This battle is yours... but the war is eternal..."));

    //normal enemies
    enemy.push_back(new Enemy(30, 5, 15, 30, 5, 7, "Knorr Bot", "The Knorr Bot rolls into the room, chalk in hand, ready to test your understanding of quantum mechanics. 'Are you prepared to face the forces of physics? I am, quite literally, a force to be reckoned with!", "With a mechanical whine, the Knorr Bot collapses into a heap of wires and broken chalk. 'Even a perfect theory can break under pressure...'"));
    enemy.push_back(new Enemy(30, 5, 15, 30, 5, 8, "Zhu Bot", "A soft but determined voice greets you as the Prof Zhu Bot enters the room, holding a piece of chalk and a laser pointer. 'Welcome to the advanced physics challenge. I hope you're ready to learn... or to fail. The laws of motion will decide your fate!'", "With a calm smile, Prof Zhu Bot steps back, saying, 'You have proven your mastery over the forces of the universe. Remember, knowledge is the ultimate power.' The bot powers down gracefully."));


    // adding instances as new dynamic objects
    instances.push_back(new Instance("Dr. Sinha", "\nDr. Sinha seems frustrated, so you ask her what's bothering her. \n'I'm becoming increasingly worried about how many weapons are on this campus'\n Sinha huffs, 'Isn't this supposed to be a closed campus? Where is public safety?\n'Why am I even here? I'm supposed to be on sabbatical. They don't pay me enough for this...'\n She wanders away.\n\n"));
    instances.push_back(new Instance("Prof. Vallone", "\n'You enter a room to see Prof. Vallone stuck in a trap.\n'I tried making traps to avoid direct confontation with the robots, but they pushed me in!'\n'Please help me, I'll give you anything! Apples, cookies, even Scrum Legos!'\nAfter hearing Scrum Legos, you are filled with excitement and determination. \nYou release Prof. Vallone, and he thanks you.\n\n"));
    instances.push_back(new Instance("Dr. Singh", "\nYou see Dr. Singh huddled over something in the back corner of an empty classroom.\nAs you get closer, you see him picking away at the skin of a public safety officer.\nBefore screaming, you realize that underneath the skin are layers and layers of wiring.\nDr. Singh states, 'It seems as though these Ian robots have been infiltrating our campus, replacing people with their own,'\n'That explains why public safety isn't helping us! Now excuse me, I need to concentrate...'\n\n")); 
    instances.push_back(new Instance("Dr. Darwish", "\nYou wave at Dr. Darwish and he seems pleased to see you haven't been torn to pieces. \nAll of a sudden, his expression changes. He screams, 'Watch out!'. \nAn Ian Minion comes up behind you and puts you in a chokehold! \nAs you watch your life flash before your eyes, Dr. Darwish spills coffee on it and it immediately dies. \n'Think smarter not harder', Darwish laughs. You leave much sticker than you came in.\n\n")); 


    dungeon.GetRoom("zen").AddEnemy(*enemy[0], 1, 1);//Ian
    dungeon.GetRoom("hennessy hall").AddEnemy(*enemy[1], 2, 3);//Robotic Staff
    dungeon.GetRoom("hennessy hall").AddEnemy(*enemy[2], 3, 3);//Ian's minion
    dungeon.GetRoom("zen").AddEnemy(*enemy[3], 2, 3); // Statue
    
    //bosses
    dungeon.GetRoom("rec center").AddEnemy(*enemy[4], 2, 2); //Ian The Devil
    dungeon.GetRoom("dreyfuss").AddEnemy(*enemy[5], 3, 3); //Alva Dean Bot
    dungeon.GetRoom("hennessy hall").AddEnemy(*enemy[6], 2, 5);//Devil of Dickinson
    //normal enemies
    dungeon.GetRoom("science building").AddEnemy(*enemy[7], 1, 1);
    dungeon.GetRoom("science building").AddEnemy(*enemy[8], 2, 2);




    dungeon.GetRoom("zen").AddItem(*item[0], 2, 2);
    dungeon.GetRoom("zen").AddItem(*item[1], 3, 3);
    dungeon.GetRoom("hennessy hall").AddItem(*item[2], 3, 1);
    dungeon.GetRoom("hennessy hall").AddItem(*item[0], 1, 1);
    dungeon.GetRoom("dreyfuss").AddItem(*item[0], 3, 3);
    dungeon.GetRoom("dreyfuss").AddItem(*item[3], 1, 3);



    // one instance per room
    dungeon.GetRoom("zen").AddInstance(*instances[0], 3, 1); // Sinha
    dungeon.GetRoom("hennessy hall").AddInstance(*instances[1], 1, 3); // Vallone
    dungeon.GetRoom("rec center").AddInstance(*instances[2], 2, 1); // Singh
    dungeon.GetRoom("dreyfuss").AddInstance(*instances[3], 3, 2); // Darwish





}

//Clear function to delete all dynamic objects
void clearGameMemory(vector<Enemy*>& enemys, vector<Item*>& items, vector<Instance*>& instances)
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
    for (Instance* instance : instances) {
        delete instance;
    }
    instances.clear();
}