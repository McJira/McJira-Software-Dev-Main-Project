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
    string currentRoomName;  // Track the player's current room by name

public:
    // Constructor to initialize rooms and connections
    Map() {
        // Initialize rooms with custom sizes and names
        rooms["Room 1"] = Room(3, 3, "Room 1");
        rooms["Room 2"] = Room(4, 4, "Room 2");
        rooms["Room 3"] = Room(3, 3, "Room 3");
        rooms["Room 4"] = Room(3, 3, "Room 4");
        rooms["Room 5"] = Room(3, 3, "Room 5");

        // Define connections based on the diagram
        connections["Room 1"] = { "Room 2", "Room 4", "Room 5" };
        connections["Room 2"] = { "Room 1", "Room 3", "Room 5" };
        connections["Room 3"] = { "Room 2", "Room 5" };
        connections["Room 4"] = { "Room 1", "Room 5" };
        connections["Room 5"] = { "Room 1", "Room 2", "Room 3", "Room 4" };

        // Start the player in Room 1
        currentRoomName = "Room 1";
    }
    string GetCurrentRoomName() const {
        return currentRoomName;
    }

    Room& GetRoom(const string& roomName) {
        return rooms.at(roomName);  // Assumes roomName exists
    }
    // Method to add an enemy to a specific room by name
    bool AddEnemyToRoom(const string& roomName, Enemy& enemy, int x, int y) {
        if (rooms.find(roomName) != rooms.end()) {
            return rooms[roomName].AddEnemy(enemy, x, y);
        }
        else {
            cout << "Room " << roomName << " does not exist." << endl;
            return false;
        }
    }


    void DisplayConnections() const {
        cout << "You can move to the following rooms: ";
        for (const auto& connectedRoom : connections.at(currentRoomName)) {
            cout << connectedRoom << " ";
        }
        cout << endl;
    }
    // Display the dungeon map with the player's current room
    void DisplayFullMap() const {
        cout << "Dungeon Map:" << endl;
        for (const auto& room : rooms) {
            cout << room.first << (room.first == currentRoomName ? " [P]" : "") << endl;
        }
        cout << endl;
    }
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




    // Display the map of the current room and show available room connections
    void DisplayCurrentRoomMap() const {
        rooms.at(currentRoomName).DisplayRoomMap();
        DisplayConnections();
    }

    // Other methods remain unchanged...

    void MovePlayerInRoom(char direction) {
        bool moved = rooms[currentRoomName].MovePlayer(direction);
        if (!moved) {
            cout << "Hit the boundary within " << currentRoomName << endl;
        }
        DisplayCurrentRoomMap();
    }



};
