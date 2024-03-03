#include "Ball.h"
#include <SDL2_image/SDL_image.h>
#include "Game.h"

Ball::Ball(std::string path, int x, int y, int initVel, Alignment align)
{
    vel = initVel;
    texr = IMG_LoadTexture(Game::renderer, path.c_str());

    int w, h;
    // Query the width and height of the texture
    SDL_QueryTexture(texr, NULL, NULL, &w, &h);

    // Calculate scaled dimensions based on desired scale factor
    float scaleFactor = 0.3f;
    w = static_cast<int>(w * scaleFactor);
    h = static_cast<int>(h * scaleFactor);

    rect = getAlignRect(align, x, y, w, h);

    dirX = rand() % 11 - 5;
    while (dirX == 0)
    {
        dirX = rand() % 11 - 5;
    }

    dirY = rand() % 11 - 5;
    while (dirY == 0)
    {
        dirY = rand() % 11 - 5;
    }
}

void Ball::update()
{
    rect.x += (vel * 1.0) * (dirX * 1.0 / abs(dirY));
    rect.y += (vel * 1.0) * (dirY * 1.0 / abs(dirX));
}

void Ball::render()
{
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}

SDL_Rect Ball::getRect()
{
    return rect;
}
