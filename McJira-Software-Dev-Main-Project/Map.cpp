#include "Map.h"


//display a simple map of the dungeon
void Map::DisplayMap(int playerAxisX, int playerAxisY) const {   
    cout << "Dungeon Map: " << endl;

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            if (playerAxisY == y && playerAxisX == x) {
                cout << "[P] "; //show the player position
            }
            else {
                cout << "[ ] "; //empty room
            }
        }
        cout << endl;
    }
}

void Map::GetRoomDescription(int x, int y) const{
    cout << endl;
    return dungeon[x][y].DisplayRoomInfo();

}