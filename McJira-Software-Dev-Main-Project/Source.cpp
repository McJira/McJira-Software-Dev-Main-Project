#include <iostream>
#include "Header.h"
#include "Player.h"
#include "map.h"
#include "Room.h"
using namespace std;

int main() {
	const string introMessage = R"(Welcome to Devils Gone Wild, a dungeon adventure game!

You find yourself in the Math/CS Department in the Zenn at FDU. 

Dr. Darwish has just given you an important mission. 
Last summer, a few of his students took on a project to build Ian, our mascot, a robot exoskeleton. One that could engage with students full time.
However, soon after those students had graduated, Ian 2.0 begun to make decisions on his own. He has begun creating his own minions, setting traps, and has hidden himself away somewhere in FDU.

As you make your way through FDU, be careful. Each room may hold enemies, traps, or items to assist you.
Each time you clear a room, you will be given a list of options on where to go next.
Keep an eye out for other professors along the way, they may give you items and hints on where to go next.

The combat in this game is turn based, you may choose between fighting, using an item, or running to fight another day!
Be sure to strategize, preserve your health, and items to survive Ian's onslaught. 

Dr. Darwish of course would have taken on this mission himself, had he not destroyed his shoulder while moving a car battery.
Are you up for the task? Of course you are!

)";
	
	//Game game;
	Player player_1;//game.start();



	/*
	cout << "Hello World this is Michael!";
	cout << "Itamar, Was here";
	cout << "Ryan was here";

	cout << "Anthony was here";

	cout << "Justine is here"

	Testing branches for player movement - Anthony Gonzalez

	cout << "Chris SHapiro was here!";

	// testing movement branch num 2

	*/
	// Create the map
	cout << introMessage<<endl<<endl;
	// Create the map
	map dungeonMap;
	dungeonMap.DisplayMap();
	while (true) {
		dungeonMap.PlayerMovement();
	}

	// Allow the player to move and interact with the dungeon


}

// Basic Premise: A bunch of CS students at FDU designed an Ian robot to go inside his suit
// Those students graduated, but the AI that drives Ian turned evil and started making minions of his own
// We have one mission, find Ian, get past his goons, and kill him before he destroys FDU
// Professors will act as CPUs, they'll give u advice on where they last saw Ian, give u items/keys/health, or help you move through rooms

; // this will be altered as everyone starts working on their code, I'll have to add more info on how the map works and combat works etc.
/*
// Game class
void Game::displayIntroMessage() {
	cout << introMessage << endl;
}
void Game::start() {
	displayIntroMessage();
	cout << "Now, lets get started!";
}
void Game::renderRoom() {}
void Game::changeRoom() {}
void Game::combat() {}

// Room class
void Room::enter() {}

// Enemy class
void Enemy::takeDamage() {}
void Enemy::attackPlayer() {}

// Item class
//void Item::use() {}

// Trap class
void Trap::trigger() {}

// Inventory class
void Inventory::addItem() {}
void Inventory::removeItem() {}
*/

