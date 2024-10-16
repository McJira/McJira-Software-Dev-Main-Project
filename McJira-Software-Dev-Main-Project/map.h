

#include "Room.h"

using namespace std;

class map {
private:
    Room dungeon[2][2]; //2x2 grid of Room objects (4 rooms)
    int playerX;        //player current X position
    int playerY;        //player current Y position

public:
    //constructor to create the map with 4 rooms
    map() : playerX(0), playerY(0) {
        //creating the 4 rooms. (more will be added later)
        dungeon[0][0] = Room("Entrance");
        dungeon[0][1] = Room("Hallway");
        dungeon[1][0] = Room("Armory");
        dungeon[1][1] = Room("Treasure Room");
    }

    //function to convert a string to lowercase so that the case does not matter
    void ToLowerCase(string& str) {
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + ('a' - 'A'); //convert uppercase to lowercase
            }
        }
    }

  
    void PlayerMovement() {  //function to prompt the user for movement move
        string direction;
        cout << "Enter direction (north, south, east, west, n, s, e, w) or 'm' to view the map: ";
        cin >> direction;

       
        ToLowerCase(direction);//converts all letters to lower

  
        if ((direction == "north" || direction == "n") && playerY > 0) {      //handle movement based on the direction entered, also makes sure the move is within the array.
            playerY--;
        }
        else if ((direction == "south" || direction == "s") && playerY < 1) {
            playerY++;
        }
        else if ((direction == "east" || direction == "e") && playerX < 1) {
            playerX++;
        }
        else if ((direction == "west" || direction == "w") && playerX > 0) {
            playerX--;
        }
        else if (direction == "m") {
            DisplayMap();
        }
        else {
            cout << "Invalid move! You can't move in that direction." << endl;
        }

        //display current room after movement
        dungeon[playerY][playerX].DisplayRoomInfo();
    }

 
    void DisplayMap() const {   //display a simple map of the dungeon
        cout << "Dungeon Map: " << endl;

        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 2; x++) {
                if (playerY == y && playerX == x) {
                    cout << "[P] "; //show the player position
                }
                else {
                    cout << "[ ] "; //empty room
                }
            }
            cout << endl;
        }
    }
};


