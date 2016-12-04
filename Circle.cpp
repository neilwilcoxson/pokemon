/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 12/3/2016
*/

#include "Circle.h"

void Circle::generate(string fileName){
    ifstream file(fileName.c_str());
    file >> frames >> height >> width;
    circle.resize(height,vector<Pixel>(width));


    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            file >> circle[i][j].R >>  circle[i][j].G >> circle[i][j].B;
        }
    }
}

void Circle::draw(SDL_Plotter& g, int row, int col){
    rowPos = row;
    colPos = col;
    for(int rowD = 0; rowD < height && row + rowD < g.getRow(); rowD++ ){
        for(int colD = 0; colD < width && col + colD < g.getCol(); colD++ ){

            //This is to ensure we don't print the white background
            if(!(circle[rowD][colD].R >= 254 &&
                 circle[rowD][colD].G >= 254 &&
                 circle[rowD][colD].B >= 254)){

                    g.plotPixel(col + colD, row + rowD, circle[rowD][colD].R,
                       circle[rowD][colD].G, circle[rowD][colD].B);
            }

        }
    }
    return;
}

void Circle::move(direction dir, SDL_Plotter& g){
    oldLoc = loc;
    switch(dir){
        case UP: loc.y -= 10;
                 break;
        case DOWN: loc.y += 10;
                 break;
        case LEFT: loc.x -= 10;
                 break;
        case RIGHT: loc.y += 10;
                 break;
    }
    draw(g, loc.x, loc.y);
}

void Circle::getPosition(int& row, int& col){
    row = rowPos;
    col = colPos;

    return;
}
