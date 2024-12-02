#ifndef ROOM_H
#define ROOM_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "enemy.h"
#include "Item.h"
#include "Instances.h"
using namespace std;

class Room {
private:
    string RoomName;  //name of the room
    vector<vector<char>> grid;  //room layout
    vector<vector<char>> ObjectsGrid;
    vector<vector<Enemy>> enemygrid;  //2D grid to store enemies
    vector<vector<Item>> Itemgrid; //Item vector stores items in the room.
    vector<vector<Instance>> InstanceGrid; //Instance vector stores items in the room.
    int playerX, playerY;  // Player's position within the room

public:
    //constructor to initialize a room with any size, a custom name, and an empty enemy grid
    Room(int rows = 2, int cols = 2, const string& name = "Unnamed")
        : RoomName(name),
        grid(rows, vector<char>(cols, ' ')),
        ObjectsGrid(rows, vector<char>(cols, ' ')),
        enemygrid(rows, vector<Enemy>(cols)),  //initialize enemygrid with room dimensions
        Itemgrid(rows, vector<Item>(cols)), //initialize Itemgrid with room dimensions
        InstanceGrid(rows, vector<Instance>(cols)), //initialize Instancegrid with room dimensions
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
    //add an Instance to a room in the map
    void AddInstance(const Instance& instance, int x, int y) {
        if (x >= 0 && x < InstanceGrid.size() && y >= 0 && y < InstanceGrid[0].size() && x != playerX && y != playerY) {
            if (ObjectsGrid[x][y] != ' ') {
                return; // makes it not place where there's already another room type
            }

            InstanceGrid[x][y] = instance;  // Add instance
            ObjectsGrid[x][y] = 'T';       // Mark the location in the ObjectsGrid
            grid[x][y] = 'T';              // Mark the location in the room layout
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
        if (ObjectsGrid[playerX][playerY] == 'I') { // fixed it so that it checks for I specifically and doesnt loop dialogue when there isnt an item there
            const Item& itemAtPosition = Itemgrid[playerX][playerY];
            return !itemAtPosition.GetItemName().empty(); 
        }
        return false;
    }
    // returns if the player is at the same position as an item

    bool HasInstance() const {
        // checks if there is an instance where the player is
        if (ObjectsGrid[playerX][playerY] == 'T') {
            const Instance& instanceAtPosition = InstanceGrid[playerX][playerY];
            return !instanceAtPosition.GetInstanceName().empty(); // checks its not empty
        }
        return false;
    }

    bool RemoveInstance(int x, int y){
        if (x >= 0 && x < InstanceGrid.size() && y >= 0 && y < InstanceGrid[0].size()) {
            InstanceGrid[x][y] = Instance();  
            ObjectsGrid[x][y] = ' '; 
            grid[x][y] = ' ';         
            return true;
        }
        cout << "Invalid position to remove item!" << endl;
        return false;
    }

    //function to return instance at the players current position
    Instance GetInstanceAtPlayerPosition() const
    {
        return InstanceGrid[playerX][playerY];
    }

    //funtion to return the item at the players current position
    Item GetItemAtPlayerPosition() const
    {

        return Itemgrid[playerX][playerY];

    }

    //function to return player's Row Position
    int GetPlayerPositionRow() const
    {
        return playerX;
    }

    //function to return player's Column Position
    int GetPlayerPositionColumn() const
    {
        return playerY;
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
    Enemy* GetEnemyAtPlayerPosition() {
        if (playerX >= 0 && playerX < enemygrid.size() &&
            playerY >= 0 && playerY < enemygrid[0].size() &&
            enemygrid[playerX][playerY].isAlive()) {
            return &enemygrid[playerX][playerY]; // Return the enemy pointer if alive
        }
        return nullptr; // No enemy or enemy is dead
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

