#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"

class Ball
{
public:
    Ball(std::string name, int x, int y, int initVel, Alignment align);
    ~Ball();

    void update();
    void render();
    SDL_Rect getRect();

private:
    SDL_Rect rect;
    SDL_Texture *texr;
    int dirX;
    int dirY;
    int vel;
};