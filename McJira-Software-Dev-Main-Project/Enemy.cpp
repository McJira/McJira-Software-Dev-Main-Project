#include "Enemy.h"

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
double Enemy::getAttackDamage(double dmg) const
{
	return attackDamage;
}

//Setter function for the attack damage of the enemy
void Enemy::setAttackDamage(double dmg)
{
	attackDamage = dmg;
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