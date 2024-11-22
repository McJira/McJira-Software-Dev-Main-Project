#ifndef ENEMY_H
#define ENEMY_H

#pragma once
#include <iostream>
#include <string>

using namespace std;

//Class definition for the enemy class
class Enemy
{
private:

	

	static int enemiesRemaining; // This variable corresponds to the amount of enemies instanced and destoryed(check constructor and destructor)

	//Define the Enemies attribute variables: Health, Attack Damage, Name, their introduction and outro
	double health;
	double attackDamage;
	int hitZoneStart;
	int hitZoneEnd;
	int attackSpeed;
	string enemyName;
	string enemyIntro;
	string enemyOutro;

public:
	//Default constructor for a default enemy
	Enemy();

	//Constructor to create custom enemies
	Enemy(double h, double dmg, int widthS, int widthE, int speed, string name, string intro, string outro);

	//Deconstructor for after enemy is defeated
	~Enemy();

	//Getter function for the health of the enemy
	double getHealth() const;

	//Setter function for the health of the enemy
	void setHealth(double h);

	//Getter function for the attack damage of the enemy
	double getAttackDamage() const;

	//Setter function for the attack damage of the enemy
	void setAttackDamage(double dmg);

	//Getter Function for the hit zone start of the enemy
	int getHitZoneStart() const;

	//Getter Function for the hit zone end of the enemy
	int getHitZoneEnd() const;

	//Getter function for the attack speed required
	int getAttackSpeed() const;

	//Getter function for the amount of enemies left
	static int getRemainingEnemies();

	//Getter function for the name of the enemy
	string getEnemyName() const;

	//Setter function for the name of the enemy
	void setenemyName(const string& name);

	//Getter function for the introduction of the enemy
	string getEnemyIntro() const;

	//Setter function for the introduction of the enemy
	void setenemyIntro(const string& intro);

	//Getter function for the outro of the enemy
	string getEnemyOutro() const;

	//Setter function for the outro of the enemy
	void setenemyOutro(const string& outro);

	//Function to check if enemy is alive
	bool isAlive() const;

	//function to make enemy take damage;
	void EnemyTakeDamage(int);

	//Display function for the enemy at the start of the battle
	void displayEnemyInfo() const;
};

#endif // !ENEMY_H
