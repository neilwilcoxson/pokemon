#ifndef POKEBALL_H_INCLUDED
#define POKEBALL_H_INCLUDED

#include "SDL_Plotter.h"
#include <string>
#include <vector>
#include <fstream>

struct Pixels
{
    int R,G,B;
};

class Pokeball
{
    private:
        vector<vector<vector<Pixels> > >graphic;
        int dem1, dem2;
        string line;
        int frameD, colD, rowD;

    public:
        void generate(string, int);
        void draw(SDL_Plotter& g, int frame, int x, int y);
        void drawThrow(SDL_Plotter& g, int frame, int x, int y, int goX, int goY);
        void drawCatch(SDL_Plotter& g, int frame, int x, int y, int goX, int goY);
};

#endif // POKEBALL_H_INCLUDED
