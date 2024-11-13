#include <Windows.h>
#include <mmsystem.h>
#include <iostream>

using namespace std;
/*Welcome to where the sounds of our game come from.Use this block comment as a Comprehensive guide to adding sound effects to the game.

**IMPORTANT** CODE WILL BE BROKEN UNLESS YOU READ!!!!


To Get Started first add the winmm.lib library to the enviroment

1. Click on Project in the top of the application. Then McJira-Software-Dev-Main-Project Properties
2. Navigate to Linker then Input
3. Add winmm.lib to the Additional Dependencies field. (To the right there should be a box to type in)
4. Rebuild the Project.

This file should no longer read errors.

To add sound effects to the game:

1. 

To the right side in the solution explorer 
right click the button where it says "Solution 'McJira-Software-Dev-Main-Project' (1 of 1 project)

2. 

An option should appear to open the file in file explorer. 
You should see a couple of files. Your Directory hiarchey should look something like this C:\...\repos\McJira-Software-Dev-Main-Project-new

3.

Double Click on the "McJira-Software-Dev-Main-Project" folder.
Drag and drop any audio files you want to add. 
Important Note: As of now I only tested .wav files. You are welcome to test .mp3 or other audio files
but if it doesnt work you can use an online converter to convert files to the .wav format
If I figured out how to add the "test.wav" sound to the repo use that as a reference as to where sound files are supposed to be.

To play and or test the sound call the play sound function with the file name. 

Use below as an example of how to call it.

Example: playSound("test.wav");

IF the computer makes an error sound and still launches properly it means the the sound file cannot be found. 
Please make sure the sound file is in the right directory.


*/

// Base sound playing function. 
//To add sounds read instructions above create a new function with the sound purpose and implement it in the main.

void playSound(const std::string& filename) {

	/*
	I have no idea why the statement below is so convuludedand complicated.
	It basically takes in the file. Just call the Play sound method with the file name
	and it should. Should work. yes. trust me.
	*/

	std::wstring wFilename = std::wstring(filename.begin(), filename.end());

	//This plays the sound. Simple enough

	PlaySound(wFilename.c_str(), NULL, SND_FILENAME | SND_SYNC);
}

