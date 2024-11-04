#pragma once
#pragma once


#include "Room.h"
#include "Player.h"

using namespace std;

class Map {
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Map {

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Map {

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

    //constructor to create the map with 4 rooms
    Map() {
        //creating the 4 rooms. (more will be added later)
        dungeon[0][0] = Room("Entrance", "You have entered into the grand lobby of the mansion.\nThere are locked doors behind you, and a sign above that says Advising Office\nYou can hear a creek in the distance, giving you a feeling you're not alone.\n");
        dungeon[0][1] = Room("Hallway", "You find yourself gazing down the stretch of a long hallway.\nAt the end, you notice that one of the rooms were left open.\nAfter entering, you see something glimmering in the distance, a KEY.\n");
        dungeon[1][0] = Room("Armory", "As you're walking, you hear the clanking of metal.\nImmediately, you fear the worst, but decide to enter anyways.\nInside, you see Professor Vallone hammering away at what looks to be a SWORD.\n ");
        dungeon[1][1] = Room("Treasure Room", "You enter the door. Inside, is a classroom that has become indistinguishable.\nThere are desks flipped over, papers torn, and books on fire.\nBehind the chaos sits IAN menacingly, looking for a fight.\n");
    }

class Map {

    void DisplayMap(int, int) const;
    void GetRoomDescription(int x, int y) const;

};
    string GetRoomName() const;

    void DisplayMap(int, int) const;
};


/*
class Map {

   
};

    void DisplayRoomInfo() const;

*/