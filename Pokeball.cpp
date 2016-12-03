#include "Pokeball.h"
void Pokeball::generate(string filename, int frame){
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

void Pokeball::draw(SDL_Plotter& g, int frame, int x, int y){
    for(rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){

            //This is to ensure we don't print the white background
            if(!(graphic[frame][rowD][colD].R == 236 &&
                 graphic[frame][rowD][colD].G == 243 &&
                 graphic[frame][rowD][colD].B == 250)){

                    g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                       graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
            }
        }
    }
    return;
}

bool Pokeball::drawThrow(SDL_Plotter& g, int frame, int x, int y, int goX, int goY)
{
    bool caught = false;
    while(x != goY && y != goY)
    {
        int difx = 1;
        int dify = 1;
        if(x > goX)
        {
            difx = -1;
        }
        if(y < goY)
        {
            dify = -1;
        }
        x += difx;
        y += dify;
        for(rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
            for(colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){

                //This is to ensure we don't print the white background
                if(!(graphic[frame][rowD][colD].R == 236 &&
                     graphic[frame][rowD][colD].G == 243 &&
                     graphic[frame][rowD][colD].B == 250)){

                        g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                           graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
                }
            }
        }
    }

    /*
     *if(x - 100 <= pokemon.x && y - 100 <= pokemon.y)
     *{
     *   caught = true;
     *}
     */

    return caught;
}
