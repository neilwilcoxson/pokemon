//
//  Pokemon.cpp
//  SDL2
//
//  Created by Natalie Glen on 11/21/16.
//  Copyright © 2016 Natalie Glen. All rights reserved.
//

#include "Pokemon.h"
void Pokemon::generate(string filename, int frame){
    ifstream file;
    file.open(filename.c_str());
    
    file >> frame;

    
    for(int h = 0; h < frame; h++){
        file >> dem1 >> dem2;
        graphic.resize(frame, vector<vector<Pixels> >(dem1, vector<Pixels>(dem2)));
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

void Pokemon::draw(SDL_Plotter& g, int frame, int x, int y){
    for(rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){
            
            //This is to ensure we don't print the white background
            if(!(graphic[frame][rowD][colD].R >= 245 &&
                 graphic[frame][rowD][colD].G >= 245 &&
                 graphic[frame][rowD][colD].B >= 245)){
                
                    g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                       graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
            }
        }
    }
    return;
}

