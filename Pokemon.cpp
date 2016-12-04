
/*
 * Author: Natalie Glen
 * Assignment Title: PokemonGo (Group Project)
 * Assignment Description: A simple game inspired by the popular mobile game
 * Due Date: 12/5/2016
 * Date Created: 11/18/2016
 * Date Last Modified: 12/2/2016
 */
#include "Pokemon.h"
void Pokemon::generate(string filename){
    ifstream file;
    file.open(filename.c_str());

    file >> frames;


    for(int h = 0; h < frames; h++){
        file >> dem1 >> dem2;
        graphic.resize(frames, vector<vector<Pixels> >(dem1, vector<Pixels>(dem2)));
        for(int i = 0; i < dem1; i++){
            for(int j = 0; j < dem2; j++){
                file >> graphic[h][i][j].R >> graphic[h][i][j].G >> graphic[h][i][j].B;
            }
        }
        getline(file, line);
    }
    file.close();
    return;
}

void Pokemon::draw(SDL_Plotter& g, int fr, int x, int y){
    curX = x;
    curY = y;
    frame = fr;
    for(int rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(int colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){

            //This is to ensure we don't print the white background
            if(!(graphic[frame][rowD][colD].R >= 245 ||
                 graphic[frame][rowD][colD].G >= 245 ||
                 graphic[frame][rowD][colD].B >= 245)){

                    g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                       graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
            }
        }
    }
    g.update();
    return;
}

void Pokemon::erase(SDL_Plotter& g, Background bk, int frame, Battery bat){
    Pixel value;
    for(int y = curY; y < dem1 + curY /*&& curY + y < g.getRow() */; y++){
        for(int x = curX; x < dem2 + curX /*&& curX + x < g.getRow()*/; x++){
            value = bk.getColor(0, y, x);
            g.plotPixel(x, y, value.R, value.G, value.B);
        }
    }
    drawOverlays(g,bat);

    return;
}

void Pokemon::getLocation(int& x, int& y, int& width, int& height){
    x = curX;
    y = curY;
    width = dem2;
    height = dem1;
    return;
}

int Pokemon::getFrames(){
    return frames;
}
