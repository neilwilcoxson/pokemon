/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
*/

#ifndef BATTERYMETER_H_
#define BATTERYMETER_H_

#include <ctime>
#include "SDL_Plotter.h"

using namespace std;

struct Color{
    int R,G,B;
};

class Battery{
	private:
	int timeBatStart, timeBatEnd;
	int totalTime, timeRemaining;
	int level = 2;
	double batteryPercent;
	Color batteryLevel[3];

	public:
    Battery();
	/*
	 * description: sets the amount of time for which the battery will last
	 * return: void
	 * precondition: integer for number of seconds
	 * postcondition: battery timing configured
	 */
	void setBatteryLife(int seconds);
	/*
	 * description: sets the amount of time for which the battery will last
	 * return: void
	 * precondition: row and column position
	 * postcondition: battery meter is drawn to the buffer
	 */
	void displayMeter(SDL_Plotter& g, int rowPos, int colPos);
};



#endif /* BATTERYMETER_H_ */
