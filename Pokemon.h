
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
    //************************************************************
    // description: reads in the data from the file and stores   *
    //              each frame                                   *
    // return: none                                              *
    // precondition: The input file opens                        *
    // postcondition: The data is read in and stored             *
    //                                                           *
    //************************************************************
    void generate(string);
    //************************************************************
    // description: draws each frame of the pokemon to the screen*
    // return: none                                              *
    // precondition: The frames have already been generated      *
    // postcondition: The frames are drawn to the screen         *
    //                                                           *
    //************************************************************
    void draw(SDL_Plotter& g, int frame, int x, int y);
    //************************************************************
    // description: erases each frame of the pokemon from the    *
    //              screen                                       *
    // return: none                                              *
    // precondition: The frames have already been drawn to the   *
    //               screen                                      *
    // postcondition: The frames are erased from the screen      *
    //                                                           *
    //************************************************************
    void erase(SDL_Plotter& g, Background bk, int frame, Battery bat);
    //************************************************************
    // description: gets the number of frames from each pokemon  *
    //              sprite file                                  *
    // return: int                                               *
    // precondition: The file has already read in the number of  *
    //               frames                                      *
    // postcondition: returns number of frames                   *
    //                                                           *
    //************************************************************
    int getFrames();

};


#endif /* Pokemon_h */
