

#include "Room.h"
#include "Player.h"

using namespace std;

#pragma once
#include "Room.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Map {

private:
    Room dungeon[2][2]; //2x2 grid of Room objects (4 rooms)

public:
    //constructor to create the map with 4 rooms

    //function to convert a string to lowercase so that the case does not matte  

    void DisplayMap(int, int) const;
    void GetRoomDescription(int x, int y) const;
};


/*
class Map {

   
};


*/