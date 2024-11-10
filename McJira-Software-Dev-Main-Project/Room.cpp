#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
private:
    string RoomName;  // Name of the room
    vector<vector<char>> grid;  // Room layout
    int playerX, playerY;  // Player's position within the room

public:
    // Constructor to initialize a room with any size and a custom name
    Room(int rows = 2, int cols = 2, const string& name = "Unnamed")
        : RoomName(name), grid(rows, vector<char>(cols, ' ')), playerX(0), playerY(0) {
        // Mark player's initial position
        grid[playerX][playerY] = 'P';
    }

    // Getter for RoomName
    string GetRoomName() const {
        return RoomName;
    }

    // Setter for RoomName
    void SetRoomName(const string& name) {
        RoomName = name;
    }

    // Method to display room information
    void DisplayRoomInfo() const {
        cout << "Room Name: " << RoomName << endl;
    }

    // Method to display the grid map of the room
    void DisplayRoomMap() const {
        cout << "Room Map: " << RoomName << endl;
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << "[" << cell << "] ";
            }
            cout << endl;
        }
    }

    // Move player in the room based on direction
    bool MovePlayer(char direction) {
        // Clear current position
        grid[playerX][playerY] = ' ';

        // Calculate new position based on direction
        int newX = playerX;
        int newY = playerY;

        switch (direction) {
        case 'n': newX--; break; // North = up
        case 's': newX++; break; // South = down
        case 'e': newY++; break; // East = right
        case 'w': newY--; break; // West = left
        default: cout << "Invalid direction!" << endl; return false;
        }

        // Check if new position is within room bounds
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
            // Update position if within bounds
            playerX = newX;
            playerY = newY;
            grid[playerX][playerY] = 'P';
            return true;
        }
        else {
            // Out of bounds, revert to original position
            cout << "Out of bounds within room!" << endl;
            grid[playerX][playerY] = 'P';  // Restore player marker
            return false;
        }
    }
};
