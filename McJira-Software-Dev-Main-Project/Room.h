#pragma once
#pragma once


#include <iostream>
#include <string>


using namespace std; 

class Room {
private:
    string RoomName;//name of the room
    

public:
    
    Room() : RoomName("Unnamed") {}//default constructor


    Room(const string& name): RoomName(name){}    //constructor to initialize the room with specific values


    string GetRoomName() const {//getter for RoomName
        return RoomName;
    }


    void SetRoomName(const string& name) {//setter for RoomName
        RoomName = name;
    }


    
    void DisplayRoomInfo() const {//method to display room information
        cout << "Room Name: " << RoomName << endl;

    }
};