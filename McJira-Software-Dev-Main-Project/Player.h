#ifndef PLAYER_H
#define PLAYER_H
#include "InputValidation.h"
#include <iostream>

using namespace std;

class Player
{
public:

	//Setter Functions
	void TakeDamage(int);
	void GainHealth(int);
	void SetPlayerAxisX(int);
	void SetPlayerAxisY(int);
	void SetMove(string);
	void SetInitialHealth();
	void DisplayStats() const;

	//Getter Functions
	string GetMove() const;
	int GetHealth() const;
	int GetPlayerAxisX() const;
	int GetPlayerAxisY() const;
	int GetAttackPower() const;
	
	//Other Functions
	void PlayerMovement(string);
	void RequestPlayerMove();

	//Constructors
	Player();
	~Player();

private:

	int maxHealth = 100;
	int attackPower = 10;
	int currentHealth;
	int playerAxisXLocation;
	int playerAxisYLocation;
	string move;
	InputValidation validate;





};

#endif 
