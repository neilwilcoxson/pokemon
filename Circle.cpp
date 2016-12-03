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
    file >> height >> width;
    vector<vector<Pixel> >circle(height,vector<Pixel>(width));

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            file >> circle[i][j].R >>  circle[i][j].G >> circle[i][j].B;
        }
    }
}

void Circle::draw(int row, int col){

}

void Circle::move(direction dir){

}
void Circle::getPosition(int& row, int& col){

}
