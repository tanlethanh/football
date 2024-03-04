#include "Score.h"
#include <SDL2_ttf/SDL_ttf.h>
#include "Game.h"

Score::Score(int initX, int initY, std::string player1, std::string player2, Alignment initAlign)
{
    align = initAlign;
    x = initX;
    y = initY;

    player1Name = player1;
    player2Name = player2;
    player1Score = 0;
    player2Score = 0;

    font = TTF_OpenFont("assets/MadimiOne-Regular.ttf", 40);
    color = {255, 255, 255};
}

Score::~Score()
{
}

SDL_Rect Score::getRect()
{
    return SDL_Rect();
}

void Score::addScoreToPlayer1(int score)
{
    player1Score += score;
}

void Score::addScoreToPlayer2(int score)
{
    player2Score += score;
}

void Score::update()
{
    std::string score = player1Name + " " + std::to_string(player1Score) + " - " + std::to_string(player2Score) + " " + player2Name;
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, score.c_str(), color);
    if (surfaceMessage == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }

    texr = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
    rect = getAlignRect(align, x, y, surfaceMessage->w, surfaceMessage->h);
}

void Score::render()
{
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}
