
#include<string>
using namespace std;



class Dialog {

public:

	void SetIntroMessage(string);
	string GetIntroMessage() const;
	Dialog();



private:

	const string INTROMESSAGE = R"(Welcome to Devils Gone Wild, a dungeon adventure game!

  You find yourself in the Math/CS Department in the Zenn at FDU. 

  Dr. Darwish has just given you an important mission. 
  Last summer, a few of his students took on a project to build Ian, our mascot, a robot exoskeleton. One that could engage with students full time.
  However, soon after those students had graduated, Ian 2.0 begun to make decisions on his own. He has begun creating his own minions, setting traps, and has hidden himself away somewhere in FDU.

  As you make your way through FDU, be careful. Each room may hold enemies, traps, or items to assist you.
  Each time you clear a room, you will be given a list of options on where to go next.
  Keep an eye out for other professors along the way, they may give you items and hints on where to go next.

  The combat in this game is turn based, you may choose between fighting, using an item, or running to fight another day!
  Be sure to strategize, preserve your health, and items to survive Ian's onslaught. 

  Dr. Darwish of course would have taken on this mission himself, had he not destroyed his shoulder while moving a car battery.
  Are you up for the task? Of course you are!

  )";



};