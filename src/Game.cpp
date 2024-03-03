#include "Game.h"
#include <sstream>

SDL_Texture *bgTexr = nullptr;

Game::Game()
{
    renderer = nullptr;
    isRunning = false;
}

Game::~Game() {}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    bgTexr = IMG_LoadTexture(renderer, "assets/football_field.jpeg");
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    // update the game state
}

void Game::render()
{
    SDL_RenderClear(renderer);

    // handle render all the objects
    // Assuming there is a texture for the background already loaded called backgroundTexture
    SDL_Rect texr;
    texr.x = 0;
    texr.y = 0;
    SDL_QueryTexture(bgTexr, NULL, NULL, &texr.w, &texr.h); // Query the width and height of the texture
    SDL_RenderCopy(renderer, bgTexr, NULL, &texr);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}