#include "Board.h"
#include <SDL2_image/SDL_image.h>
#include "Game.h"

Board::Board(std::string path)

{
    texr = IMG_LoadTexture(Game::renderer, path.c_str());
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
