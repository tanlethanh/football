#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"

class Ball
{
public:
    Ball(std::string name, int x, int y, Alignment align);
    ~Ball();

    void update();
    void render();

private:
    SDL_Rect rect;
    SDL_Texture *texr;
    int x;
    int y;
};