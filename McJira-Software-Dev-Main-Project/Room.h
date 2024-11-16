#ifndef ROOM_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "enemy.h"
#include "Item.h"
using namespace std;

class Room {
private:
    string RoomName;  //name of the room
    vector<vector<char>> grid;  //room layout
    vector<vector<char>> ObjectsGrid;
    vector<vector<Enemy>> enemygrid;  //2D grid to store enemies
    vector<vector<Item>> Itemgrid; //Item vector stores items in the room.
    int playerX, playerY;  // Player's position within the room

public:
    //constructor to initialize a room with any size, a custom name, and an empty enemy grid
    Room(int rows = 2, int cols = 2, const string& name = "Unnamed")
        : RoomName(name),
        grid(rows, vector<char>(cols, ' ')),
        ObjectsGrid(rows, vector<char>(cols, ' ')),
        enemygrid(rows, vector<Enemy>(cols)),  //initialize enemygrid with room dimensions
        Itemgrid(rows, vector<Item>(cols)), //initialize Itemgrid with room dimensions
        playerX(0),
        playerY(0) {
        //mark player's initial position
        grid[playerX][playerY] = 'P';
    }

    //getter for RoomName
    string GetRoomName() const {
        return RoomName;
    }
    //setter for RoomName
    void SetRoomName(const string& name) {
        RoomName = name;
    }

    //adds an Item to a room in the map
    void AddItem(const Item& item, int x, int y) {
        if (x >= 0 && x < Itemgrid.size() && y >= 0 && y < Itemgrid[0].size() && x != playerX && y != playerY) {
            Itemgrid[x][y] = item;  // Place item at the specified position
            ObjectsGrid[x][y] = 'I';
            grid[x][y] = 'I';
        }
    }
    // Method to remove an item from a specific position in the room
    bool RemoveItem(int x, int y) {
        if (x >= 0 && x < Itemgrid.size() && y >= 0 && y < Itemgrid[0].size()) {
            Itemgrid[x][y] = Item();  // Reset the item to a default (inactive) item
            ObjectsGrid[x][y] = ' ';  // Clear item marker in ObjectsGrid
            grid[x][y] = ' ';         // Clear item marker in the room layout
            return true;
        }
        cout << "Invalid position to remove item!" << endl;
        return false;
    }
    //retruns true if player is at the same posiiotn as an item in te room.
    bool HasItem() const {
        for (const auto& row : Itemgrid) {
            for (const auto& item : row) {
                if (item.GetItemName() != "" && ObjectsGrid[playerX][playerY] != ' ') {  // Checks if the item is not the default/empty item
                    return true;
                }
            }
        }
        return false;
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
        if (x >= 0 && x < enemygrid.size() && y >= 0 && y < enemygrid[0].size() && x != playerX && y != playerY) {
            enemygrid[x][y] = enemy;
            grid[x][y] = 'E';  // Mark enemy position in the room layout
            return true;
        }
        cout << "Invalid enemy position!" << endl;
        return false;
    }
    //This function removes an enemy from the room.
    
    bool RemoveEnemy(int x, int y) {
        if (x >= 0 && x < enemygrid.size() && y >= 0 && y < enemygrid[0].size()) {
            enemygrid[x][y] = Enemy();  // Replace enemy with a default blank enemy
            grid[x][y] = ' ';           // Clear the position on the room layout
            return true;
        }
        cout << "Invalid position to remove enemy!" << endl;
        return false;
    }

    
    // Method to check if a specific enemy is alive at the player's location
    bool HasEnemy(const string& enemyName) const {
        const Enemy& enemyAtPosition = enemygrid[playerX][playerY];
        // Check if the enemy's health is greater than zero and matches the specified name
        if (enemyAtPosition.getHealth() > 0 && enemyAtPosition.getEnemyName() == enemyName) {
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

#endif // !ROOM_H

