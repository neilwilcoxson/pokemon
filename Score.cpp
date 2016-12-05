#include "Score.h"

Score::Score()
{
    ifstream file;
    file.open("digits");

    file >> frames;


    for(int h = 0; h < frames; h++){
        file >> dem1 >> dem2;
        digits.resize(frames, vector<vector<Pixels> >(dem1, vector<Pixels>(dem2)));
        for(int i = 0; i < dem1; i++){
            for(int j = 0; j < dem2; j++){
                file >> digits[h][i][j].R >> digits[h][i][j].G >> digits[h][i][j].B;
            }
        }
        getline(file, line);
    }
    file.close();

    score = 5;

    return;
}

void Score::setScore(int caught)
{
    score = caught;
}

int Score::getScore()
{
    return score;
}

void Score::drawScore(SDL_Plotter& g, int x, int y)
{
    curX = x;
    curY = y;
    int ones = score % 10;

    for(int rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(int colD = 0; colD < dem2 && x + colD < g.getCol(); colD++ ){
            g.plotPixel( x + colD, y + rowD, digits[score / 10][rowD][colD].R,
                digits[score / 10][rowD][colD].G, digits[score / 10][rowD][colD].B);
        }
    }

    for(int rowD = 0; rowD < dem1 && y + rowD < g.getRow(); rowD++ ){
        for(int colD = 0; colD < dem2 && x + 68 + colD < g.getCol(); colD++ ){
            g.plotPixel( x + 68 + colD, y + rowD, digits[ones][rowD][colD].R,
                digits[ones][rowD][colD].G, digits[ones][rowD][colD].B);
        }
    }

    return;
}
