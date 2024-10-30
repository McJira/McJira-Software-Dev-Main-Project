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
        : RoomName(name), RoomDescription(description) {}    //constructor to initialize the room with specific values

    string GetRoomName() const;



    void SetRoomName(const string& name);

    string GetRoomDescription() const;

    void SetRoomDescription(const string& description);

    void DisplayRoomInfo() const;

};
