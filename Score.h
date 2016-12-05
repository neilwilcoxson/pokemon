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
        string line;
        vector<vector<vector<Pixels > > > digits;

    public:
        Score();
        void setScore(int caught);
        int getScore();
        void drawScore(SDL_Plotter& g, int frame, int x, int y);
};

#endif // SCORE_H_INCLUDED
