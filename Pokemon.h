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
    int frameD, colD, rowD;
    
    public:
    void generate(string, int);
    void draw(SDL_Plotter& g, int frame, int x, int y);
    
};


#endif /* Pokemon_h */
