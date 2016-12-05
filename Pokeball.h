/*
* Author: Weston Straw
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 12/2/2016
*/

//.h to create the pokeball and throw it

#ifndef POKEBALL_H_INCLUDED
#define POKEBALL_H_INCLUDED

#include "SDL_Plotter.h"
#include "Background.h"
#include "BatteryMeter.h"
#include "Overlays.h"
#include "Pokemon.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Pokeball{
    private:
        vector<vector<vector<Pixels> > >graphic;
        int dem1, dem2;
        string line;
        int frames;
        int curX, curY;

    public:
        void generate(string);

        /*
         * description: draws the pokeball to the plotter
         * return: void
         * precondition: the plotter and integer parameters exist
         * postcondition: draws the pokeball to the plotter at the inputed
         *                frame
         */
        void draw(SDL_Plotter& g, int frame, int x, int y);

        /*
         * description: erases the pokeball from the plotter
         * return: void
         * precondition: plotter, background, integer, and battery parameters
         *               exist
         * postcondition: erases the pokeball from the plotter
         */
        void erase(SDL_Plotter& g, Background bk, int frame, Battery bat);

        /*
         * description: throws the pokeball to a position using draw and erase
         *              and finds position of pokemon in read in Pokemon array
         *              if it is caught
         * return: int
         * precondition: plotter, background, integers, battery and array of
         *               Pokemon exist
         * postcondition: draws a pokeball being thrown to a position on
         *                plotter
         */
        int pokeballThrow(SDL_Plotter& g, Background bk, int frame,
                          Battery bat, int x, int y, int goX, int goY,
                          Pokemon a[], int length);

        /*
         * description: gets the number of frames of the pokeball
         * return: int
         * precondition: frames variable exists
         * postcondition: returns frames from pokeball object
         */
        int getFrames();

};

#endif // POKEBALL_H_INCLUDED
