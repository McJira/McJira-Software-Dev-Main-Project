#include "Dialog.h"




void Dialog::SetIntroMessage(string introMessage){
	introMessage = INTROMESSAGE;
}

string Dialog::GetIntroMessage() const{

	return INTROMESSAGE;
}

string Dialog::DisplayRoomSideDescription(string roomSide)
{
	
	int convertStringToInt;

	if (roomSide == "n")
	{
		convertStringToInt = 0;
	}
	if (roomSide == "e")
	{
		convertStringToInt = 1;
	}
	if (roomSide == "s")
	{
		convertStringToInt = 2;
	}
	if (roomSide == "w")
	{
		convertStringToInt = 3;
	}
	
	return lobbyDescriptions[convertStringToInt];

	//return lobbyDescriptions[roomNum];


}

const string Dialog::LOBBY_NORTH = "You are in the northern side of the lobby, a long hallway is infront of you, to your left a door lay open, a key positioned under it\n";
const string Dialog::LOBBY_EAST = "You are in the eastern side of the lobby, locked doors are infront of you, a sign above says Advising Office\n";
const string Dialog::LOBBY_SOUTH = "You are in the southern side of the lobby, infront of you is a broken stairway, going up, under it lays another stairway going down, locked by gate, a key hole situated inside\n";
const string Dialog::LOBBY_WEST = "You are in the western side of the lobby, double doors lay behind you, to your right lay a couch and a table\n";

const string Dialog::lobbyDescriptions[4] = { Dialog::LOBBY_NORTH, Dialog::LOBBY_EAST, Dialog::LOBBY_SOUTH, Dialog::LOBBY_WEST };

Dialog::Dialog(){

	SetIntroMessage(INTROMESSAGE);

}