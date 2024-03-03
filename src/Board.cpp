#include "Board.h"
#include <SDL2_image/SDL_image.h>
#include "Game.h"

Board::Board(std::string path)

{
    texr = IMG_LoadTexture(Game::renderer, path.c_str());
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texr, NULL, NULL, &rect.w, &rect.h); // Query the width and height of the texture

    leftLineRect.x = 0;
    leftLineRect.y = 0;
    leftLineRect.h = rect.h;
    leftLineRect.w = 1;

    rightLineRect.x = rect.w - 1;
    rightLineRect.y = 0;
    rightLineRect.h = rect.h;
    rightLineRect.w = 1;

    topLineRect.x = 0;
    topLineRect.y = 0;
    topLineRect.h = 1;
    topLineRect.w = rect.w;

    bottomLineRect.x = 0;
    bottomLineRect.y = rect.h - 1;
    bottomLineRect.h = 1;
    bottomLineRect.w = rect.w;
}

Board::~Board()
{
}

void Board::update()
{
}

void Board::render()
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texr, NULL, NULL, &rect.w, &rect.h); // Query the width and height of the texture
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}

SDL_Rect Board::getLeftLineRect()
{
    return leftLineRect;
}

SDL_Rect Board::getRightLineRect()
{
    return rightLineRect;
}

SDL_Rect Board::getTopLineRect()
{
    return topLineRect;
}

SDL_Rect Board::getBottomLineRect()
{
    return bottomLineRect;
}
