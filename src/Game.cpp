#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Ball.h"

SDL_Renderer *Game::renderer = nullptr;

Board *board = nullptr;
Player *player1 = nullptr;
Player *player2 = nullptr;
Ball *ball = nullptr;

Game::Game()
{
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

    board = new Board("assets/football_field.jpeg");
    player1 = new Player("assets/ronaldo.png", 0, height / 2, Alignment::LEFT_CENTER);
    player2 = new Player("assets/messi.png", width, height / 2, Alignment::RIGHT_CENTER);
    ball = new Ball("assets/ball.png", width / 2, height / 2, Alignment::CENTER_CENTER);
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

    board->render();
    player1->render();
    player2->render();
    ball->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}