#include <iostream>
#include <string>			//strings in filename, etc.
#include "Background.h"		//Background initialization and drawing
#include "Circle.h"
#include "BatteryMeter.h"
#include "Pokemon.h"
#include "Overlays.h"
#include "Pokeball.h"
#include "Score.h"
#include <ctime>
#include <windows.h>

using namespace std;

//Vertical resolution (Rows or Y-Values)
const int WIN_RES_ROWS = 480;
//Horizontal resolution (Columns or X-Values)
const int WIN_RES_COLS = 640;

//Number of Pokemon
const int NUM_POKEMON = 8;

//Name of background input file
const string BKG_IMG_NAME = "bkrd";

int main(int argc, char *argv[])
{
	//Hide the console window (Windows only)
	FreeConsole();

	//Primary display plotter is created
	SDL_Plotter g(WIN_RES_ROWS,WIN_RES_COLS);

	//initialize sounds
	g.initSound("se_go_ball_throw.wav");
	g.initSound("200_ME_gotcha.wav");
    g.initSound("se_go_sys_select.wav");
    g.initSound("catchtrue.wav");

	//Keep track of time program started
	long int startTime = time(0);

	int caught = -1, numCaught = 0, poke = 0;

	Background loading;
	loading.generate("loading");
	loading.draw(g,0);
	g.update();

	//Array of Pokemon Names
	string pokemonNames[8] = {"Charmeleon","Diglet","Jigglypuff","Meowth",
                                "Noctowl","Pikachu","Topegi","Totodile"};
    Pokemon pokemonObjects[8];
    bool pokemonCaught[8] = {false,false,false,false,false,false,false,false};

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

    //Generate Booth "Pokemon"
    Pokemon booth;
    booth.generate("Thought_Bubble");

    //Create battery
	Battery bat;
	bool gameOver = false;

	//Create caught screen
	Background caughtScreen;
	caughtScreen.generate("CaughtPokemon");

	//Create score object
	Score score;

	//Create end screen
	Background endScreen;
	endScreen.generate("PokemonGameOverScreen");

	//Counter variable for current frame of game play
	//Use %(number of frames in file) to select frame of each object
	long long int frame = 0;

	//Makes a pokeball object
	Pokeball pokeball;
	pokeball.generate("Pokeball");

	//Pause on loading screen if short to prevent flashing
	if(time(0) - startTime < 2){
		g.Sleep(1000);
	}

	//Draw start screen
	startScreen.draw(g,0);
	g.update();

	//Wait until a key is pressed
	while(!g.kbhit()){
        if(g.kbhit()){
            break;
		}
		g.Sleep(5);
	}

    g.playSound("se_go_sys_select.wav");

	g.update();

	//Draw instructions screen
	instructionsScreen.draw(g,0);
	g.update();

	//Wait until a key is pressed
	while(!g.kbhit()){
        if(g.kbhit()){
            break;
		}
		g.Sleep(5);
	}

	g.playSound("se_go_sys_select.wav");

	bat.setBatteryLife(30);

	char key;

	srand(time(0));
	int xrand = rand()%540;
	int yrand = 100 + rand()%340;

    //Keep window open until quit state is reached (ESC)
    while (!g.getQuit() && !gameOver){
        city.draw(g,0);
        bat.displayMeter(g,5,5);

        if(!pokemonCaught[poke])
        {
            pokemonObjects[poke].draw(g,frame%pokemonObjects[poke].getFrames(),
                                      xrand,yrand);
        }
        else if(poke < 7)
        {
            pokemonCaught[poke] = false;
            xrand = rand()%540;
            yrand = 240 + rand()%140;
            poke++;
        }
        else
        {
            poke = 0;
            xrand = rand()%540;
            yrand = 240 + rand()%140;
        }

        if(g.kbhit()){
            key = g.getKey();
            switch(key){
                case UP_ARROW: cursor.move(UP, g);
                                break;
                case DOWN_ARROW: cursor.move(DOWN, g);
                                break;
                case LEFT_ARROW: cursor.move(LEFT, g);
                                break;
                case RIGHT_ARROW: cursor.move(RIGHT, g);
                                break;
                case ' ': g.playSound("se_go_ball_throw.wav");
                          caught = pokeball.pokeballThrow(g, city,
                                                    frame%pokeball.getFrames(),
                                                    bat, 320, 459,
                                                    cursor.loc.x, cursor.loc.y,
                                                    pokemonObjects,
                                                    NUM_POKEMON);
                          break;
            }
        }

        if(caught >= 0)
        {
            pokemonCaught[caught] = true;
            numCaught++;
            g.Sleep(300);
            g.playSound("catchtrue.wav");
        }

        caught = -1;

        cursor.draw(g,cursor.getLoc().y, cursor.getLoc().x);
        g.update();
    	g.Sleep(50);
    	frame++;

    	if(bat.getBatteryLevel() <= 0){
    		gameOver = true;
    	}
    }

    if(gameOver){
        caughtScreen.draw(g, 0);

        score.setScore(numCaught);

        score.drawScore(g, 260, 205);
        g.playSound("200_ME_gotcha.wav");

        g.update();

        g.Sleep(4000);

        endScreen.draw(g,0);
        g.update();
        for(int i = 0; i < booth.getFrames(); i++){
            booth.erase(g,endScreen,0,bat);
            booth.draw(g,i,150,300);
            g.update();
            g.Sleep(100);
        }
        while(!g.getQuit()){
            if(g.kbhit()){
                key = g.getKey();
            }
        }
    }

    //quit sounds
    g.quitSound("se_go_ball_throw.wav");
	g.quitSound("200_ME_gotcha.wav");
    g.quitSound("se_go_sys_select.wav");
    g.quitSound("catchtrue.wav");

    return 0;
}
