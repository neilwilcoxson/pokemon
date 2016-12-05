#include "Pokeball.h"
#include "Pokemon.h"

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
            if(!(graphic[frame][rowD][colD].R == 236 ||
                 graphic[frame][rowD][colD].G == 243 ||
                 graphic[frame][rowD][colD].B == 250)){

                    g.plotPixel( x + colD, y + rowD, graphic[frame][rowD][colD].R,
                       graphic[frame][rowD][colD].G, graphic[frame][rowD][colD].B);
            }
        }
    }
    g.update();
    return;
}

void Pokeball::erase(SDL_Plotter& g, Background bk, int frame, Battery bat){
    Pixel value;
    for(int y = curY; y < dem1 + curY && curY + dem1 < g.getRow(); y++){
        for(int x = curX; x < dem2 + curX && curX + dem2 < g.getCol(); x++){
            value = bk.getColor(0, y, x);
            g.plotPixel(x, y, value.R, value.G, value.B);
        }
    }
    drawOverlays(g,bat);

    return;
}

int Pokeball::pokeballThrow(SDL_Plotter& g, Background bk, int frame,
                            Battery bat, int x, int y, int goX, int goY,
                            Pokemon a[], int length)
{
    int caught = -1;

    int difX = 1;
    int difY = 1;

    int pokeRow, pokeCol, pokeX, pokeY;

    curX = x;
    curY = y;

    while(curX != goX || curY != goY)
    {
        if(curX > goX)
        {
            difX = -1;
        }
        else if(curX < goX)
        {
            difX = 1;
        }
        else
        {
            difX = 0;
        }

        if(curY > goY)
        {
            difY = -1;
        }
        else if(curY < goY)
        {
            difY = 1;
        }
        else
        {
            difY = 0;
        }

        erase(g, bk, frame, bat);

        curX += difX;
        curY += difY;

        draw(g, frame, curX, curY);



        if(frame < getFrames() - 1)
        {
            frame++;
        }
        else
        {
            frame = 0;
        }
    }

    for(int c = 0; c < length; c++)
    {
        a[c].getLocation(pokeX, pokeY, pokeCol, pokeRow);

        for(int i = 0; i < 100; i++)
        {
            if(pokeX + (pokeCol / 2) == curX + i || pokeX + (pokeCol / 2) == curX - i)
            {
                for(int j = 0; j < 100; j++)
                {
                    if(pokeY + (pokeRow / 2) == curY + j || pokeY + (pokeRow / 2) == curY - j)
                    {
                        caught = c;
                        a[c].erase(g, bk, 0, bat);
                        g.update();
                    }
                }
            }
        }
    }

    return caught;
}

int Pokeball::getFrames(){
    return frames;
}
