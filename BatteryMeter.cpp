/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
*/

#include "BatteryMeter.h"

Battery::Battery(){
    batteryLevel[2].R = 50;
    batteryLevel[2].G = 205;
    batteryLevel[2].B = 50;
    batteryLevel[1].R = 205;
    batteryLevel[1].G = 255;
    batteryLevel[1].B = 0;
    batteryLevel[0].R = 255;
    batteryLevel[0].G = 50;
    batteryLevel[0].B = 0;
}

void Battery::setBatteryLife(int seconds){
	timeBatStart = time(0);
	timeBatEnd = timeBatStart + seconds;
	totalTime = seconds;
}

void Battery::displayMeter(SDL_Plotter& g, int rowPos, int colPos){
	timeRemaining = timeBatEnd - time(0);
	batteryPercent = static_cast<double>(timeRemaining)/totalTime;

	//draw border of battery meter
	for(int borderRow = 0; borderRow < 32; borderRow++){
		//top border
		g.plotPixel(colPos + borderRow, rowPos, 254, 254, 254);
		//bottom border
		g.plotPixel(colPos + borderRow, rowPos + 16, 254, 254, 254);
	}
	for(int borderCol = 0; borderCol < 16; borderCol++){
		//left side
		g.plotPixel(colPos, rowPos + borderCol, 254,254,254);
		//right side
		g.plotPixel(colPos + 32, rowPos + borderCol, 254,254,254);
	}
	//extra on positive pole
	for(int extra = 0; extra < 8; extra++){
        g.plotPixel(colPos + 33, rowPos + 4 + extra, 254,254,254);
	}

	//inner battery fill
	if(batteryPercent >= .5){
        level = 2;
	}
	else if(batteryPercent >= .25){
        level = 1;
	}
	else{
        level = 0;
	}

	for(int r = 1; r < 15; r++){
		for(int c = 1; c < 31 * batteryPercent; c++){
                g.plotPixel(colPos + c, rowPos + r, batteryLevel[level].R,
                            batteryLevel[level].G, batteryLevel[level].B);
		}
	}
}
