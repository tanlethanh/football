#include <string>
#include <SDL2/SDL_render.h>
#include "Alignment.h"

class Player
{
public:
    Player(std::string name, int x, int y, Alignment align);
    ~Player();

    SDL_Rect getRect();
    void update();
    void render();
    void move(int stepX, int stepY);

    SDL_Rect head;
    SDL_Rect body;
    SDL_Rect foot;

private:
    Alignment align;
    SDL_Rect rect;
    SDL_Texture *texr;
    int x;
    int y;
};