#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"

class Player
{
public:
    Player(std::string name, int x, int y, Alignment align);
    ~Player();

    void update();
    void render();

private:
    SDL_Rect rect;
    SDL_Texture *texr;
    int x;
    int y;
};