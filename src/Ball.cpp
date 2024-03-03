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

    dirX = -100 + rand() % (200 + 1);
    while (dirX == 0)
    {
        dirX = -100 + rand() % (200 + 1);
    }

    dirY = -100 + rand() % (200 + 1);
    while (dirY == 0)
    {
        dirY = -100 + rand() % (200 + 1);
    }
}

void Ball::update()
{
    double rel = sqrt(pow(dirX, 2) + pow(dirY, 2));
    rect.x += (vel * dirX * 1.0) / rel;
    rect.y += (vel * dirY * 1.0) / rel;
}

void Ball::render()
{
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}

SDL_Rect Ball::getRect()
{
    return rect;
}

void Ball::setVel(int newVel)
{
    vel = newVel;
}

void Ball::getDirs(int *x, int *y)
{
    *x = dirX;
    *y = dirY;
}

void Ball::setDirs(int x, int y)
{
    dirX = x;
    dirY = y;
}
