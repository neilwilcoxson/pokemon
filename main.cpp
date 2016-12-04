#include <iostream>
#include <string>			//strings in filename, etc.
#include "Background.h"		//Background initialization and drawing
#include "Circle.h"
#include "BatteryMeter.h"
#include "Pokemon.h"
#include "Overlays.h"
#include <ctime>
#include <windows.h>

using namespace std;

//Vertical resolution (Rows or Y-Values)
const int WIN_RES_ROWS = 480;
//Horizontal resolution (Columns or X-Values)
const int WIN_RES_COLS = 640;

//Number of Pokemon
const int NUM_POKEMON = 9;

//Name of background input file
const string BKG_IMG_NAME = "bkrd";

int main(int argc, char *argv[])
{
	//Hide the console window (Windows only)
	FreeConsole();
	//Primary display plotter is created
	SDL_Plotter g(WIN_RES_ROWS,WIN_RES_COLS);

	//Keep track of time program started
	long int startTime = time(0);

	Background loading;
	loading.generate("loading");
	loading.draw(g,0);
	//g.initSound("PokemonTheme.wav");
	//g.playSound("PokemonTheme.wav");
	g.update();

	//Array of Pokemon Names
	string pokemonNames[15] = {"Charmeleon","Diglet","Jigglypuff","Meowth",
                                "Noctowl","Pikachu","Topegi","Totodile","Booth"};
    Pokemon pokemonObjects[15];

    //Load Background for Start Screen
    Background startScreen;
    startScreen.generate("PokemonStartScreen");

    //Load Background for instructions screen
    Background instructionsScreen;
    instructionsScreen.generate("PokemonInstructionsScreen");

	//Background object for main level is created
	Background city;
	city.generate(BKG_IMG_NAME);

	//Circle cursor object is created
	Circle cursor;
	cursor.generate("Circle");

    //Create Pokemon Objects and generate vectors
    for(int i = 0; i < NUM_POKEMON; i++){
        pokemonObjects[i].generate(pokemonNames[i].c_str());
    }

    //Create battery
	Battery bat;
	bool gameOver = false;

	//Counter variable for current frame of game play
	//Use %(number of frames in file) to select frame of each object
	long long int frame = 0;

	//Pause on loading screen if short to prevent flashing
	if(time(0) - startTime < 2){
		g.Sleep(1000);
	}

	//Draw start screen
	startScreen.draw(g,0);
	g.update();

	//Wait until a key is pressed
	while(!g.kbhit()){
		g.Sleep(5);
	}

	//g.quitSound("PokemonTheme.wav");
	g.update();

	//Draw instructions screen
	instructionsScreen.draw(g,0);
	g.update();

	//Wait until a key is pressed
	while(!g.kbhit()){
		g.Sleep(5);
	}

	bat.setBatteryLife(60);

	int row, col;
	char key;

	row = 182;
	col = 262;

    //Keep window open until quit state is reached (ESC)
    while (!g.getQuit() && !gameOver){
        city.draw(g,0);
        cursor.draw(g,row, col);
        bat.displayMeter(g,5,5);
        pokemonObjects[8].draw(g,frame%pokemonObjects[8].getFrames(),400,300);
    		//if(g.kbhit()){
    	    	//key = g.getKey();
    	    	//switch(key){
                  //  case UP_ARROW: cursor.move(UP, g);
                                   break;
                    //case DOWN_ARROW: cursor.move(DOWN, g);
                                     break;
                    //case LEFT_ARROW: cursor.move(LEFT, g);
                                   break;
                    //case RIGHT_ARROW: cursor.move(RIGHT, g);
                                     break;
    	    //	}
    		//}
    	g.update();
    	g.Sleep(100);
    	//pokemonObjects[1].erase(g,city,frame%city.getFrames(),bat);
    	//g.update();
    	//g.Sleep(100);
    	//Increment current frame number
    	frame++;

    	if(bat.getBatteryLevel() <= 0){
    		gameOver = true;
    	}
    }
    return 0;
}
