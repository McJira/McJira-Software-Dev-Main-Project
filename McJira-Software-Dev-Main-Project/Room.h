#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "enemy.h"
using namespace std;

class Room {
private:
    string RoomName;  // Name of the room
    vector<vector<char>> grid;  // Room layout
    vector<vector<Enemy>> enemygrid;  // 2D grid to store enemies
    //Implmentation of an Item vector can start here.

    int playerX, playerY;  // Player's position within the room

public:
    // Constructor to initialize a room with any size, a custom name, and an empty enemy grid
    Room(int rows = 2, int cols = 2, const string& name = "Unnamed")
        : RoomName(name), grid(rows, vector<char>(cols, ' ')), enemygrid(rows, vector<Enemy>(cols)), playerX(0), playerY(0) {
        // Mark player's initial position
        grid[playerX][playerY] = 'P';
    }

    // Getter for RoomName
    string GetRoomName() const {
        return RoomName;
    }
    bool HasEnemy() const {
        const Enemy& enemyAtPosition = enemygrid[playerX][playerY];
        if (enemyAtPosition.getIsAlive()) {
            cout << "An enemy is at your current location!" << endl;
            return true;
        }
        return false;
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

    // Method to add an enemy at a specific position in the enemy grid
    bool AddEnemy(const Enemy& enemy, int x, int y) {
        if (x >= 0 && x < enemygrid.size() && y >= 0 && y < enemygrid[0].size()) {
            enemygrid[x][y] = enemy;
            grid[x][y] = 'E';  // Mark enemy position in the room layout
            return true;
        }
        cout << "Invalid enemy position!" << endl;
        return false;
    }
    // Method to check if a specific enemy is alive at the player's location
    bool HasEnemy(const string& enemyName) const {
        const Enemy& enemyAtPosition = enemygrid[playerX][playerY];
        if (enemyAtPosition.getIsAlive() && enemyAtPosition.getEnemyName() == enemyName) {
            return true;
        }
        return false;
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
