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

void Score::drawScore(SDL_Plotter& g, int frame, int x, int y)
{

}
