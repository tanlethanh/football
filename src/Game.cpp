#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Ball.h"
#include "Collision.h"
#include "Score.h"

SDL_Renderer *Game::renderer = nullptr;

Board *board = nullptr;
Player *player1 = nullptr;
Player *player2 = nullptr;
Ball *ball = nullptr;
Score *score = nullptr;

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

    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }

    board = new Board("assets/football_field.jpeg");
    player1 = new Player("assets/ronaldo.png", 0, height / 2, Alignment::LEFT_CENTER);
    player2 = new Player("assets/messi.png", width, height / 2, Alignment::RIGHT_CENTER);
    ball = new Ball("assets/ball.png", width / 2, height / 2, 6, Alignment::CENTER_CENTER);
    score = new Score(width / 2 - 20, 80, "Ronaldo", "Messi", Alignment::CENTER_CENTER);
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_r:
            if (ball->getVel() == 0)
            {
                ball->reset();
            }
            break;
        case SDLK_a:
            player1->move(-10, 0);
            break;
        case SDLK_d:
            player1->move(10, 0);
            break;
        case SDLK_w:
            player1->move(0, -10);
            break;
        case SDLK_s:
            player1->move(0, 10);
            break;
        case SDLK_UP:
            player2->move(0, -10);
            break;
        case SDLK_DOWN:
            player2->move(0, 10);
            break;
        case SDLK_LEFT:
            player2->move(-10, 0);
            break;
        case SDLK_RIGHT:
            player2->move(10, 0);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Game::update()
{
    int ballDirX, ballDirY;
    ball->getDirs(&ballDirX, &ballDirY);

    if (Collision::check(board->getLeftLineRect(), ball->getRect()))
    {
        if (ball->getVel() != 0)
        {
            score->addScoreToPlayer2(1);
            ball->setVel(0);
        }
    }
    else if (Collision::check(board->getRightLineRect(), ball->getRect()))
    {
        if (ball->getVel() != 0)
        {
            score->addScoreToPlayer1(1);
            ball->setVel(0);
        }
    }
    else if (Collision::check(board->getTopLineRect(), ball->getRect()))
    {
        if (!ball->isColliding)
        {
            ball->setDirs(ballDirX, -ballDirY);
            ball->isColliding = true;
        }
    }
    else if (Collision::check(board->getBottomLineRect(), ball->getRect()))
    {
        if (!ball->isColliding)
        {
            ball->setDirs(ballDirX, -ballDirY);
            ball->isColliding = true;
        }
    }
    else if (Collision::check(player1->getRect(), ball->getRect()))
    {
        if (!ball->isColliding)
        {
            if (Collision::check(player1->head, ball->getRect()))
            {
                std::cout << "head 1" << std::endl;
                ball->setDirs(-ballDirX, ballDirY - 20);
            }
            else if (Collision::check(player1->body, ball->getRect()))
            {
                std::cout << "body 1" << std::endl;
                ball->setDirs(-ballDirX, ballDirY);
            }
            else if (Collision::check(player1->foot, ball->getRect()))
            {
                std::cout << "foot 1" << std::endl;
                ball->setDirs(-ballDirX, ballDirY + 20);
            }
            else
            {
                std::cout << "else 1" << std::endl;
                ball->setDirs(-ballDirX, ballDirY);
            }
            ball->isColliding = true;
        }
    }
    else if (Collision::check(player2->getRect(), ball->getRect()))
    {
        if (!ball->isColliding)
        {
            if (Collision::check(player2->head, ball->getRect()))
            {
                std::cout << "head 2" << std::endl;
                ball->setDirs(-ballDirX, ballDirY - 20);
            }
            else if (Collision::check(player2->body, ball->getRect()))
            {
                std::cout << "body 2" << std::endl;
                ball->setDirs(-ballDirX, ballDirY);
            }
            else if (Collision::check(player2->foot, ball->getRect()))
            {
                std::cout << "foot 2" << std::endl;
                ball->setDirs(-ballDirX, ballDirY + 20);
            }
            else
            {
                std::cout << "else 2" << std::endl;
                ball->setDirs(-ballDirX, ballDirY);
            }
            ball->isColliding = true;
        }
    }
    else
    {
        ball->isColliding = false;
    }

    ball->update();
    score->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    board->render();
    player1->render();
    player2->render();
    ball->render();
    score->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    TTF_CloseFont(score->font);

    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
}