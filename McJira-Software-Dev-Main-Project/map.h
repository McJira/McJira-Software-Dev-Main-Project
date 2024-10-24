

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
        dungeon[0][0] = Room("Entrance", "You are in the eastern side of the lobby, locked doors are infront of you, a sign above says Advising Office\n");
        dungeon[0][1] = Room("Hallway", "You are in the northern side of the lobby, a long hallway is infront of you, to your left a door lay open, a key positioned under it\n");
        dungeon[1][0] = Room("Armory", "You are in the southern side of the lobby, infront of you is a broken stairway, going up, under it lays another stairway going down, locked by gate, a key hole situated inside\n");
        dungeon[1][1] = Room("Treasure Room", "You are in the western side of the lobby, double doors lay behind you, to your right lay a couch and a table\n");
    }

    //function to convert a string to lowercase so that the case does not matte  

    void DisplayMap(int,int) const;
    void GetRoomDescription(int x, int y) const;
   
};


