

#include "Room.h"
#include "Player.h"

using namespace std;

#pragma once
#include "Room.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Map {
private:
    unordered_map<string, Room> rooms;  //stores rooms by name
    unordered_map<string, vector<string>> connections;  //stores room connections
    string currentRoomName;  //track the player's current room by name

public:
    //constructor to initialize rooms and connections based on input
    Map() {
        //initialize rooms with custom sizes and names
        rooms["Room 1"] = Room(3, 3, "Room 1");
        rooms["Room 2"] = Room(3, 3, "Room 2");
        rooms["Room 3"] = Room(3, 3, "Room 3");
        rooms["Room 4"] = Room(3, 3, "Room 4");
        rooms["Room 5"] = Room(3, 3, "Room 5");

        //define connections based on the diagram in teams
        connections["Room 1"] = { "Room 2", "Room 4", "Room 5" };
        connections["Room 2"] = { "Room 1", "Room 3", "Room 5" };
        connections["Room 3"] = { "Room 2", "Room 5" };
        connections["Room 4"] = { "Room 1", "Room 5" };
        connections["Room 5"] = { "Room 1", "Room 2", "Room 3", "Room 4" };

        //start the player in Room 1
        currentRoomName = "Room 1";
    }

    //display the dungeon map with the player's current room
    void DisplayFullMap() const {
        cout << "Dungeon Map:" << endl;
        for (const auto& room : rooms) {
            cout << room.first << (room.first == currentRoomName ? " [P]" : "") << endl;
        }
        cout << endl;
    }

    //display the map of the current room and show available room connections
    void DisplayCurrentRoomMap() const {
        rooms.at(currentRoomName).DisplayRoomMap();
        //show available rooms the player can move to
        DisplayConnections();
    }

    //display possible room connections from the current room
    void DisplayConnections() const {
        cout << "You can move to the following rooms: ";
        for (const auto& connectedRoom : connections.at(currentRoomName)) {
            cout << connectedRoom << " ";
        }
        cout << endl;
    }

    //move player between connected rooms
    void MovePlayerToRoom(const string& targetRoom) {
        if (find(connections[currentRoomName].begin(), connections[currentRoomName].end(), targetRoom) != connections[currentRoomName].end()) {
            currentRoomName = targetRoom;
            cout << "Moved to " << targetRoom << endl;
        }
        else {
            cout << "No direct connection to " << targetRoom << " from " << currentRoomName << endl;
        }

        DisplayFullMap();
        DisplayCurrentRoomMap();
    }

    //move player within the current room
    void MovePlayerInRoom(char direction) {
        bool moved = rooms[currentRoomName].MovePlayer(direction);
        if (!moved) {
            cout << "Hit the boundary within " << currentRoomName << endl;
        }
        DisplayCurrentRoomMap();
    }
};


/*
class Map {
private:
    Room dungeon[2][2]; //2x2 grid of Room objects (4 rooms)

public:
    //constructor to create the map with 4 rooms
    Map(){
        //creating the 4 rooms. (more will be added later)
        dungeon[0][0] = Room("Entrance", "You have entered into the grand lobby of the mansion.\nThere are locked doors behind you, and a sign above that says Advising Office\nYou can hear a creek in the distance, giving you a feeling you're not alone.\n");
        dungeon[0][1] = Room("Hallway", "You find yourself gazing down the stretch of a long hallway.\nAt the end, you notice that one of the rooms were left open.\nAfter entering, you see something glimmering in the distance, a KEY.\n");
        dungeon[1][0] = Room("Armory", "As you're walking, you hear the clanking of metal.\nImmediately, you fear the worst, but decide to enter anyways.\nInside, you see Professor Vallone hammering away at what looks to be a SWORD.\n ");
        dungeon[1][1] = Room("Treasure Room", "You enter the door. Inside, is a classroom that has become indistinguishable.\n There are desks flipped over, papers torn, and books on fire.\nBehind the chaos sits IAN menacingly, looking for a fight.\n");
    }

    //function to convert a string to lowercase so that the case does not matte  

    void DisplayMap(int,int) const;
    void GetRoomDescription(int x, int y) const;
   
};


*/