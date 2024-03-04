#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"
#include <SDL2_ttf/SDL_ttf.h>

class Score
{
public:
    Score(int x, int y, std::string player1, std::string player2, Alignment initAlign);
    ~Score();

    SDL_Rect getRect();
    void addScoreToPlayer1(int score);
    void addScoreToPlayer2(int score);
    void update();
    void render();

    TTF_Font *font;
    SDL_Color color;

private:
    Alignment align;
    SDL_Rect rect;
    SDL_Texture *texr;
    int x;
    int y;
    int player1Score;
    int player2Score;
    std::string player1Name;
    std::string player2Name;
};