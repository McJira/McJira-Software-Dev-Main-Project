#include "Movement.h"

void room1(string);

void Movement::ChangeLocation(string move)
{
	room1(move);

}

void room1(string move )
{
	if(move == "North")
	{
		cout << "You went to the fountain";
	}
	
	if (move == "South")
	{
		cout << "You went to the mall";
	}


}
