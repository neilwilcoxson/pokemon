#include "Pokeball.h"

void Pokeball::generate(string filename){
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

void Pokeball::draw(SDL_Plotter& g, int frame, int x, int y){
    curX = x;
    curY = y;
    for(int rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(int colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){

            //This is to ensure we don't print the white background
            if(!(graphic[frame][rowD][colD].R >= 236 &&
                 graphic[frame][rowD][colD].G >= 243 &&
                 graphic[frame][rowD][colD].B >= 250)){

                    g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                       graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
            }
        }
    }
    return;
}

void Pokeball::erase(SDL_Plotter& g, Background bk, int frame, Battery bat){
    for(int y = curY; y < dem1 && curY + y < g.getRow(); y++){
        for(int x = curX; x < dem2 && curX + x < g.getRow(); x++){
            g.plotPixel(x, y, bk.getColor(frame,y,x).R,
                              bk.getColor(frame,y,x).G,
                              bk.getColor(frame,y,x).B);
        }
    }
    drawOverlays(g,bat);
    return;
}

bool Pokeball::pokeballThrow(SDL_Plotter& g, Background bk, int frame, Battery bat, int x, int y, int goX, int goY)
{
    bool caught = false;

    int difX = 1;
    int difY = 1;

    while(x != goX && y != goY)
    {
        if(x > goX)
        {
            difX = -1;
        }
        else
        {
            difX = 1;
        }

        if(y > goX)
        {
            difY = -1;
        }
        else
        {
            difY = 1;
        }

        erase(g, bk, frame, bat);

        x += difX;
        y += difY;

        draw(g, frame, x, y);

    }
    /*
     *if(x - 100 <= pokemon.x && y - 100 <= pokemon.y)
     *{
     *    caught = true;
     *}
     */
    return caught;
}

int Pokeball::getFrames(){
    return frames;
}
