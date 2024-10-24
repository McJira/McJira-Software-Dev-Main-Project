#pragma once
#pragma once


#include <iostream>
#include <string>


using namespace std; 

class Room {
private:
    string RoomName;//name of the room
    string RoomDescription;

public:
    
    Room() : RoomName("Unnamed"), RoomDescription("Unavailable") {} //default constructors

    Room(const string& name, const string& description)
        : RoomName(name), RoomDescription(description){}    //constructor to initialize the room with specific values

    string GetRoomName() const { //getter for RoomName
        return RoomName;
    }


    void SetRoomName(const string& name) { //setter for RoomName
        RoomName = name;
    }

    string GetRoomDescription() const { // getter for RoomDesc
        return RoomDescription;
    }

    void SetRoomDescription(const string& description) { // setter for RoomDesc
        RoomDescription = description;
    }

    
    void DisplayRoomInfo() const {//method to display room information
        cout << "Room Name: " << RoomName << endl;
        cout << RoomDescription << endl;
    }
};