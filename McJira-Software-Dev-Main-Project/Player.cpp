// Player class
#include "Player.h"


//void Player::takeDamage() {}
//void Player::collectItem() {}


//Sets initial health to max health when game starts, to be called in constructor
void Player::SetInitialHealth()
{
	currentHealth = maxHealth;
}

//funtion to decrease health based on a damage parameter
void Player::TakeDamage(int damage)
{

	currentHealth -= damage;

}

void Player::GainHealth(int healAmmount)
{

	currentHealth += healAmmount;

}

//Sets the players move based on input
void Player::SetMove(string move)
{

	this->move = move;

}

void Player::SetPlayerAxisX(int playerAxisXLocation){


	this->playerAxisXLocation = playerAxisXLocation;

}

void Player::SetPlayerAxisY(int playerAxisYLocation) {


	this->playerAxisYLocation = playerAxisYLocation;

}

//Returns the current health of the player
int Player::GetHealth() const
{
	return currentHealth;
}

int Player::GetPlayerAxisX() const {

	return playerAxisXLocation;

}
int Player::GetPlayerAxisY() const {

	return playerAxisYLocation;

}

int Player::GetAttackPower() const

{
    return attackPower;
}

// Displays the player's stats (health and attack power)
void Player::DisplayStats() const
{
    cout << "Player Stats:" << endl;
    cout << "Health: " << currentHealth << "/" << maxHealth << endl;
    cout << "Attack Power: " << attackPower << endl;
}


void Player::PlayerMovement(string inputDirection) {  //function to prompt the user for movement move

    if ((inputDirection == "north" || inputDirection == "n") && GetPlayerAxisY() > 0) {      //handle movement based on the direction entered, also makes sure the move is within the array.
        SetPlayerAxisY(GetPlayerAxisY() - 1);
    }
    else if ((inputDirection == "south" || inputDirection == "s") && GetPlayerAxisY() < 1) {
        SetPlayerAxisY(GetPlayerAxisY() + 1);
    }
    else if ((inputDirection == "east" || inputDirection == "e") && GetPlayerAxisX() < 1) {
        SetPlayerAxisX(GetPlayerAxisX() + 1);

    }
    else if ((inputDirection == "west" || inputDirection == "w") && GetPlayerAxisX() > 0) {
        SetPlayerAxisX(GetPlayerAxisX() - 1);
    }
    else {
        cout << "Invalid move! You can't move in that direction." << endl;
    }

    //display current room after movement
}

//Gets the players move 
string Player::GetMove() const
{
	return move;
}



//initializes the player
Player::Player()
{

	Player::SetInitialHealth();
	Player::SetPlayerAxisX(0);
	Player::SetPlayerAxisY(0);

};

//destroys player object instance
Player::~Player()
{

	cout << "Player object destroyed.";

}



