#include "Room.h"


void Room::setRoom(int roomNumber)
{
	room = roomNumber;
}

void Room::setRoomSide(string side)
{
	roomSide = side;
}

void Room::getLocation()
{


	cout << "You are now in room: " << getRoom() << " on side " << getRoomSide() << endl;



}
int Room::getRoom()
{

	return room;

}

string Room::getRoomSide()
{

	return roomSide;

}


Room::Room()
{

	setRoom(1);
	setRoomSide("North");

}





