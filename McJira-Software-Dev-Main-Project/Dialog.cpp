#include "Dialog.h"


void Dialog::SetIntroMessage(string introMessage){
	introMessage = INTROMESSAGE;
}

string Dialog::GetIntroMessage() const{

	return INTROMESSAGE;

}

Dialog::Dialog(){

	SetIntroMessage(INTROMESSAGE);

}