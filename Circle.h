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

using namespace std;

struct Pixel{
    int R,G,B;
};

enum direction {UP,DOWN,LEFT,RIGHT};

class Circle{
	private:
		int rowPos, colPos, height, width;
	public:
	    void generate(string fileName);
		void draw(int row, int col);
		void move(direction dir)
		void getPosition(int& row, int& col);
};



#endif /* CIRCLE_H_ */
