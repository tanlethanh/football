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
    void setVel(int vel);
    void getDirs(int *x, int *y);
    void setDirs(int x, int y);
    bool isColliding;

private:
    SDL_Rect rect;
    SDL_Texture *texr;
    int dirX;
    int dirY;
    int vel;
};