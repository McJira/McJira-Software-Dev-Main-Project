
#include<string>
#include<iostream>
using namespace std;



class Dialog {

public:

    //Function to display introduction message
	void SetIntroMessage(string);
    //Setter for the descriptions array
    void SetUpDescriptionsArray();
    //function to display room side description to the player - takes an int for the room number and a string - which will be converted to int within the method - for room side 
    string DisplayRoomSideDescription(int,string);
    //Function to display introduction message to player
	string GetIntroMessage() const;
    Dialog();

    // below are all the descriptions for when you pick up an item
    string GetKeyDescription() const
    {
        return "You find a small, rusty key that looks like it can open a door.\n";
    }

    string GetIanDescription() const
    {
        return "Uh oh, you've challenged Ian to a duel. Let's hope you're prepared.\n";
    }

    string GetSwordDescription() const
    {
        return "Professor Vallone sees you eyeing his sword, eagerly\nHe speaks, 'Are you the student they've sent to fix this Ian mess? Well, you're gonna need this.'\nVallone passes you his sword. You grip it tightly.\nHe also offers you apples and cookies, but you aren't hungry.\n";
    }

    string GetInstructions() const;

private:

	//Static descriptions for the beginning of the game
	const string INTROMESSAGE = R"(Welcome to Devils Gone Wild, a dungeon adventure game!

You find yourself in the Math/CS Department in the Zenn at FDU. 

Dr. Darwish has just given you an important mission. 
Last summer, a few of his students took on a project to build Ian, our mascot, a robot exoskeleton. One that could engage with students full time.
However, soon after those students had graduated, Ian 2.0 begun to make decisions on his own. 
He has begun creating his own minions, setting traps, and has hidden himself away somewhere in the FDU Mansion.

As you make your way through the mansion, be careful. Each room may hold enemies, traps, or items to assist you.
Each time you clear a room, you will be given a list of options on where to go next.
Keep an eye out for other professors along the way, they may give you items and hints on where to go next.
 
The combat in this game is turn based, you may choose between fighting, using an item, or running to fight another day!
Be sure to strategize, preserve your health, and items to survive Ian's onslaught. 

Dr. Darwish of course would have taken on this mission himself, had he not destroyed his shoulder while moving a car battery.
Are you up for the task? Of course you are!

To move through the dungeon, type the direction you want to head (north, south, east, west, n, s, e, w).
If you'd like to check out your players stats, type stats!
And if you dont remember where you are, just type m for map!
Pay attention to any words in UPPERCASE, you can interact with them! Just type that uppercase word into the console.

----------------------------------------------------------------------------------------------------------------------

Dr. Darwish pushes you out of the CS/Math department.
You decide to push onwards.

  )";

    const string KEYDESCRIPTION = "";
    const string IANDESCRIPTION = "";
    const string SWORDDESCRIPTION = "";
    
    //Moved all the into below into Map.H 

	const string ROOM1DESCRIPTION = R"(Infront of you lay large wooden doors, you push them open, you hear their wood sqiuck, 
	  making you shiver. As you Enter the mansion, you feel a cold air rise around you. You walk into the room and as you do, 
	  the doors behind you lock, you desperately try to open them but to no avail, and you realise that you are locked in the mansion)";

    //Descriptions for lobby Sides
    const string LOBBY_EAST = "You are in the eastern side of the lobby, locked doors are infront of you, a sign above says Advising Office\n";
    const string LOBBY_NORTH = "You are in the northern side of the lobby, a long hallway is infront of you, to your left a door lay open, a key positioned under it\n";
    const string LOBBY_SOUTH = "You are in the southern side of the lobby, infront of you is a broken stairway, going up, under it lays another stairway going down, locked by gate, a key hole situated inside\n";
    const string LOBBY_WEST = "You are in the western side of the lobby, double doors lay behind you, to your right lay a couch and a table\n";
    //An array to hold room descritions - to be manually enlarged when more room descriptions are added - row stand for Room number - i.e lobby - column stand for side - i.e north.
    string roomDescriptions[4][1];

    const string INSTRUCTIONS = "\nCommands: \n 'w' to move up\n 'a' to move left\n 's' to move down\n 'd' to move right\n Enter room name (e.g., 'Hennessy Hall' or shorthand 'HH') to move to a connected room\n 'map' to display the full map, 'current' to display the current room map\n";

};