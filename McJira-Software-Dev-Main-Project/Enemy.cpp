#include "Enemy.h"
#include <iostream>

using namespace std; 

//Implementation of default enemy constructor
Enemy::Enemy() : health(25.0), attackDamage(10.0), enemyIntro("Default Enemy") {}

//Implementation of custom enemy constructor
Enemy::Enemy(double h, double dmg, string name, string intro, string outro) : health(h), attackDamage(dmg), enemyName(name), enemyIntro(intro), enemyOutro(outro) {}

//Implementation of the deconstructor
Enemy::~Enemy() {}

//Getter function for the health of the enemy
double Enemy::getHealth() const
{
	return health;
}

//Setter function for the health of the enemy
void Enemy::setHealth(double h)
{
	health = h;
}

//Getter function for the attack damage of the enemy
double Enemy::getAttackDamage() const
{
	return attackDamage;
}

//Setter function for the attack damage of the enemy
void Enemy::setAttackDamage(double dmg)
{
	attackDamage = dmg;
}

//Getter function for the name of the enemy
string Enemy::getEnemyName() const
{
	return enemyName;
}

//Setter function for the name of the enemy
void Enemy::setenemyName(const string& name)
{
	enemyName = name;
}

//Getter function for the introduction of the enemy
string Enemy::getEnemyIntro() const
{
	return enemyIntro;
}

//Setter function for the introduction of the enemy
void Enemy::setenemyIntro(const string& intro)
{
	enemyIntro = intro;
}

//Getter function for the outro of the enemy
string Enemy::getEnemyOutro() const
{
	return enemyOutro;
}

//Setter function for the introduction of the enemy
void Enemy::setenemyOutro(const string& outro)
{
	enemyOutro = outro;
}


//Getter function for the boolean isAlive to check if the enemy is alive or not
bool Enemy::getIsAlive() const
{
	return isAlive;
}

//Setter function for the boolean isAlive to check if the enemy is alive or not
void Enemy::setIsAlive(bool life)
{
	isAlive = life;
}

//Display the stats of the enemy at the beginning of the fight
void Enemy::displayEnemyInfo() const
{
	if(isAlive)
	{
		cout << "\n" << enemyIntro << endl;
		cout << "\n" << enemyName << " has:\n" << "Health: " << health << "\n" << "Attack Damage: " << attackDamage << endl;
	}
	else
	{
		cout << "You see IAN's remains on the ground.  You have already defeated him." << endl;
	}
}