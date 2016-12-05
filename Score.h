#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include "SDL_Plotter.h"
#include "Background.h"
#include "BatteryMeter.h"
#include "Overlays.h"
#include "Pokemon.h"
#include <string>
#include <vector>
#include <fstream>

class Score
{
    private:
        int score;
        int frames;
        int dem1, dem2;
        int curX, curY;
        string line;
        vector<vector<vector<Pixels > > > digits;

    public:
        Score();

        /*
         * description: sets the score based on number of pokemon caught
         * return: void
         * precondition: integer parameter exists
         * postcondition: sets score equal to parameter in Score object
         */
        void setScore(int caught);

        /*
         * description: gets the score
         * return: int
         * precondition: score integer exists
         * postcondition: returns score from Score object
         */
        int getScore();

        /*
         * description: draws the score to the plotter
         * return: void
         * precondition: the plotter and integer parameters exist
         * postcondition: draws the score to the plotter
         */
        void drawScore(SDL_Plotter& g, int x, int y);
};

#endif // SCORE_H_INCLUDED
