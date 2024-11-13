#pragma once
#include "Player.h"
#include "Enemy.h"

class Combat
{
private:
	Player& player;
	Enemy& enemy;

public:
	//default constructor
	Combat();
	//Constructor that takes an object from the player and enemy class
	Combat(Player& player, Enemy& enemy);

	//registers attacks to the players and enemies
	void playerAttacks();
	void enemyAttacks();

	//Functions to execute the attack timining mini game
	void displayAttackBar(int position);
	bool verifyHit(int position);
	bool combatMinigame();

	//Defines fight function
	void fight();
};
