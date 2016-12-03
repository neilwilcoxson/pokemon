#include <iostream>
#include <string>			//strings in filename, etc.
#include "Background.h"		//Background initialization and drawing
#include "BatteryMeter.h"
#include "Pokemon.h"
#include "Overlays.h"

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
	//Primary display plotter is created
	SDL_Plotter g(WIN_RES_ROWS,WIN_RES_COLS);

	Background loading;
	loading.generate("loading");
	loading.draw(g,0);
	g.update();

	//Vector of Pokemon Names
	string pokemonNames[15] = {"Charmeleon","Diglet","Jigglypuff","Meowth",
                                "Noctowl","Pikachu","Topegi","Totodile"};
    Pokemon pokemonObjects[15];

	//Background object for main level is created
	Background city;
	city.generate(BKG_IMG_NAME);

    //Create Pokemon Objects and generate vectors
    for(int i = 0; i < NUM_POKEMON; i++){
        pokemonObjects[i].generate(pokemonNames[i].c_str());
    }

	Battery bat;
	bat.setBatteryLife(60);

	long long int frame = 0;	//Current frame

    //Keep window open until quit state is reached (ESC)
    while (!g.getQuit()){
    	city.draw(g,0);
        bat.displayMeter(g,0,0);
        pokemonObjects[1].draw(g,frame%pokemonObjects[1].getFrames(),0,0);
    	g.update();
    		if(g.kbhit()){
    	    	g.getKey();
    		}
    	g.Sleep(100);
    	pokemonObjects[1].erase(g,city,frame%city.getFrames(),bat);
    	g.update();
    	g.Sleep(100);
    	//Increment current frame number
    	frame++;
    }
    return 0;
}
