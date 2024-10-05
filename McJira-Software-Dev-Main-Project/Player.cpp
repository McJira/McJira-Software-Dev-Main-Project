// Player class
#include "Player.h"


//void Player::takeDamage() {}
//void Player::collectItem() {}


//Sets initial health to max health when game starts, to be called in constructor
void Player::setInitialHealth()
{
	currentHealth = maxHealth;
}

//funtion to decrease health based on a damage parameter
void Player::takeDamage(int damage)
{

	currentHealth -= damage;

}

void Player::gainHealth(int healAmmount)
{

	currentHealth += healAmmount;

}
//Returns the current health of the player
int Player::getHealth() const
{
	return currentHealth;
}

//initializes the player
Player::Player()
{

	Player::setInitialHealth();

};

//destroys player object instance
Player::~Player()
{

	cout << "Player object destroyed.";

}



