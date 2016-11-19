#include <iostream>
#include <string>			//strings in filename, etc.
#include "Background.h"		//Background initialization and drawing
#include "BatteryMeter.h"

using namespace std;

//Vertical resolution (Rows or Y-Values)
const int WIN_RES_ROWS = 480;
//Horizontal resolution (Columns or X-Values)
const int WIN_RES_COLS = 640;

//Base name of background input files (ex. background0 --> background)
const string BKG_IMG_NAME = "background";
//Number of background frames to be imported
const int NUM_BKG_FRAMES = 5;

int main(int argc, char *argv[])
{
	//Primary display plotter is created
	SDL_Plotter g(WIN_RES_ROWS,WIN_RES_COLS);
	//Background object for main level is created
	Background forest;
	forest.generate(BKG_IMG_NAME,NUM_BKG_FRAMES);

	int frame = 0;	//Current background frame

    //Keep window open until quit state is reached (ESC)
    while (!g.getQuit()){
    	forest.draw(g,frame);
    	g.update();
    		if(g.kbhit()){
    	    	g.getKey();
    		}
    	g.Sleep(100);
    	//Increment current frame number and keep within valid range
    	frame++;
    	frame %= NUM_BKG_FRAMES;
    }
    return 0;
}
