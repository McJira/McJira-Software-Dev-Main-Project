#include <iostream>
#include "Player.h"
#include "InputValidation.h"
#include "Map.h"
#include "Room.h"
#include "Dialog.h"
using namespace std;

int main() {

	
	string playerInput;
	InputValidation inputValid;

	Player player_1;
	
	Dialog dialog;
	Map dungeonMap;

	dialog.GetIntroMessage();
	dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());

	while (true) {
		cin >> playerInput;
		inputValid.ToLowerCase(playerInput);
		if (playerInput == "m")
		{
			dungeonMap.DisplayMap(player_1.GetPlayerAxisX(), player_1.GetPlayerAxisY());
		}
		else
		{
			player_1.PlayerMovement(playerInput);
		}
	}



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

