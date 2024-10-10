#pragma once
#include <iostream>
using namespace std;

class Room
{

public:

	int getRoom();
	string getRoomSide();
	void setRoom(int);
	void setRoomSide(string);
	void getLocation();
	Room();





private:

	int room;
	string roomSide;




};