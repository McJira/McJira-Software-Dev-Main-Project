#pragma once
#pragma once


#include <iostream>
#include <string>


using namespace std; 


#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
private:
    string RoomName;  // name of the room
    vector<vector<char>> grid;  // room layout
    int playerX, playerY;  // player's position within the room

public:
    // constructor to initialize a room with any size and a custom name
    Room(int rows = 2, int cols = 2, const string& name = "Unnamed")
        : RoomName(name), grid(rows, vector<char>(cols, ' ')), playerX(0), playerY(0) {
        // mark player's initial position
        grid[playerX][playerY] = 'P';
    }

    // getter for RoomName
    string GetRoomName() const {
        return RoomName;
    }

    // setter for RoomName
    void SetRoomName(const string& name) {
        RoomName = name;
    }

    // method to display room information
    void DisplayRoomInfo() const {
        cout << "Room Name: " << RoomName << endl;
    }

    // method to display the grid map of the room
    void DisplayRoomMap() const {
        cout << "Room Map: " << RoomName << endl;
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << "[" << cell << "] ";
            }
            cout << endl;
        }
    }

    // move player in the room based on direction
    bool MovePlayer(char direction) {
        // clear current position
        grid[playerX][playerY] = ' ';

        // calculate new position based on direction
        int newX = playerX;
        int newY = playerY;

        switch (direction) {
        case 'n': newX--; break; // north = up
        case 's': newX++; break; // south = down
        case 'e': newY++; break; // east = right
        case 'w': newY--; break; // west = left
        default: cout << "Invalid direction!" << endl; return false;
        }

        // check if new position is within room bounds
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
            // update position if within bounds
            playerX = newX;
            playerY = newY;
            grid[playerX][playerY] = 'P';
            return true;
        }
        else {
            // out of bounds, revert to original position
            cout << "Out of bounds within room!" << endl;
            grid[playerX][playerY] = 'P';  // restore player marker
            return false;
        }
    }
};



/*
class Room {
private:
    string RoomName;//name of the room
    string RoomDescription;

public:
    
    Room() : RoomName("Unnamed"), RoomDescription("Unavailable") {} //default constructors

    Room(const string& name, const string& description)
        : RoomName(name), RoomDescription(description){}    //constructor to initialize the room with specific values

    string GetRoomName() const;
    


    void SetRoomName(const string& name); 

    string GetRoomDescription() const; 

    void SetRoomDescription(const string& description); 
    
    void DisplayRoomInfo() const;

};
*/