// In Map.h
#pragma once

#include "Room.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Map {
private:
    unordered_map<string, Room> rooms;  // Stores rooms by name
    unordered_map<string, vector<string>> connections;  // Stores room connections
    unordered_map<string, string> shorthandToFullName; // Stores Shorthadn names making it easier to move rooms for the player.
    string currentRoomName;  // Track the player's current room by name

public:
    //constructor to initialize rooms and connections
    Map() {
        //initialize rooms with custom sizes and names
        rooms["Zen"] = Room(4, 4, "Zen");
        rooms["Hennessy Hall"] = Room(4, 6, "Hennessy Hall");
        rooms["Science Building"] = Room(4, 4, "Science Building");
        rooms["Rec Center"] = Room(4, 3, "Rec Center");
        rooms["Dreyfuss"] = Room(5, 4, "Dreyfuss");

        //define connections based on the diagram
        connections["Zen"] = { "Hennessy Hall", "Rec Center", "Dreyfuss" };
        connections["Hennessy Hall"] = { "Zen", "Science Building", "Dreyfuss" };
        connections["Science Building"] = { "Hennessy Hall", "Dreyfuss" };
        connections["Rec Center"] = { "Zen", "Dreyfuss" };
        connections["Dreyfuss"] = { "Zen", "Hennessy Hall", "Science Building", "Rec Center" };

        //define shorthand mappings
        shorthandToFullName["Z"] = "Zen";
        shorthandToFullName["HH"] = "Hennessy Hall";
        shorthandToFullName["SB"] = "Science Building";
        shorthandToFullName["RC"] = "Rec Center";
        shorthandToFullName["D"] = "Dreyfuss";
        //start the player in Zen
        currentRoomName = "Zen";
    }
    string GetCurrentRoomName() const {
        return currentRoomName;
    }

    Room& GetRoom(const string& roomName) {
        return rooms.at(roomName);  //assumes roomName exists
    }
    //method to add an enemy to a specific room by name
    bool AddEnemyToRoom(const string& roomName, Enemy& enemy, int x, int y) {
        if (rooms.find(roomName) != rooms.end()) {
            return rooms[roomName].AddEnemy(enemy, x, y);
        }
        else {
            cout << "Room " << roomName << " does not exist." << endl;
            return false;
        }
    }
    //this function shows the player where they can move from there current room.
    void DisplayConnections() const {
        cout << "You can move to the following rooms: ";
        const auto& connectedRooms = connections.at(currentRoomName);

        for (size_t i = 0; i < connectedRooms.size(); ++i) {
            cout << connectedRooms[i];
            if (i < connectedRooms.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    //display the dungeon map with the player's current room
    void DisplayFullMap() const {
        cout << "Dungeon Map:" << endl;
        for (const auto& room : rooms) {
            cout << room.first << (room.first == currentRoomName ? " [P]" : "") << endl;
        }
        cout << endl;
    }
    void MovePlayerToRoom(const string& targetRoom) {
        //convert shorthand to full name if necessary
        string roomName = targetRoom;
        if (shorthandToFullName.find(targetRoom) != shorthandToFullName.end()) {
            roomName = shorthandToFullName[targetRoom];
        }
        //check if the room is connected and move the player if possible
        if (find(connections[currentRoomName].begin(), connections[currentRoomName].end(), roomName) != connections[currentRoomName].end()) {
            currentRoomName = roomName;
            cout << "Moved to " << roomName << endl;
        }
        else {
            cout << "No direct connection to " << roomName << " from " << currentRoomName << endl;
        }

        DisplayFullMap();
        DisplayCurrentRoomMap();
    }

    //display the map of the current room and show available room connections
    void DisplayCurrentRoomMap() const {
        rooms.at(currentRoomName).DisplayRoomMap();
        DisplayConnections();
    }

    //other methods that remain unchanged

    void MovePlayerInRoom(char direction) {
        bool moved = rooms[currentRoomName].MovePlayer(direction);
        if (!moved) {
            cout << "Hit the boundary within " << currentRoomName << endl;
        }
        DisplayCurrentRoomMap();
    }

};
