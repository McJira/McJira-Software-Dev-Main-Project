#pragma once
#include <iostream>
using namespace std;



/*

jobs of the room class:

#1. Create rooms
	*discriptions to be incorporated from seperate classes
	
#2. Contains the location of the player

#3. To be used together with either a movement class or the player class

*/



class Room
{


public:

	//function to return current room the player is in
	int getRoom();
	//function to return current room side the player is in
	string getRoomSide();
	//function to set room
	void setRoom(int);
	//function to set room side
	void setRoomSide(string);
	//function to return the current location of the player
	void getLocation();
	//Constructs to set the spawn room and room side
	Room();





private:

	//room var to set what room the player is in or moves to
	int room;
	//room side var to set what side of the room the player is in or moves to
	string roomSide;




};