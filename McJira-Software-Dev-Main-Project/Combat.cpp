#include "Combat.h"
#include <iostream>
#include <conio.h>  
#include <chrono>
#include <thread>

using namespace std;

//Sets the entire width of the attack bar (which is the same for every enemy)
const int attackBarWidth = 50;

//Implement the constructor
Combat::Combat(Player& player, Enemy& enemy) : player(player), enemy(enemy) {}

//Implementation of displayAttackBar function
void Combat::displayAttackBar(int position)
{
    //Gets the hitZone start and End from the values of the Enemy class constructor
    int hitZoneStart = enemy.getHitZoneStart();
    int hitZoneEnd = enemy.getHitZoneEnd();
    system("CLS");  // Clear console screen

    //Create the bar
    for (int i = 0; i < attackBarWidth; i++)
    {
        if (i >= enemy.getHitZoneStart() && i <= enemy.getHitZoneEnd())
        {
            cout << "=";  // Want to change the color of the success zone to green potentially
        }
        else
        {
            cout << "-";  // The characters of the bar that are not the success zone
        }
    }
    cout << endl;

    // Display the sliders position
    for (int i = 0; i < attackBarWidth; i++)
    {
        if (i == position)
        {
            cout << "^";
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
}

//Implementation of the verifyHit function that allows us to check whether the player succeded their attack or not
bool Combat::verifyHit(int position)
{
    //Gets the hitZone start and End from the values of the Enemy class constructor
    int hitZoneStart = enemy.getHitZoneStart();
    int hitZoneEnd = enemy.getHitZoneEnd();

    //Checks if the cursor was stopped in the hitzone by the player but doesn't return true or calse yet
    return (position >= hitZoneStart && position <= hitZoneEnd);
}

//Implementation of the combatMinigame function
bool Combat::combatMinigame()
{
    int position = 0;
    int direction = 1;  //The cursor starts going from right to left

    //A loop that will continue to move the cursor across the bar until the spacebar is pressed which it will then verify the hit
    while (true)
    {
        displayAttackBar(position);

        //Uses the function _kbhit() for console input 
        if (_kbhit())
        {
            char key = _getch();
            if (key == ' ')
            {
                if (verifyHit(position))
                {
                    cout << "Attack Successful!" << endl;
                    return true;
                }
                else
                {
                    cout << "Attack Missed!" << endl;
                    return false;
                }
            }
        }

        //This changes the direction of the cursor if it reaches the end of the bar without the space bar being pressed
        position += direction;
        if (position == 0 || position == attackBarWidth - 1) {
            direction = -direction;
        }

        //The sleep function is responsible for the speed that the cursor moves, it is called from the enemy class object
        //The lower the time value that the enemy has, the faster the cursor will move across the bar, therefore the harder it is to execute a sucessful hit
        std::this_thread::sleep_for(std::chrono::milliseconds(enemy.getAttackSpeed()));
    }
}

//Implementation of the playerAttacks function
void Combat::playerAttacks()
{
    if (combatMinigame())
    {
        int playerDmg = player.GetAttackPower();
        enemy.EnemyTakeDamage(playerDmg);
        cout << "You have dealt " << playerDmg << " damage." << enemy.getEnemyName() << "'s HP is now " << enemy.getHealth() << endl;
    }
    else
    {
        cout << "You missed your attack!" << endl;
    }
}

//Implementation of the enemyAttacks function
void Combat::enemyAttacks()
{
    int enemyDmg = enemy.getAttackDamage();
    player.TakeDamage(enemyDmg);
    cout << enemy.getEnemyName() << " attacks you for " << enemyDmg << " damage.  Your HP is now " << player.GetHealth() << endl;
}

//Implementation of the fight function that is responsible for executing the instantce of combat between the player and the enemy
void Combat::fight()
{
    cout << "You have started your fight with " << enemy.getEnemyName() << "!" << endl;

    //creates a loop that will run until either the player or enemy dies
    while (player.isAlive() && enemy.isAlive())
    {
        //verifys the player succeded their attack
        if (combatMinigame())
        {
            playerAttacks();
        }

        //verifies the enemy didn't die from that attack and exits the function if it did
        if (!enemy.isAlive())
        {
            cout << "You have killed " << enemy.getEnemyName() << "!" << endl;
            break;
        }
        //Now the enemy attacks if it didn't die
        enemyAttacks();

        //Checks if the player is still alive before going back through the loop
        if (!player.isAlive())
        {
            cout << "You have been killed by " << enemy.getEnemyName() << "!" << endl;
        }
    }
}