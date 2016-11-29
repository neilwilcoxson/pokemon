/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "SDL_Plotter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Pixel{
	int R,G,B;
};

class Background{
	private:
	vector<vector<vector<Pixel> > > backgroundSequence;
	int frames, row, col;
	string temp;

	public:
	/*
	 * description: initializes background and loads files
	 * return: void
	 * precondition: background file exists
	 * postcondition: background is loaded to vector
	 */
	void generate(string fileName);

	/*
	 * description: draws the background to the buffer
	 * return: void
	 * precondition: plotter exists
	 * postcondition: background is drawn to the buffer
	 */
	void draw(SDL_Plotter& g, int frame);
};



#endif /* BACKGROUNDDRAW_H_ */
