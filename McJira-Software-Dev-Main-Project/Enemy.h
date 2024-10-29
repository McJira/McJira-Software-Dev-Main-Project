#pragma once
#include <iostream>
#include <string>

using namespace std;

//Class definition for the enemy class
class Enemy
{
private:
	//Define the Enemies attribute variables: Health, Attack Damage, Name and their introduction
	double health;
	double attackDamage;
	string enemyIntro;
	

public:
	//Default constructor for a default enemy
	Enemy() : health(25.0), attackDamage(12.0), enemyIntro("Prepare to fight!") {}

	//Constructor to create custom enemies
	Enemy(double h, double dmg, string name, string intro) : health(h), attackDamage(dmg), enemyIntro(intro) {}

	//Deconstructor for after enemy is defeated
	~Enemy() {}

	//Getter function for the health of the enemy
	double getHealth() const
	{
		return health;
	}

	//Setter function for the health of the enemy
	void setHealth(double h)
	{
		health = h;
	}

	//Getter function for the attack damage of the enemy
	double getAttackDamage(double dmg) const
	{
		return attackDamage;
	}

	//Setter function for the attack damage of the enemy
	void setAttackDamage(double dmg)
	{
		attackDamage = dmg;
	}

	//Getter function for the introduction of the enemy
	string getEnemyIntro() const
	{
		return enemyIntro;
	}

	//Setter function for the introduction of the enemy
	void setenemyIntro(const string& intro)
	{
		enemyIntro = intro;
	}
};
