#include "Player.h"
#include <SDL2_image/SDL_image.h>
#include "Game.h"

Player::Player(std::string path, int x, int y, Alignment align)
{
    texr = IMG_LoadTexture(Game::renderer, path.c_str());

    int w, h;
    // Query the width and height of the texture
    SDL_QueryTexture(texr, NULL, NULL, &w, &h);

    // Calculate scaled dimensions based on desired scale factor
    float scaleFactor = 0.3f; // Set the desired scale factor
    w = static_cast<int>(w * scaleFactor);
    h = static_cast<int>(h * scaleFactor);

    rect = getAlignRect(align, x, y, w, h);
}

Player::~Player()
{
}

void Player::render()
{
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}
