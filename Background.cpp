/*
* Author: Neil Wilcoxson
* Assignment Title: PokemonGo (Group Project)
* Assignment Description: A simple game inspired by the popular mobile game
* Due Date: 12/5/2016
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
*/

#include "Background.h"

void Background::generate(string fileName, int numFrames){
	frames = numFrames;
	//Make vector reflect number of frames
	backgroundSequence.resize(frames);

	for(int fileNumber = 0; fileNumber < frames; fileNumber++){
		//Open the background file
		ifstream file((fileName+to_string(fileNumber)).c_str());
		if(!file){
			cout << "Background File Failed To Open" << endl;
		}
		else{
			//Read number of rows and columns from first two lines of file
			file >> row >> col;

			//Resize vector for row dimension
			backgroundSequence[fileNumber].resize(row);

			//Resize vector for column dimension
			for(int i = 0; i < row; i++){
				backgroundSequence[fileNumber][i].resize(col);
			}

			//read background data into vector
			for(int r = 0; r < row; r++){
				for(int c = 0; c < col; c++){
					file >> backgroundSequence[fileNumber][r][c].R
					>> backgroundSequence[fileNumber][r][c].G
					>> backgroundSequence[fileNumber][r][c].B;
				}
			}

			file.close();
		}
	}
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
	g.update();
}
