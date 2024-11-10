#pragma once
#pragma once
#include "Room2.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Map2 {
private:
    unordered_map<string, Room2> rooms;  //stores rooms by name
    unordered_map<string, vector<string>> connections;  //stores room connections
    unordered_map<string, vector<Enemy*>> enemiesInRooms;
    string currentRoomName;  //track the player's current room by name


public:
    //constructor to initialize rooms and connections based on input
    Map2() {
        //initialize rooms with custom sizes and names
        rooms["Room 1"] = Room2(3, 3, "Room 1");
        rooms["Room 2"] = Room2(4, 4, "Room 2");
        rooms["Room 3"] = Room2(3, 3, "Room 3");
        rooms["Room 4"] = Room2(3, 3, "Room 4");
        rooms["Room 5"] = Room2(3, 3, "Room 5");

        //connections based on the diagram in ms teams files
        connections["Room 1"] = { "Room 2", "Room 4", "Room 5" };
        connections["Room 2"] = { "Room 1", "Room 3", "Room 5" };
        connections["Room 3"] = { "Room 2", "Room 5" };
        connections["Room 4"] = { "Room 1", "Room 5" };
        connections["Room 5"] = { "Room 1", "Room 2", "Room 3", "Room 4" };

        //start the player in Room 1
        currentRoomName = "Room 1";
        
        //Enemies can be added here.

        AddEnemyToRoom("Room 1", new Enemy(25.0, 10.0, "IAN","I am IAN! You really think you can defeat me? Give it your best shot!","no... NOO... THIS CAN'T BE....", &rooms["Room 1"], 1, 1));
    }


    //display the dungeon map with the player's current room
    void DisplayFullMap() const {
        cout << "Dungeon Map:" << endl;
        for (const auto& room : rooms) {
            cout << room.first << (room.first == currentRoomName ? " [P]" : "") << endl;
        }
        cout << endl;
    }

    ~Map2() {
        for (auto& roomEnemies : enemiesInRooms) {
            for (Enemy* enemy : roomEnemies.second) {
                delete enemy;  // Clean up dynamically allocated enemies
            }
        }
    }

    //display the map of the current room and show available room connections
    void DisplayCurrentRoomMap() const {
        rooms.at(currentRoomName).DisplayRoomMap();
        //show available rooms the player can move to
        DisplayConnections();
    }
    //Enemy functions
    void AddEnemyToRoom(const string& roomName, Enemy* enemy) {
        if (rooms.find(roomName) != rooms.end()) {
            enemiesInRooms[roomName].push_back(enemy);
        }
    }

    void CheckForEnemy() const {
        if (enemiesInRooms.find(currentRoomName) != enemiesInRooms.end()) {
            int playerX = rooms.at(currentRoomName).getPlayerX();  // Assuming Room2 has getPlayerX()
            int playerY = rooms.at(currentRoomName).getPlayerY();  // Assuming Room2 has getPlayerY()

            for (Enemy* enemy : enemiesInRooms.at(currentRoomName)) {
                if (enemy->getIsAlive() && enemy->isPlayerAtLocation(playerX, playerY)) {
                    cout << enemy->getEnemyIntro() << endl;
                    // Additional combat logic could go here if needed
                }
            }
        }
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
