// In Map.h
#ifndef MAP_H
#define MAP_H

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
        rooms["zen"] = Room(4, 4, "zen");
        rooms["hennessy hall"] = Room(4, 6, "hennessy hall");
        rooms["science building"] = Room(4, 4, "science Building");
        rooms["rec center"] = Room(4, 3, "rec center");
        rooms["dreyfuss"] = Room(5, 4, "dreyfuss");

        //define connections based on the diagram
        connections["zen"] = { "hennessy hall", "rec center", "dreyfuss" };
        connections["hennessy hall"] = { "zen", "science building", "dreyfuss" };
        connections["science building"] = { "hennessy hall", "dreyfuss" };
        connections["rec center"] = { "zen", "dreyfuss" };
        connections["dreyfuss"] = { "zen", "hennessy hall", "science building", "rec center" };

        //define shorthand mappings
        shorthandToFullName["z"] = "zen";
        shorthandToFullName["hh"] = "hennessy hall";
        shorthandToFullName["sb"] = "science building";
        shorthandToFullName["rc"] = "rec center";
        shorthandToFullName["d"] = "dreyfuss";
        //start the player in Zen
        currentRoomName = "zen";
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
        char adjustedDirection;
        switch (direction) {
        case 'w': adjustedDirection = 'n'; break;
        case 'a': adjustedDirection = 'w'; break;
        case 's': adjustedDirection = 's'; break;
        case 'd': adjustedDirection = 'e'; break;
        default: cout << "Invalid direction!" << endl; return;
        }
        bool moved = rooms[currentRoomName].MovePlayer(adjustedDirection);
        if (!moved) {
            cout << "Hit the boundary within " << currentRoomName << endl;
        }
        DisplayCurrentRoomMap();
    }

};

#endif // !MAP_H
