/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
*/

#include "Background.h"

void Background::generate(string fileName){
	ifstream file(fileName.c_str());
	file >> frames >> row >> col;
	//Make vector reflect number of frames
	backgroundSequence.resize(frames);

	for(int frameNumber = 0; frameNumber < frames; frameNumber++){

		//Resize vector for row dimension
		backgroundSequence[frameNumber].resize(row);

		//Resize vector for column dimension
		for(int i = 0; i < row; i++){
			backgroundSequence[frameNumber][i].resize(col);
		}

		//read background data into vector
		for(int r = 0; r < row; r++){
			for(int c = 0; c < col; c++){
				file >> backgroundSequence[frameNumber][r][c].R
				>> backgroundSequence[frameNumber][r][c].G
				>> backgroundSequence[frameNumber][r][c].B;
			}
		}

		getline(file,temp);
	}
	file.close();
}

void Background::draw(SDL_Plotter& g, int frame){
	//For each row
	for(int r = 0; r < row; r++){
		//For each column
		for(int c = 0; c < col; c++){
			//Plot the pixel stored in backgroundSequence for frame requested
			g.plotPixel(c, r, backgroundSequence[frame][r][c].R,
							  backgroundSequence[frame][r][c].G,
							  backgroundSequence[frame][r][c].B);
		}
	}
	//draw function does not update the screen, must be called in driver
}
