#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Dialog.h"

using namespace std;


int main() {
	
	
	string move;
	string answer;
	Dialog dialog;
	Room rooms;
	Player Player_1;
	

	cout << dialog.getIntroMessage() << endl;

	rooms.getLocation();
	while (true)
	{
		cout << "Choose room side: " << endl;
		cin >> move;
		Player_1.setMove(move);
		rooms.setRoomSide(move);
		rooms.getLocation();
		if (rooms.getRoomSide() == "South" || rooms.getRoomSide() == "south")
		{

			cout << "A door is infront of you, Would you like to enter: " << endl;
			cin >> answer;

			if (answer == "Yes" || answer == "yes")
			{
				rooms.setRoom(2);
				rooms.setRoomSide("North");
				rooms.getLocation();
			}
			if (answer == "No" || answer == "no")
			{

				continue;

			}

		}

		if (rooms.getRoomSide() == "North" || rooms.getRoomSide() == "north" && rooms.getRoom() == 2)
		{

			cout << "A door is behind of you, Would you like to enter: " << endl;
			cin >> answer;

			if (answer == "Yes" || answer == "yes")
			{
				rooms.setRoom(1);
				rooms.setRoomSide("South");
				rooms.getLocation();
			}
			if (answer == "No" || answer == "no")
			{

				continue;

			}


		}

		



	}



	
	return 0;
}

// Basic Premise: A bunch of CS students at FDU designed an Ian robot to go inside his suit
// Those students graduated, but the AI that drives Ian turned evil and started making minions of his own
// We have one mission, find Ian, get past his goons, and kill him before he destroys FDU
// Professors will act as CPUs, they'll give u advice on where they last saw Ian, give u items/keys/health, or help you move through rooms

 // this will be altered as everyone starts working on their code, I'll have to add more info on how the map works and combat works etc.

// Game class
/*
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
//void Room::enter() {}

// Enemy class
void Enemy::takeDamage() {}
void Enemy::attackPlayer() {}

// Item class
void Item::use() {}

// Trap class
void Trap::trigger() {}

// Inventory class
void Inventory::addItem() {}
void Inventory::removeItem() {}
*/
