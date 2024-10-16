#include "Dialog.h"


string Dialog::getIntroMessage()
{

	return INTROMESSAGE;

}

//array to return discriptions based on room number 
	//*room side to be added, as a string input?
string Dialog::dialogArray(int roomNumber)
{

	return discriptionsArray[roomNumber];

}
