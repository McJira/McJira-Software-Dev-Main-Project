#include <iostream>
#include "dungeon_game.h"
using namespace std;

int main() {
	cout << "Hello World this is Michael!";
	cout << "Itamar, Was here";
	cout << "Ryan was here";


	cout << "Justine is here"

	cout << "Chris SHapiro was here!";
	return 0;
}

// Game class
void Game::start() {}
void Game::renderRoom() {}
void Game::changeRoom() {}
void Game::combat() {}

// Player class
void Player::attackEnemy() {}
void Player::takeDamage() {}
void Player::collectItem() {}

// Room class
void Room::enter() {}

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
