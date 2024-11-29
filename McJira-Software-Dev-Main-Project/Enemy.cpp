
#pragma once

#include "Enemy.h"
#include <iostream>

using namespace std;

//Implementation of default enemy constructor
Enemy::Enemy() : health(25.0), attackDamage(10.0), enemyIntro("Default Enemy") {

}
//Implementation of custom enemy constructor
Enemy::Enemy(double h, double dmg, int widthS, int widthE, int speed, string name, string intro, string outro) : health(h), attackDamage(dmg), hitZoneStart(widthS), hitZoneEnd(widthE), attackSpeed(speed), enemyName(name), enemyIntro(intro), enemyOutro(outro)
{

	enemiesRemaining++;

}

//Implementation of the deconstructor
Enemy::~Enemy() 
{

;

}

int Enemy::enemiesRemaining = 0;

//Getter for functiojn for enemies remaining
int Enemy::getRemainingEnemies()
{

	return enemiesRemaining;

}
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

//Getter function for the hit zone start of the enemy
int Enemy::getHitZoneStart() const
{
	return hitZoneStart;
}

// Getter function for the hit zone end of the enemy
int Enemy::getHitZoneEnd() const
{
	return hitZoneEnd;
}

//Getter function for the enemies hit zone sliders speed
int Enemy::getAttackSpeed() const
{
	return attackSpeed;
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

void Enemy::EnemyTakeDamage(int damageToBeRecieved)
{

	health -= damageToBeRecieved;
	setHealth(health);
	if (health < 0)
	{
		health = 0;
	}
}

bool Enemy::isAlive() const 
{
	return health > 0;
}

//Display the stats of the enemy at the beginning of the fight
void Enemy::displayEnemyInfo() const
{
	
	cout << "\n" << enemyIntro << endl;
	cout << "\n" << enemyName << " has:\n" << "Health: " << health << "\n" << "Attack Damage: " << attackDamage << endl;
   //cout << "You see IAN's remains on the ground.  You have already defeated him." << endl;
	
}