#include "Room.h"



void Room::setRoom(int roomNumber)
{
	//sets the room variable with a given room input
	room = roomNumber;
}

void Room::setRoomSide(string side)
{
	//sets the roomSide variable with a given room side input
	roomSide = side;
}

void Room::getLocation()
{

	//retrieves the location of the player

	cout << "You are now in room: " << getRoom() << " on side " << getRoomSide() << endl;



}
int Room::getRoom()
{
	//retrieves the current room
	return room;

}

string Room::getRoomSide()
{

	//retrieves the current room side
	return roomSide;

}


Room::Room()
{

	//Constructs the spawn location of the player
	setRoom(1);
	setRoomSide("North");

}





