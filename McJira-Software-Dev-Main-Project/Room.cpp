#include "Room.h"



string Room::GetRoomName() const{ //getter for RoomName

    return RoomName;
}

void Room::SetRoomName(const string& name) { //setter for RoomName
    RoomName = name;
}

string Room::GetRoomDescription() const { // getter for RoomDesc
    return RoomDescription;
}

void Room::SetRoomDescription(const string& description) { // setter for RoomDesc
    RoomDescription = description;
}

void Room::DisplayRoomInfo() const { //method to display room information
    cout << "Room Name: " << RoomName << endl;
    cout << RoomDescription << endl;
}