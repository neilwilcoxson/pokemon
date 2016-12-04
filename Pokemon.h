//
//  Pokemon.h
//  SDL2
//
//  Created by Natalie Glen on 11/21/16.
//  Copyright © 2016 Natalie Glen. All rights reserved.
//

#ifndef Pokemon_h
#define Pokemon_h

#include "SDL_Plotter.h"
#include "Background.h"
#include "BatteryMeter.h"
#include "Overlays.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Pixels{
    int R,G,B;
};

class Pokemon{
    private:
    vector<vector<vector<Pixels> > >graphic;
    int dem1, dem2;
    string line;
    int frames;
    int curX, curY;

    public:
    void generate(string);
    void draw(SDL_Plotter& g, int frame, int x, int y);
    void erase(SDL_Plotter& g, Background bk, int frame, Battery bat);
    int getFrames();
    void getLocation(int& x, int& y);

};


#endif /* Pokemon_h */
