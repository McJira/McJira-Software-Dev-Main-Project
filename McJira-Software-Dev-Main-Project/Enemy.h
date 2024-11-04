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
	string enemyName;
	string enemyIntro;
	string enemyOutro;
	bool isAlive; 

public:
	//Default constructor for a default enemy
	Enemy();

	//Constructor to create custom enemies
	Enemy(double h, double dmg, string name, string intro, string outro);

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

	//Getter function for the boolean isAlive to check if the enemy is alive or not
	bool getIsAlive() const;

	//Setter function for the boolean isAlive to check if the enemy is alive or not
	void setIsAlive(bool life);
	//function to make enemy take damage;
	void EnemyTakeDamage(int);
	//Display function for the enemy at the start of the battle
	void displayEnemyInfo() const;
};
