#pragma once

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>
#include <vector>

class AssetManager;
class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();

    void init(const char *title, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();

    static SDL_Renderer *renderer;

private:
    SDL_Event event;
    bool isRunning;
    SDL_Window *window;
};