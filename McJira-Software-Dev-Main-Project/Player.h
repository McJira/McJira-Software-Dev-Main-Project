#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
public: 

	
	void takeDamage(int);
	//void gainHealth(int);

	//void setMove(string);
	void setInitialHealth();
	//void setCurrentPosition(int);

	//string getMove() const;
	int getHealth() const;
	//int getCurrentPosition() const;

    Player();
	~Player();

private:

	int maxHealth = 100;
	int currentHealth;
	string move;





};

#endif 