#include "Dialog.h"




void Dialog::SetIntroMessage(string introMessage){
	introMessage = INTROMESSAGE;
}

string Dialog::GetIntroMessage() const{

	return INTROMESSAGE;
}

void Dialog::SetUpDescriptionsArray()
{

	roomDescriptions[0][0] = LOBBY_NORTH;
	roomDescriptions[0][1] = LOBBY_EAST;
	roomDescriptions[0][2] = LOBBY_SOUTH;
	roomDescriptions[0][3] = LOBBY_WEST;


}
string Dialog::DisplayRoomSideDescription(int roomNum,string roomSide)
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
	
	return roomDescriptions[roomNum][convertStringToInt];


}




Dialog::Dialog(){

	SetIntroMessage(INTROMESSAGE);
	SetUpDescriptionsArray();

}