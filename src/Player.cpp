#include "Player.h"
#include <SDL2_image/SDL_image.h>
#include "Game.h"

Player::Player(std::string path, int x, int y, Alignment initAlign)
{
    align = initAlign;
    texr = IMG_LoadTexture(Game::renderer, path.c_str());

    int w, h;
    // Query the width and height of the texture
    SDL_QueryTexture(texr, NULL, NULL, &w, &h);

    // Calculate scaled dimensions based on desired scale factor
    float scaleFactor = 0.3f; // Set the desired scale factor
    w = static_cast<int>(w * scaleFactor);
    h = static_cast<int>(h * scaleFactor);

    rect = getAlignRect(align, x, y, w, h);
    head.x = rect.x;
    head.y = rect.y;
    head.w = rect.w;
    head.h = rect.h / 5;
    std::cout << head.x << " " << head.y << " " << head.w << " " << head.h << std::endl;

    foot.x = rect.x;
    foot.y = rect.y + (2.0 * rect.h / 3);
    foot.w = rect.w;
    foot.h = rect.h / 5;
    std::cout << foot.x << " " << foot.y << " " << foot.w << " " << foot.h << std::endl;

    body.x = rect.x;
    body.y = rect.y + head.h;
    body.w = rect.w;
    body.h = rect.h - head.h - foot.h;
    std::cout << body.x << " " << body.y << " " << body.w << " " << body.h << std::endl;
}

Player::~Player()
{
}

SDL_Rect Player::getRect()
{
    return rect;
}

void Player::render()
{
    SDL_RenderCopy(Game::renderer, texr, NULL, &rect);
}

void Player::move(int stepX, int stepY)
{
    rect.x += stepX;
    rect.y += stepY;
}
