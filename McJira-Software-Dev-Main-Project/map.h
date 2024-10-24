

#include "Room.h"
#include "Player.h"

using namespace std;

class Map {
private:
    Room dungeon[2][2]; //2x2 grid of Room objects (4 rooms)

public:
    //constructor to create the map with 4 rooms
    Map(){
        //creating the 4 rooms. (more will be added later)
        dungeon[0][0] = Room("Entrance");
        dungeon[0][1] = Room("Hallway");
        dungeon[1][0] = Room("Armory");
        dungeon[1][1] = Room("Treasure Room");
    }

    //function to convert a string to lowercase so that the case does not matte  

    void DisplayMap(int,int) const;
    void GetRoomDescription(int x, int y) const
    {
        return dungeon[x][y].DisplayRoomInfo();
    }
};


