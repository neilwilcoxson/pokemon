#include "Overlays.h"

void drawOverlays(SDL_Plotter& g, Battery b){
    int row,col;
    b.getPosition(row,col);
    b.displayMeter(g,row,col);
}
