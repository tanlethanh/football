#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"

class Ball
{
public:
    Ball(std::string name, int initX, int initY, int initVel, Alignment align);
    ~Ball();

    void update();
    void reset();
    void render();
    SDL_Rect getRect();
    int getVel();
    void setVel(int vel);
    void getDirs(int *x, int *y);
    void setDirs(int x, int y);
    bool isColliding;

private:
    SDL_Rect rect;
    SDL_Texture *texr;
    int x;
    int y;
    int dirX;
    int dirY;
    int vel;
    int dVel;
    Alignment align;
};