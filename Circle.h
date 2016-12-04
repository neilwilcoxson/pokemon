/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 12/3/2016
*/

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <vector>
#include <string>
#include <fstream>
#include "SDL_Plotter.h"
#include "Background.h"

using namespace std;

struct Point{
    int x, y;
};

enum direction {UP,DOWN,LEFT,RIGHT};

class Circle{
	private:
		int rowPos, colPos, height, width, frames;
		Point oldLoc, center;
		vector<vector<Pixel> >circle;
	public:
	    Circle();
	    Point loc;
	    void generate(string fileName);
		void draw(SDL_Plotter& g, int row, int col);
		void move(direction dir, SDL_Plotter&);
		void getPosition(int& row, int& col);
		Point getLoc();
};



#endif /* CIRCLE_H_ */
